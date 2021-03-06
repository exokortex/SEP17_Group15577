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

#include <algorithm>

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
bool EnvironmentalCondition::isItHot()
{
  return sky_cover_ == SUNNY && temperature_ >= TEMP_UPPERTHIRD;
}

//------------------------------------------------------------------------------
bool EnvironmentalCondition::isItCold()
{
  return temperature_ <= TEMP_LOWERTHIRD;
}

//------------------------------------------------------------------------------
bool EnvironmentalCondition::isItRainy()
{
  return (precipitation_ == MEDIUM || precipitation_ == HIGH)
      && (sky_cover_ == OVERCAST || sky_cover_ == VERY_OVERCAST);
}

//------------------------------------------------------------------------------
bool EnvironmentalCondition::isItStormy()
{
  return (wind_ == MEDIUM || wind_ == HIGH)
      && (sky_cover_ == OVERCAST || sky_cover_ == VERY_OVERCAST);
}

//------------------------------------------------------------------------------
string EnvironmentalCondition::getSkyCoverString()
{
  switch (sky_cover_) {
    case EnvironmentalCondition::VERY_OVERCAST:
      return "very overcast";
    case EnvironmentalCondition::OVERCAST:
      return "overcast";
    case EnvironmentalCondition::CLOUDY:
      return "cloudy";
    case EnvironmentalCondition::SUNNY:
      return "sunny";
  }
  return "";
}

//------------------------------------------------------------------------------
string EnvironmentalCondition::getSkyCoverStringUpper()
{
  string text = getSkyCoverString();
  transform(text.begin(), text.end(), text.begin(), ::toupper);
  return text;
}

//------------------------------------------------------------------------------
string EnvironmentalCondition::getWindString()
{
  return rankToString(wind_);
}

//------------------------------------------------------------------------------
string EnvironmentalCondition::getWindStringUpper()
{
  string text = getWindString();
  transform(text.begin(), text.end(), text.begin(), ::toupper);
  return text;
}

//------------------------------------------------------------------------------
string EnvironmentalCondition::getPrecipitationString()
{
  return rankToString(precipitation_);
}

//------------------------------------------------------------------------------
string EnvironmentalCondition::getPrecipitationStringUpper()
{
  string text = getPrecipitationString();
  transform(text.begin(), text.end(), text.begin(), ::toupper);
  return text;
}

//------------------------------------------------------------------------------
string EnvironmentalCondition::rankToString(Rank rank)
{
  switch (rank) {
    case EnvironmentalCondition::NONE:
      return "none";
    case EnvironmentalCondition::LOW:
      return "low";
    case EnvironmentalCondition::MEDIUM:
      return "medium";
    case EnvironmentalCondition::HIGH:
      return "high";
  }
  return "";
}
