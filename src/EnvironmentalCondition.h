//------------------------------------------------------------------------------
// EnvironmentalCondition.h
//
// Group: Group 15577, study assistant Roman Walch
//
// Authors: Johannes Haring 1611655
//          Thomas Moder 1615103
//          Verena Buder 1312723
//------------------------------------------------------------------------------
//

#ifndef ENVIRONMENTALCONDITION_H_INCLUDED
#define ENVIRONMENTALCONDITION_H_INCLUDED

class EnvironmentalCondition
{
  public:
    static const int TEMP_MIN = 10;
    static const int TEMP_MAX = 35;
    static const int TEMP_UPPERTHIRD = (TEMP_MAX - TEMP_MIN) / 3. * 2. + TEMP_MIN;

    enum Cover
    {
      SUNNY, CLOUDY, OVERCAST, VERY_OVERCAST
    };
    enum Rank
    {
      NONE, LOW, MEDIUM, HIGH
    };

    // Methods
    EnvironmentalCondition(Cover sky_cover, Rank precipitation,
        float temperature, Rank wind);

    bool isItHot();
    bool isItRainy();
    bool isItStormy();

    // Setters
    void setSkyCover(Cover cover)
    {
      sky_cover_ = cover;
    }
    void setPrecipitation(Rank rank)
    {
      precipitation_ = rank;
    }
    void setTemperature(float temperature)
    {
      temperature_ = temperature;
    }
    void setWind(Rank rank)
    {
      wind_ = rank;
    }

    // Getters
    Cover getSkyCover() const
    {
      return sky_cover_;
    }
    Rank getPrecipitation() const
    {
      return precipitation_;
    }
    float getTemperature() const
    {
      return temperature_;
    }
    Rank getWind() const
    {
      return wind_;
    }

  private:
    Cover sky_cover_;
    Rank precipitation_;
    float temperature_;
    Rank wind_;
};

#endif /* ENVIRONMENTALCONDITION_H_INCLUDED */
