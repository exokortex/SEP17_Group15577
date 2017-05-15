//------------------------------------------------------------------------------
// CommandSetweather.cpp
//
// Group: Group 15577, study assistant Roman Walch
//
// Authors: Johannes Haring 1611655
//          Thomas Moder 1615103
//          Verena Buder 1312723
//------------------------------------------------------------------------------
//

#include <string>
#include <sstream>

#include "CommandSetweather.h"
#include "GameHandler.h"
#include "StringUtil.h"

const string CommandSetweather::NAME = "setweather";
const string CommandSetweather::USAGE_STRING =
    "[ERR] Usage: setweather <cover> <precipitation> <temperature> <wind>\n";
const string CommandSetweather::ERROR_PARAM = "[ERR] Wrong parameter.\n";

CommandSetweather::CommandSetweather() :
    Command(NAME)
{
}

//------------------------------------------------------------------------------
int CommandSetweather::execute(GameHandler& game, vector<string>& params)
{
  int sky_cover_int;
  int precipitation_int;
  float temperature;
  int wind_int;

  if (!StringUtil::strictParseInt(params[0], &sky_cover_int)
      || !StringUtil::strictParseInt(params[1], &precipitation_int)
      || !StringUtil::strictParseInt(params[3], &wind_int))
  {
    return Command::EXECUTION_RESULT_NO_SUCCESS;
  }

  EnvironmentalCondition::Cover sky_cover = EnvironmentalCondition::Cover(
      sky_cover_int);

  EnvironmentalCondition::Rank precipitation = EnvironmentalCondition::Rank(
      precipitation_int);

  EnvironmentalCondition::Rank wind = EnvironmentalCondition::Rank(wind_int);

  std::unique_ptr<EnvironmentalCondition> condition(
      new EnvironmentalCondition(sky_cover, precipitation, temperature, wind));

  handler->setNextWeather(condition);
}
