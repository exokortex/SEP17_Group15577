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

#include <algorithm>

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

//------------------------------------------------------------------------------
vector<string> StringUtil::split(const std::string& original, char separator)
{
  std::vector<std::string> results;
  std::string::const_iterator start = original.begin();
  std::string::const_iterator end = original.end();
  std::string::const_iterator next = std::find(start, end, separator);
  while (next != end)
  {
    // ignore empty parts
    if (start != next)
      results.push_back(std::string(start, next));
    start = next + 1;
    next = std::find(start, end, separator);
  }
  // ignore empty parts
  if (start != next)
    results.push_back(std::string(start, next));
  return results;
}
