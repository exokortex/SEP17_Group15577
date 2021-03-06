//------------------------------------------------------------------------------
// EnvironmentalEngine.h
//
// Group: Group 15577, study assistant Roman Walch
//
// Authors: Johannes Haring 1611655
//          Thomas Moder 1615103
//          Verena Buder 1312723
//------------------------------------------------------------------------------
//

#ifndef ENVIRONMENTALENGINE_H_INCLUDED
#define ENVIRONMENTALENGINE_H_INCLUDED

#include <memory>

class EnvironmentalCondition;

//------------------------------------------------------------------------------
// class EnvironmentalEngine
// generator for random EnvironmentalCondition objects
//
class EnvironmentalEngine
{
  public:
    //--------------------------------------------------------------------------
    // The precision of the random temperature (should be a power of 10)
    // If set to 10 to the power of n, then n is the number of fractional
    // digits.
    //
    static const int TEMP_DECIMAL_PRECISION = 10;

    //--------------------------------------------------------------------------
    // Constructor
    // Initializes the random function.
    //
    EnvironmentalEngine();

    //--------------------------------------------------------------------------
    // Creates a new random Environmental condition.
    //
    std::unique_ptr<EnvironmentalCondition> createCondition();

    //--------------------------------------------------------------------------
    // Creates a new random Environmental condition based on the previous.
    // @param previous_condition the previous Environmental condition
    //
    std::unique_ptr<EnvironmentalCondition> createCondition(
        EnvironmentalCondition& previous_condition);

    //--------------------------------------------------------------------------
    // Creates an Environmental condition with the minimum possible
    // values based on the previous.
    // @param previous_condition the previous Environmental condition
    //
    static std::unique_ptr<EnvironmentalCondition> getConditionMin(
        EnvironmentalCondition& previous_condition);

    //--------------------------------------------------------------------------
    // Creates an Environmental condition with the maximum possible
    // values based on the previous.
    // @param previous_condition the previous Environmental condition
    //
    static std::unique_ptr<EnvironmentalCondition> getConditionMax(
        EnvironmentalCondition& previous_condition);

  private:
    //--------------------------------------------------------------------------
    // Private copy constructor
    //
    EnvironmentalEngine(const EnvironmentalEngine& original) = delete;

    //--------------------------------------------------------------------------
    // Private assignment operator
    //
    EnvironmentalEngine& operator=(const EnvironmentalEngine& original)
       = delete;
};

#endif /* ENVIRONMENTALENGINE_H_INCLUDED */
