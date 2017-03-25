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

#include "EnvironmentalCondition.h"

class EnvironmentalEngine
{
  public:
    EnvironmentalEngine();
    EnvironmentalCondition createCondition();
};

#endif /* ENVIRONMENTALENGINE_H_INCLUDED */
