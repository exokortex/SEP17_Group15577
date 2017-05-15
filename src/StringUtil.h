/*
 * StringUtil.h
 *
 *  Created on: 15.05.2017
 *      Author: johannes
 */

#ifndef STRINGUTIL_H_INCLUDED
#define STRINGUTIL_H_INCLUDED

#include <string>

class StringUtil final
{
  public:
    static bool strictParseInt(std::string input, int* output);
  private:
    virtual ~StringUtil();
};

#endif /* STRINGUTIL_H_INCLUDED */
