//------------------------------------------------------------------------------
// CommandForecast.cpp
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

#include "CommandForecast.h"
#include "Command.h"
#include "GameHandler.h"
#include "EnvironmentalEngine.h"

const string CommandForecast::NAME = "forecast";
const string CommandForecast::USAGE_STRING = "[ERR] Usage: forecast\n";

//------------------------------------------------------------------------------
CommandForecast::CommandForecast() :
    Command(NAME)
{
}

//------------------------------------------------------------------------------
int CommandForecast::execute(GameHandler& game, vector<string>& params)
{
  if (params.size() != PARAMETER_COUNT)
  {
    game.output(USAGE_STRING);
    return Command::EXECUTION_RESULT_NO_SUCCESS;
  }
  std::unique_ptr<EnvironmentalCondition> minima =
      EnvironmentalEngine::getConditionMin(game.getNextWeather());
  std::unique_ptr<EnvironmentalCondition> maxima =
      EnvironmentalEngine::getConditionMax(game.getNextWeather());
  std::ostringstream out;
  out << "Next game weekend, the temperature will be between ";
  out << minima->getTemperature() << " and " << maxima->getTemperature();
  out << "°C." << std::endl;
  out << "The precipitation will be between ";
  out << minima->getPrecipitationString() << " and ";
  out << maxima->getPrecipitationString() << std::endl;
  out << "Sky coverage will be between ";
  out << minima->getSkyCoverString() << " and ";
  out << maxima->getSkyCoverString() << std::endl;
  out << "We expect wind to be from ";
  out << minima->getWindString() << " to ";
  out << maxima->getWindString() << std::endl;
  game.output(out.str());
  return Command::EXECUTION_RESULT_SUCCESS;
}
