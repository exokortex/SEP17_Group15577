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

#include <string>

using std::string;

//------------------------------------------------------------------------------
// class EnvironmentalCondition
// dataclass for one state of the environment
//
class EnvironmentalCondition
{
  public:
    //--------------------------------------------------------------------------
    // The minimal temperature in degrees celsius
    //
    static const int TEMP_MIN = 10;

    //--------------------------------------------------------------------------
    // The maximal temperature in degrees celsius
    //
    static const int TEMP_MAX = 35;

    //--------------------------------------------------------------------------
    // The threshold for the upper third of the temperature specturm
    //
    const float TEMP_UPPERTHIRD = (TEMP_MAX - TEMP_MIN) / 3.0f * 2.0f
        + TEMP_MIN;

    //--------------------------------------------------------------------------
    // The threshold for the lower third of the temperature specturm
    //
    const float TEMP_LOWERTHIRD = (TEMP_MAX - TEMP_MIN) / 3.0f
        + TEMP_MIN;

    //--------------------------------------------------------------------------
    // The size of the Cover enum
    //
    static const int COVER_SIZE = 4;

    //--------------------------------------------------------------------------
    // The size of the Rank enum
    //
    static const int RANK_SIZE = 4;

    //--------------------------------------------------------------------------
    // To predicate if the sky is sunny, cloudy, overcast or very overcast
    //
    enum Cover
    {
      SUNNY, CLOUDY, OVERCAST, VERY_OVERCAST
    };

    //--------------------------------------------------------------------------
    // To rank from none to high
    //
    enum Rank
    {
      NONE, LOW, MEDIUM, HIGH
    };

    //--------------------------------------------------------------------------
    // Constructor
    // Creates an object and sets the member variables accordingly.
    // @param sky_cover the cover level of the sky
    // @param precipitation the cover level of the sky
    // @param temperature the temperature in degrees celsius
    // @param wind the rank of the wind
    //
    EnvironmentalCondition(Cover sky_cover, Rank precipitation,
        float temperature, Rank wind);

    //--------------------------------------------------------------------------
    // isItHot
    // @return Returns true if sky_cover is sunny and temperature is in
    //         the upper third of the specturm
    //
    bool isItHot();

    //--------------------------------------------------------------------------
    // isItCold
    // @return Returns true if temperature is in
    //         the lower third of the specturm
    //
    bool isItCold();

    //--------------------------------------------------------------------------
    // isItRainy
    // @return Returns true if precipitation is medium or high and
    //         sky_cover is overcast or very overcast
    //
    bool isItRainy();

    //--------------------------------------------------------------------------
    // isItStormy
    // @return Returns true if wind is medium or high and
    //         sky_cover is overcast or very overcast
    //
    bool isItStormy();

    //--------------------------------------------------------------------------
    // getSkyCoverString
    // @return Returns the sky cover condition as string
    //
    string getSkyCoverString();

    //--------------------------------------------------------------------------
    // getWindString
    // @return Returns the wind condition as string
    //
    string getWindString();

    //--------------------------------------------------------------------------
    // getPrecipitationString
    // @return Returns the precipitation condition as string
    //
    string getPrecipitationString();

    //--------------------------------------------------------------------------
    // getSkyCoverStringUpper
    // @return Returns the sky cover condition as string in uppercase
    //
    string getSkyCoverStringUpper();

    //--------------------------------------------------------------------------
    // getWindStringUpper
    // @return Returns the wind condition as string in uppercase
    //
    string getWindStringUpper();

    //--------------------------------------------------------------------------
    // getPrecipitationStringUpper
    // @return Returns the precipitation condition as string in uppercase
    //
    string getPrecipitationStringUpper();

    //--------------------------------------------------------------------------
    // rankToString
    // @return Converts the given rank to a human-readable string
    // @param rank the rank to convert
    //
    static string rankToString(Rank rank);

    //--------------------------------------------------------------------------
    // Setter Methods
    //
    inline void setSkyCover(Cover cover)
    {
      sky_cover_ = cover;
    }
    inline void setPrecipitation(Rank rank)
    {
      precipitation_ = rank;
    }
    inline void setTemperature(float temperature)
    {
      temperature_ = temperature;
    }
    inline void setWind(Rank rank)
    {
      wind_ = rank;
    }

    //--------------------------------------------------------------------------
    // Getter Methods
    //
    inline Cover getSkyCover() const
    {
      return sky_cover_;
    }
    inline Rank getPrecipitation() const
    {
      return precipitation_;
    }
    inline float getTemperature() const
    {
      return temperature_;
    }
    inline Rank getWind() const
    {
      return wind_;
    }

  private:
    //--------------------------------------------------------------------------
    // To predicate if the sky is sunny, cloudy, overcast or very overcast
    //
    Cover sky_cover_;

    //--------------------------------------------------------------------------
    // The rank of the precipitation
    //
    Rank precipitation_;

    //--------------------------------------------------------------------------
    // The termperature in degrees celsius
    //
    float temperature_;

    //--------------------------------------------------------------------------
    // The strength of the wind
    //
    Rank wind_;

    //--------------------------------------------------------------------------
    // Private copy constructor
    //
    EnvironmentalCondition(const EnvironmentalCondition& original) = delete;

    //--------------------------------------------------------------------------
    // Private assignment operator
    //
    EnvironmentalCondition& operator=(const EnvironmentalCondition& original)
      = delete;
};

#endif /* ENVIRONMENTALCONDITION_H_INCLUDED */
