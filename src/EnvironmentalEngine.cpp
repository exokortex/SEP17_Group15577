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

EnvironmentalEngine::EnvironmentalEngine()
{
  // Initialize random seed
  srand(time(NULL));
}

EnvironmentalCondition EnvironmentalEngine::createCondition()
{
  // Generate and return random condition
  return EnvironmentalCondition(EnvironmentalCondition::Cover(rand() % EnvironmentalCondition::COVER_SIZE),
                                EnvironmentalCondition::Rank(rand() % EnvironmentalCondition::RANK_SIZE),
                                static_cast<float>(rand() % (EnvironmentalCondition::TEMP_MAX * TEMP_DECIMAL_PRECISION
                                    - EnvironmentalCondition::TEMP_MIN * TEMP_DECIMAL_PRECISION + 1)
                                    + EnvironmentalCondition::TEMP_MIN * TEMP_DECIMAL_PRECISION) / TEMP_DECIMAL_PRECISION,
                                EnvironmentalCondition::Rank(rand() % EnvironmentalCondition::RANK_SIZE));
}
