//------------------------------------------------------------------------------
// CommandWrite.cpp
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
#include <iostream>
#include <fstream>

#include "CommandSave.h"
#include "Command.h"
#include "GameHandler.h"
#include "StringUtil.h"

const string CommandSave::NAME = "save";
const string CommandSave::USAGE_STRING = "[ERR] Usage: save <filename>\n";
const string CommandSave::ERROR_FILE_NOT_OPEN = "[ERR] Could not open file.\n";

//------------------------------------------------------------------------------
CommandSave::CommandSave() :
    Command(NAME)
{
}

//------------------------------------------------------------------------------
int CommandSave::execute(GameHandler& game, vector<string>& params)
{
  if (params.size() != PARAMETER_COUNT)
  {
    game.output(USAGE_STRING);
    return Command::EXECUTION_RESULT_NO_SUCCESS;
  }

  string filename = params[0];

  std::ofstream file;
  file.open(filename);

  if (!file.is_open())
  {
    game.output(ERROR_FILE_NOT_OPEN);
    return Command::EXECUTION_RESULT_NO_SUCCESS;
  }

  file << "<savefile>\n"
      "  <weather>\n"
      "    <wind>" << game.getNextWeather().getWindStringUpper()
      << "</wind>\n"
      "    <temperature>" << game.getNextWeather().getTemperature()
      << "</temperature>\n"
      "    <precipitation>"
      << game.getNextWeather().getPrecipitationStringUpper()
      << "</precipitation>\n"
      "    <cover>" << game.getNextWeather().getSkyCoverStringUpper()
      << "</cover>\n"
      "  </weather>\n"
      "  <stats>\n"
      "    <cash>" << game.getStockCash() << "</cash>\n"
      "    <balance>" << game.getBalance() << "</balance>\n"
      "    <income>" << game.getIncome() << "</income>\n"
      "    <expence>" << game.getExpence() << "</expence>\n"
      "    <lemons>" << game.getStockLemon() << "</lemons>\n"
      "    <sugar>" << game.getStockSugar() << "</sugar>\n"
      "    <pricesugar>" << game.getPriceSugar() << "</pricesugar>\n"
      "    <pricelemons>" << game.getPriceLemon() << "</pricelemons>\n"
      "  </stats>\n"
      "</savefile>\n";

  if (file.bad())
    return EXECUTION_RESULT_NO_SUCCESS; // there was no error message specified

  file.close();

  return Command::EXECUTION_RESULT_SUCCESS;
}

