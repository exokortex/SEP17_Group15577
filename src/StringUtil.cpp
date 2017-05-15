//------------------------------------------------------------------------------
// StringUtil.cpp
//
// Group: Group 15577, study assistant Roman Walch
//
// Authors: Johannes Haring 1611655
//          Thomas Moder 1615103
//          Verena Buder 1312723
//------------------------------------------------------------------------------
//

#include "StringUtil.h"

//------------------------------------------------------------------------------
bool StringUtil::strictParseInt(std::string input, int* output)
{
  try
  {
    size_t pos;
    *output = std::stoi(input, &pos);
    return pos == input.size();
  }
  // catch std::invalid_argument or std::out_of_range
  catch (const std::exception& e)
  {
    return false;
  }
}

//------------------------------------------------------------------------------
bool StringUtil::strictParseFloat(std::string input, float* output)
{
  try
  {
    size_t pos;
    *output = std::stof(input, &pos);
    return pos == input.size();
  }
  // catch std::invalid_argument or std::out_of_range
  catch (const std::exception& e)
  {
    return false;
  }
}
