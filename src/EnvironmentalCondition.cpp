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

EnvironmentalCondition::EnvironmentalCondition(int sky_cover, int precipitation, float temperature, int wind)
{
  enum sky_cover: int
  {
    SUNNY, CLOUDY, OVERCAST, VERY_OVERCAST
  };
  enum precipitation: int
  {
    NONE, LOW, MEDIUM, HIGH
  };
  enum wind: int
  {
    NONE, LOW, MEDIUM, HIGH
  };


  //Methoden
  void EnvironmentalCondition::isltHot(int sky_cover, int temperature)


  void EnvironmentalCondition::isltRainy(int precipitation, int sky_cover)


  void EnvironmentalCondition::isltStormy(int wind, int sky_cover)




  public:
    //Setters
    void setSkyCover(int cover)
    {
      sky_cover = cover;
    }
    void setPrecipitation(int rank)
    {
      precipitation = rank;
    }
    void setTemperature(float temperature)
    {
      temperature = temperature;
    }
    void setWind(int rank)
    {
      wind = rank;
    }

    //Getters
    int getSkyCover() const
    {
      return void;
    }
    int getPrecipitation() const
    {
      return void;
    }
    int getTemperature() const
    {
      return void;
    }
    int getWind() const
    {
      return void;
    }

  private:
    int sky_cover;
    int precipitation;
	int temperature;
	int wind;

}

