//------------------------------------------------------------------------------
// HTMLWriterEnvironment.cpp
//
// Group: Group 15577, study assistant Roman Walch
//
// Authors: Johannes Haring 1611655
//          Thomas Moder 1615103
//          Verena Buder 1312723
//------------------------------------------------------------------------------
//

#include <sstream>

#include "HTMLWriterEnvironment.h"

//------------------------------------------------------------------------------
HTMLWriterEnvironment::HTMLWriterEnvironment(string filename) :
    HTMLWriter::HTMLWriter(filename)
{
  // nothing to do here
}

//------------------------------------------------------------------------------
void HTMLWriterEnvironment::writeFile(EnvironmentalCondition ec)
{
  std::stringstream body;

  string skycoverstr;
  string skycoverimg;

  switch (ec.getSkyCover()) {
    case EnvironmentalCondition::SUNNY:
      skycoverstr = "sunny";
      skycoverimg = "https://palme.iicm.tugraz.at/wiki/images/9/9a/"
          "Sunny.png";
      break;
    case EnvironmentalCondition::CLOUDY:
      skycoverstr = "cloudy";
      skycoverimg = "https://palme.iicm.tugraz.at/wiki/images/3/33/"
          "Cloudy.png";
      break;
    case EnvironmentalCondition::OVERCAST:
      skycoverstr = "overcast";
      skycoverimg = "https://palme.iicm.tugraz.at/wiki/images/6/6f/"
          "Overcast.png";
      break;
    case EnvironmentalCondition::VERY_OVERCAST:
      skycoverstr = "very overcast";
      skycoverimg = "https://palme.iicm.tugraz.at/wiki/images/3/30/"
          "Very_overcast.png";
      break;
    default:
      break;
  }

  body << "    <table style=\"margin: 25px;\">\n"
          "      <tbody>\n"
          "        <tr>\n"
          "          <th>Precipitation:</th>\n"
          "          <td>" << ec.getPrecipitationString() << "</td>\n"
          "          <td rowspan=\"6\" style=\"text-align: center\">\n"
          "            <img src=\"" << skycoverimg << "\" alt=\"\""
                        " width=\"128\" height=\"128\" />\n"
          "            <br>" << skycoverstr << "\n"
          "          </td>\n"
          "        </tr>\n"
          "        <tr>\n"
          "          <th>Temperature:</th>\n"
          "          <td>" << ec.getTemperature() << "°C</td>\n"
          "        </tr>\n"
          "        <tr>\n"
          "          <th>Wind:</th>\n"
          "          <td>" << ec.getWindString() << "</td>\n"
          "        </tr>\n"
          "        <tr>\n"
          "          <th>Hot:</th>\n"
          "          <td>" << (ec.isItHot() ? "yes" : "no") << "</td>\n"
          "        </tr>\n"
          "        <tr>\n"
          "          <th>Rainy:</th>\n"
          "          <td>" << (ec.isItRainy() ? "yes" : "no") << "</td>\n"
          "        </tr>\n"
          "        <tr>\n"
          "          <th>Stormy:</th>\n"
          "          <td>" << (ec.isItStormy() ? "yes" : "no") << "</td>\n"
          "        </tr>\n"
          "      </tbody>\n"
          "    </table>\n";
  HTMLWriter::writeFile(body.str());
}
