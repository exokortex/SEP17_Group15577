//------------------------------------------------------------------------------
// HTMLWriterBalance.h
//
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

//------------------------------------------------------------------------------
// class HTMLWriterBalance
// HTMLWriter for the current balance
//
class HTMLWriterBalance : HTMLWriter
{
  public:
    //--------------------------------------------------------------------------
    // Constructor
    // sets the default filename for output
    //
    HTMLWriterBalance(std::string filename);

    //--------------------------------------------------------------------------
    // writeFile
    // Writes an HTML file according to the parameters
    // @param lemon the lemon count
    // @param sugar the sugar count
    // @param cash the cash
    // @param delta the delta
    //
    void writeFile(int lemon, int sugar, int cash, int delta);
};

#endif /* HTMLWRITERBALANCE_H_INCLUDED */
