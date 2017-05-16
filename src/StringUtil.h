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

class StringUtil final
{
  public:
    static bool strictParseInt(std::string input, int* output);
    static bool strictParseFloat(std::string input, float* output);

    //--------------------------------------------------------------------------
    // stringsplit into vecor of string
    //
    static vector<string> split(const string& original, char separator);
  private:
    virtual ~StringUtil();
};

#endif /* STRINGUTIL_H_INCLUDED */
