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
  //nothing to do here
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

  body << "    <table cellpadding=\"10\" border=\"1\""
                "style=\"border-collapse: collapse; margin: 25px;\">"
          "      <tbody>"
          "        <tr>"
          "          <th>Precipitation:</th>"
          "          <td>" << ec.getPrecipitationString() << "</td>"
          "          <td rowspan=\"6\" align=\"center\">"
          "            <img src=\"" << skycoverimg << "\" alt=\"\""
                        "width=\"128\" height=\"128\" />"
          "            <br>" << skycoverstr << ""
          "          </td>"
          "        </tr>"
          "        <tr>"
          "          <th>Temperature:</th>"
          "          <td>" << ec.getTemperature() << "°C</td>"
          "        </tr>"
          "        <tr>"
          "          <th>Wind:</th>"
          "          <td>" << ec.getWindString() << "</td>"
          "        </tr>"
          "        <tr>"
          "          <th>Hot:</th>"
          "          <td>" << (ec.isItHot() ? "yes" : "no") << "</td>"
          "        </tr>"
          "        <tr>"
          "          <th>Rainy:</th>"
          "          <td>" << (ec.isItRainy() ? "yes" : "no") << "</td>"
          "        </tr>"
          "        <tr>"
          "          <th>Stormy:</th>"
          "          <td>" << (ec.isItStormy() ? "yes" : "no") << "</td>"
          "        </tr>"
          "      </tbody>"
          "    </table>";
  HTMLWriter::writeFile(body.str());
}
