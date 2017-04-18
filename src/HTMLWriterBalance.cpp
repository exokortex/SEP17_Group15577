// Group: Group 15577, study assistant Roman Walch
//
// Authors: Johannes Haring 1611655
//          Thomas Moder 1615103
//          Verena Buder 1312723
//------------------------------------------------------------------------------
//

#include "HTMLWriterBalance.h"

#include <sstream>

HTMLWriterBalance::HTMLWriterBalance(std::string filename) :
    HTMLWriter::HTMLWriter(filename)
{
  // noting left to do here
}

void HTMLWriterBalance::writeFile(int lemon, int sugar, int cash, int delta)
{
  std::ostringstream body;
  body
      << "    <table>\n"
          "      <tbody>\n"
          "        <tr>\n"
          "          <td><img src=\"https://palme.iicm.tugraz.at/wiki/images/3/35/Lemon.png\" alt=\"\" width=\"64\" height=\"64\" /></td>\n"
          "          <td><strong>Lemons: </strong>" << lemon
      << "</td>\n"
          "        </tr>\n"
          "        <tr>\n"
          "          <td><img src=\"https://palme.iicm.tugraz.at/wiki/images/a/a9/Sugar.png\" alt=\"\" width=\"64\" height=\"64\" /></td>\n"
          "          <td><strong>Sugar: </strong>" << sugar
      << "</td>\n"
          "        </tr>\n"
          "        <tr>\n"
          "          <td><img src=\"https://palme.iicm.tugraz.at/wiki/images/f/f0/Coins.png\" alt=\"\" width=\"64\" height=\"64\" /></td>\n"
          "          <td>\n"
          "            <p><strong>Cash: </strong>" << cash << "$</p>\n"
          "            <p><strong>Delta: </strong>" << delta << "$</p>\n"
          "          </td>\n"
          "        </tr>\n"
          "      </tbody>\n"
          "    </table>\n";

  HTMLWriter::writeFile(body.str());
}
