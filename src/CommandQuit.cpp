//------------------------------------------------------------------------------
// CommandQuit.cpp
//
// Group: Group 15577, study assistant Roman Walch
//
// Authors: Johannes Haring 1611655
//          Thomas Moder 1615103
//          Verena Buder 1312723
//------------------------------------------------------------------------------
//

#include <string>

#include "CommandQuit.h"
#include "Command.h"
#include "GameHandler.h"

const string CommandQuit::NAME = "quit";
const string CommandQuit::USAGE_STRING =
    "[ERR] Usage: quit\n";
const string CommandQuit::MESSAGE = "Going out of business!\n";

//------------------------------------------------------------------------------
CommandQuit::CommandQuit() :
    Command(NAME)
{
}

//------------------------------------------------------------------------------
int CommandQuit::execute(GameHandler& game, vector<string>& params)
{
  if (params.size() != PARAMETER_COUNT)
  {
    game.output(USAGE_STRING);
    return Command::EXECUTION_RESULT_NO_SUCCESS;
  }
  game.output(MESSAGE);
  return Command::EXECUTION_RESULT_REQUEST_TERMINATION;
}
