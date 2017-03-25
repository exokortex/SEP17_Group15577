//------------------------------------------------------------------------------
// EnvironmentalCondition.cpp
//
// Group: Group 15577, study assistant Roman Walch
//
// Authors: Johannes Haring 1611655
//          Thomas Moder 1615103
//          Verena Buder 1312723
//------------------------------------------------------------------------------
//

#include "EnvironmentalCondition.h"

using namespace std;

EnvironmentalCondition::EnvironmentalCondition(Cover sky_cover,
    Rank precipitation, float temperature, Rank wind)
{
  this->sky_cover_ = sky_cover;
  this->precipitation_ = precipitation;
  this->temperature_ = temperature;
  this->wind_ = wind;
}

bool EnvironmentalCondition::isItHot()
{
  return sky_cover_ == SUNNY && temperature_ >= TEMP_UPPERTHIRD;
}

bool EnvironmentalCondition::isItRainy()
{
  return (precipitation_ == MEDIUM || precipitation_ == HIGH)
      && (sky_cover_ == OVERCAST || sky_cover_ == VERY_OVERCAST);
}

bool EnvironmentalCondition::isItStormy()
{
  return (wind_ == MEDIUM || wind_ == HIGH)
      && (sky_cover_ == OVERCAST || sky_cover_ == VERY_OVERCAST);
}
