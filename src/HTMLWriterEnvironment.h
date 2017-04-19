//------------------------------------------------------------------------------
// HTMLWriterEnvironment.h
//
// Group: Group 15577, study assistant Roman Walch
//
// Authors: Johannes Haring 1611655
//          Thomas Moder 1615103
//          Verena Buder 1312723
//------------------------------------------------------------------------------
//

#ifndef HTMLWRITERENVIRONMENT_H_INCLUDED
#define HTMLWRITERENVIRONMENT_H_INCLUDED

#include "HTMLWriter.h"
#include "EnvironmentalCondition.h"

//------------------------------------------------------------------------------
// class HTMLWriterEnvironment
// HTMLWriter for the current EnvironmentalCondition
//
class HTMLWriterEnvironment : HTMLWriter
{
  public:
    //--------------------------------------------------------------------------
    // Constructor
    // sets the default filename for output
    //
    HTMLWriterEnvironment(string filename);

    //--------------------------------------------------------------------------
    // writeFile
    // Writes an HTML file according to the parameters
    // @param EnvironmentalCondition the EnvironmentalCondition to be
    //        represented in the file
    //
    void writeFile(EnvironmentalCondition ec);
};

#endif /* HTMLWRITERENVIRONMENT_H_INCLUDED */
