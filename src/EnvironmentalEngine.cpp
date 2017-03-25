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
  // TODO Auto-generated constructor stub
}

EnvironmentalCondition EnvironmentalEngine::createCondition()
{
  // Initialize random seed
  srand (time(NULL));

  // Generate and return random condition
  return EnvironmentalCondition(EnvironmentalCondition::Cover(rand() % 4),
                                EnvironmentalCondition::Rank(rand() % 3),
                                (float) (rand() % (350 - 100) + 100) / 10,
                                EnvironmentalCondition::Rank(rand() % 3));
}
