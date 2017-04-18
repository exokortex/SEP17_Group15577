// Group: Group 15577, study assistant Roman Walch
//
// Authors: Johannes Haring 1611655
//          Thomas Moder 1615103
//          Verena Buder 1312723
//------------------------------------------------------------------------------
//

#ifndef HTMLWRITERBALANCE_H_INCLUDED
#define HTMLWRITERBALANCE_H_INCLUDED

#include "HTMLWriter.h"

class HTMLWriterBalance : HTMLWriter
{
  public:
    HTMLWriterBalance(std::string filename);
    void writeFile(int lemon, int sugar, int cash, int delta);
};

#endif /* HTMLWRITERBALANCE_H_INCLUDED */
