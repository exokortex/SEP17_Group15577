//------------------------------------------------------------------------------
// CommandLoad.cpp
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

#include "CommandLoad.h"
#include "Command.h"
#include "GameHandler.h"

const string CommandLoad::NAME = "load";
const string CommandLoad::USAGE_STRING = "[ERR] Usage: load <filename>\n";
const string CommandLoad::ERROR_FILE_NOT_OPEN = "[ERR] Could not open file.\n";

//------------------------------------------------------------------------------
CommandLoad::CommandLoad() :
    Command(NAME)
{
}

//------------------------------------------------------------------------------
int CommandLoad::execute(GameHandler& game, vector<string>& params)
{
  if (params.size() != PARAMETER_COUNT)
  {
    game.output(USAGE_STRING);
    return Command::EXECUTION_RESULT_NO_SUCCESS;
  }

  string filename = params[0];

  std::ifstream file(filename);

  if (!file.is_open())
  {
    game.output(ERROR_FILE_NOT_OPEN);
    return Command::EXECUTION_RESULT_NO_SUCCESS;
  }

  string line;
  while (std::getline(file, line))
  {
    // TODO implement
  }

  if (file.bad())
    return EXECUTION_RESULT_NO_SUCCESS; // there was no error message specified

  return Command::EXECUTION_RESULT_SUCCESS;
}

