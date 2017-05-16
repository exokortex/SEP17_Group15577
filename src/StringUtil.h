//------------------------------------------------------------------------------
// StringUtil.h
//
// Group: Group 15577, study assistant Roman Walch
//
// Authors: Johannes Haring 1611655
//          Thomas Moder 1615103
//          Verena Buder 1312723
//------------------------------------------------------------------------------
//

#ifndef STRINGUTIL_H_INCLUDED
#define STRINGUTIL_H_INCLUDED

#include <string>
#include <vector>

using std::vector;
using std::string;

//------------------------------------------------------------------------------
// class StringUtil
// Provides static string manipulation functions
//
class StringUtil final
{
  public:
    //--------------------------------------------------------------------------
    // parse a string to int
    // @return if the parsing was successful
    //
    static bool strictParseInt(std::string input, int* output);

    //--------------------------------------------------------------------------
    // parse a string to float
    // @return if the parsing was successful
    //
    static bool strictParseFloat(std::string input, float* output);

    //--------------------------------------------------------------------------
    // stringsplit into vecor of string
    //
    static vector<string> split(const string& original, char separator);

  private:
    //--------------------------------------------------------------------------
    // Private copy constructor
    //
    StringUtil(const StringUtil& original) = delete;

    //--------------------------------------------------------------------------
    // Private assignment operator
    //
    StringUtil& operator=(const StringUtil& original) = delete;

    //--------------------------------------------------------------------------
    // Private Destructor (allow no objects)
    //
    virtual ~StringUtil() = delete;
};

#endif /* STRINGUTIL_H_INCLUDED */
