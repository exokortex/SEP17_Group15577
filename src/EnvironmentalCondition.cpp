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

//------------------------------------------------------------------------------
EnvironmentalCondition::EnvironmentalCondition(Cover sky_cover,
    Rank precipitation, float temperature, Rank wind)
{
  this->sky_cover_ = sky_cover;
  this->precipitation_ = precipitation;
  this->temperature_ = temperature;
  this->wind_ = wind;
}

//------------------------------------------------------------------------------
//methods with boolean value as return value (=true or false)
//isItHot returns true if sky_cover is sunny and temperature is in the upper area
//
bool EnvironmentalCondition::isItHot()
{
  return sky_cover_ == SUNNY && temperature_ >= TEMP_UPPERTHIRD;
}

//------------------------------------------------------------------------------
// isItRainy returns true if precipitation is medium or
// high and sky_cover is overcast or very overcast
//
bool EnvironmentalCondition::isItRainy()
{
  return (precipitation_ == MEDIUM || precipitation_ == HIGH)
      && (sky_cover_ == OVERCAST || sky_cover_ == VERY_OVERCAST);
}

//------------------------------------------------------------------------------
// isItStormy returns true if wind is medium or
// high and sky_cover is overcast or very overcast
//
bool EnvironmentalCondition::isItStormy()
{
  return (wind_ == MEDIUM || wind_ == HIGH)
      && (sky_cover_ == OVERCAST || sky_cover_ == VERY_OVERCAST);
}
