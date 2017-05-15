/*
 * StringUtil.cpp
 *
 *  Created on: 15.05.2017
 *      Author: johannes
 */

#include "StringUtil.h"

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
