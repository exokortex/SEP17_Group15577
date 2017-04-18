//------------------------------------------------------------------------------
// HTMLWriter.cpp
//
// Group: Group 15577, study assistant Roman Walch
//
// Authors: Johannes Haring 1611655
//          Thomas Moder 1615103
//          Verena Buder 1312723
//------------------------------------------------------------------------------
//

#include <iostream>
#include <fstream>

#include "HTMLWriter.h"

//------------------------------------------------------------------------------
HTMLWriter::HTMLWriter(std::string filename)
{
  this->filename_ = filename;
}

//------------------------------------------------------------------------------
void HTMLWriter::writeFile(std::string body)
{
  std::ofstream file;
  file.open(this->filename_);

  file << "<!DOCTYPE html>" "<html lang=\"en\">\n"
      "  <head>\n"
      "    <meta charset=\"utf-8\">\n"
      "    <meta http-equiv=\"refresh\" content=\"3\">\n"
      "    <title>SEP 2017</title>\n"
      "    <style>body{margin: 0px; padding: 0px;}</style>\n"
      "  </head>\n"
      "  <body>\n" << body << "</body>\n"
      "</html>\n";

  file.close();
}
