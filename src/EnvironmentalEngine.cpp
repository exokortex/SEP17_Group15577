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
std::unique_ptr<EnvironmentalCondition> EnvironmentalEngine::createCondition()
{
  // Generate and return random condition
  EnvironmentalCondition::Cover sky_cover = EnvironmentalCondition::Cover(
      rand() % EnvironmentalCondition::COVER_SIZE);

  EnvironmentalCondition::Rank precipit = EnvironmentalCondition::Rank(
      rand() % EnvironmentalCondition::RANK_SIZE);

  float temperature = static_cast<float>(rand()
      % static_cast<int>(
          EnvironmentalCondition::TEMP_MAX * TEMP_DECIMAL_PRECISION
          - EnvironmentalCondition::TEMP_MIN * TEMP_DECIMAL_PRECISION + 1)
      + EnvironmentalCondition::TEMP_MIN * TEMP_DECIMAL_PRECISION)
          / TEMP_DECIMAL_PRECISION;

  EnvironmentalCondition::Rank wind = EnvironmentalCondition::Rank(
      rand() % EnvironmentalCondition::RANK_SIZE);

  std::unique_ptr<EnvironmentalCondition> condition(
      new EnvironmentalCondition(sky_cover, precipit, temperature, wind));

  return condition;
}

//------------------------------------------------------------------------------
std::unique_ptr<EnvironmentalCondition> EnvironmentalEngine::createCondition(
    EnvironmentalCondition& previous_condition)
{
  // Generate and return random condition based on current min and max ranges
  std::unique_ptr<EnvironmentalCondition> minima
    = getConditionMin(previous_condition);
  std::unique_ptr<EnvironmentalCondition> maxima
    = getConditionMax(previous_condition);

  EnvironmentalCondition::Cover sky_cover = EnvironmentalCondition::Cover(
      rand() % (maxima->getSkyCover() - minima->getSkyCover() + 1)
      + minima->getSkyCover());

  EnvironmentalCondition::Rank precipit = EnvironmentalCondition::Rank(
      rand() % (maxima->getPrecipitation() - minima->getPrecipitation() + 1)
      + minima->getPrecipitation());

  float temperature = static_cast<float>(rand()
      % static_cast<int>(maxima->getTemperature() * TEMP_DECIMAL_PRECISION
          - minima->getTemperature() * TEMP_DECIMAL_PRECISION + 1)
      + minima->getTemperature() * TEMP_DECIMAL_PRECISION)
          / TEMP_DECIMAL_PRECISION;

  EnvironmentalCondition::Rank wind = EnvironmentalCondition::Rank(rand() %
      (maxima->getWind() - minima->getWind() + 1) + minima->getWind());

  std::unique_ptr<EnvironmentalCondition> condition(
      new EnvironmentalCondition(sky_cover, precipit, temperature, wind));

  return condition;
}

//------------------------------------------------------------------------------
std::unique_ptr<EnvironmentalCondition> EnvironmentalEngine::getConditionMin(
    EnvironmentalCondition& previous_condition)
{
  EnvironmentalCondition::Cover sky_cover = previous_condition.getSkyCover();
  sky_cover = EnvironmentalCondition::Cover(std::max(0, sky_cover - 1));

  EnvironmentalCondition::Rank precipitation
    = previous_condition.getPrecipitation();
  precipitation = EnvironmentalCondition::Rank(std::max(0, precipitation - 1));

  float temperature = previous_condition.getTemperature();
  temperature = std::max(static_cast<float>(
      EnvironmentalCondition::TEMP_MIN), temperature - 5);

  EnvironmentalCondition::Rank wind = previous_condition.getWind();
  wind = EnvironmentalCondition::Rank(std::max(0, wind - 1));

  std::unique_ptr<EnvironmentalCondition> condition(
      new EnvironmentalCondition(sky_cover, precipitation, temperature, wind));

  return condition;
}

//------------------------------------------------------------------------------
std::unique_ptr<EnvironmentalCondition> EnvironmentalEngine::getConditionMax(
    EnvironmentalCondition& previous_condition)
{
  EnvironmentalCondition::Cover sky_cover
    = previous_condition.getSkyCover();
  sky_cover = EnvironmentalCondition::Cover(
      std::min(sky_cover + 1, EnvironmentalCondition::COVER_SIZE));

  EnvironmentalCondition::Rank precipit
    = previous_condition.getPrecipitation();
  precipit = EnvironmentalCondition::Rank(
      std::min(precipit + 1, EnvironmentalCondition::RANK_SIZE));

  float temperature = previous_condition.getTemperature();
  temperature = std::min(static_cast<float>(
      EnvironmentalCondition::TEMP_MAX), temperature + 5);

  EnvironmentalCondition::Rank wind = previous_condition.getWind();
  wind = EnvironmentalCondition::Rank(
      std::min(wind + 1, EnvironmentalCondition::RANK_SIZE));

  std::unique_ptr<EnvironmentalCondition> condition(
      new EnvironmentalCondition(sky_cover, precipit, temperature, wind));

  return condition;
}
