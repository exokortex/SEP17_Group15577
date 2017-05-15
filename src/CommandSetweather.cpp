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
  if (params.size() != PARAMETER_COUNT)
  {
    game.output(USAGE_STRING);
    return Command::EXECUTION_RESULT_NO_SUCCESS;
  }

  int sky_cover_int = 0;
  int precipitation_int = 0;
  float temperature = 0;
  int wind_int = 0;

  if (!StringUtil::strictParseInt(params[0], &sky_cover_int)
     || sky_cover_int < 0
      || sky_cover_int >= EnvironmentalCondition::COVER_SIZE
      || !StringUtil::strictParseInt(params[1], &precipitation_int)
  || precipitation_int < 0
      || precipitation_int >= EnvironmentalCondition::RANK_SIZE
      || !StringUtil::strictParseFloat(params[2], &temperature)
  || temperature < EnvironmentalCondition::TEMP_MIN
     || temperature > EnvironmentalCondition::TEMP_MAX
      || !StringUtil::strictParseInt(params[3], &wind_int) || wind_int < 0
          || wind_int >= EnvironmentalCondition::COVER_SIZE)
  {
    game.output(USAGE_STRING);
    return Command::EXECUTION_RESULT_NO_SUCCESS;
  }

  EnvironmentalCondition::Cover sky_cover = EnvironmentalCondition::Cover(
      sky_cover_int);
  EnvironmentalCondition::Rank precipitation = EnvironmentalCondition::Rank(
      precipitation_int);
  EnvironmentalCondition::Rank wind = EnvironmentalCondition::Rank(wind_int);

  game.setNextWeather(
      std::unique_ptr<EnvironmentalCondition>(
          new EnvironmentalCondition(sky_cover, precipitation, temperature,
              wind)));

  game.viewUpdateEnvironment();

  return Command::EXECUTION_RESULT_SUCCESS;
}
