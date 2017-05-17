//------------------------------------------------------------------------------
// EnvironmentalEngine.cpp
//
// Group: Group 15577, study assistant Roman Walch
//
// Authors: Johannes Haring 1611655
//          Thomas Moder 1615103
//          Verena Buder 1312723
//------------------------------------------------------------------------------
//

#include <stdlib.h>
#include <time.h>

#include "EnvironmentalEngine.h"
#include "EnvironmentalCondition.h"

//------------------------------------------------------------------------------
EnvironmentalEngine::EnvironmentalEngine()
{
  // Initialize random seed
  srand(time(NULL));
}

//------------------------------------------------------------------------------
std::unique_ptr<EnvironmentalCondition> EnvironmentalEngine::createCondition(
    EnvironmentalCondition& previous_condition)
{
  // Generate and return random condition
  int generator_min;
  int generator_max;

  EnvironmentalCondition::Cover sky_cover = previous_condition.getSkyCover();
  generator_min = std::max(0, sky_cover - 1);
  generator_max = std::min(sky_cover + 1, EnvironmentalCondition::COVER_SIZE);
  sky_cover = EnvironmentalCondition::Cover(rand() %
      (generator_max - generator_min + 1) + generator_min);

  EnvironmentalCondition::Rank precipit
    = previous_condition.getPrecipitation();
  generator_min = std::max(0, precipit - 1);
  generator_max = std::min(precipit + 1, EnvironmentalCondition::RANK_SIZE);
  precipit = EnvironmentalCondition::Rank(rand() %
      (generator_max - generator_min + 1) + generator_min);

  float temperature = previous_condition.getTemperature();
  float temp_max = std::min(static_cast<float>(
        EnvironmentalCondition::TEMP_MAX), temperature + 5);
  float temp_min = std::max(static_cast<float>(
        EnvironmentalCondition::TEMP_MIN), temperature - 5);
  temperature = static_cast<float>(rand()
      % static_cast<int>(temp_max * TEMP_DECIMAL_PRECISION
          - temp_min * TEMP_DECIMAL_PRECISION + 1)
      + temp_min * TEMP_DECIMAL_PRECISION) / TEMP_DECIMAL_PRECISION;

  EnvironmentalCondition::Rank wind = previous_condition.getWind();
    generator_min = std::max(0, wind - 1);
    generator_max = std::min(wind + 1, EnvironmentalCondition::RANK_SIZE);
    wind = EnvironmentalCondition::Rank(rand() %
        (generator_max - generator_min + 1) + generator_min);

  std::unique_ptr<EnvironmentalCondition> condition(
      new EnvironmentalCondition(sky_cover, precipit, temperature, wind));

  return condition;
}
