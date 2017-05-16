//------------------------------------------------------------------------------
// HTMLWriter.h
//
// Group: Group 15577, study assistant Roman Walch
//
// Authors: Johannes Haring 1611655
//          Thomas Moder 1615103
//          Verena Buder 1312723
//------------------------------------------------------------------------------
//

#ifndef HTMLWRITER_H_INCLUDED
#define HTMLWRITER_H_INCLUDED

#include <string>

using std::string;

//------------------------------------------------------------------------------
// class HTMLWriter
// generic HTML file writer
//
class HTMLWriter
{
  public:
    //--------------------------------------------------------------------------
    // Constructor
    // sets the default filename for output
    //
    HTMLWriter(string filename);

    //--------------------------------------------------------------------------
    // writeFile
    // wirtes an HTML file with the parameter as body.
    // @param the body of the HTML-File to write
    //
    void writeFile(string body);

  private:
    //--------------------------------------------------------------------------
    // the default filename
    //
    string filename_;

    //--------------------------------------------------------------------------
    // Private copy constructor
    //
    HTMLWriter(const HTMLWriter& original) = delete;

    //--------------------------------------------------------------------------
    // Private assignment operator
    //
    HTMLWriter& operator=(const HTMLWriter& original) = delete;
};

#endif /* HTMLWRITER_H_INCLUDED */
