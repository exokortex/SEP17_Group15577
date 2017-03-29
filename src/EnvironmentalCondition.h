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

//------------------------------------------------------------------------------
// class EnvironmentalCondition
// implements the constructor, methods, setters and getters
//
class EnvironmentalCondition
{
  public:
    //------------------------------------------------------------------------
    // Constructor
    // constructs the definition for temperature
	// @TEMP_MIN the temperature is <= 10
	// @TEMP_MAX the temperature is >= 35
	// @TEMP_UPPERTHIRD is in the upper one-third
	// @enum is an enumeration type
	//
	static const int TEMP_MIN = 10;
    static const int TEMP_MAX = 35;
    const float TEMP_UPPERTHIRD = (TEMP_MAX - TEMP_MIN) / 3.0f * 2.0f + TEMP_MIN;

    enum Cover
    {
      SUNNY, CLOUDY, OVERCAST, VERY_OVERCAST
    };
    enum Rank
    {
      NONE, LOW, MEDIUM, HIGH
    };

    //------------------------------------------------------------------------
    // Methods
    //
    EnvironmentalCondition(Cover sky_cover, Rank precipitation,
        float temperature, Rank wind);

    bool isItHot();
    bool isItRainy();
    bool isItStormy();

    //------------------------------------------------------------------------
    // Setter Methods
    //
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

    //------------------------------------------------------------------------
    // Getter Methods
    //
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
    //------------------------------------------------------------------------
    // To predicate if the sky is sunny, cloudy, overcast or very overcast
    //
    Cover sky_cover_;

    //------------------------------------------------------------------------
    // To rank it from none to high
    //
    Rank precipitation_;

    //------------------------------------------------------------------------
    // Variable for temperature for floating point operations
    //
    float temperature_;

    //------------------------------------------------------------------------
    // To rank it from none to high
    //
    Rank wind_;
};

#endif /* ENVIRONMENTALCONDITION_H_INCLUDED */
