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

#include "CommandPlay.h"
#include "Command.h"
#include "GameHandler.h"

const string CommandPlay::NAME = "play";
const string CommandPlay::USAGE_STRING =
    "[ERR] Usage: play\n";

//------------------------------------------------------------------------------
CommandPlay::CommandPlay() :
    Command(NAME)
{
}

//------------------------------------------------------------------------------
int CommandPlay::execute(GameHandler& game, vector<string>& params)
{
  if (params.size() != PARAMETER_COUNT)
  {
    game.output(USAGE_STRING);
    return Command::EXECUTION_RESULT_NO_SUCCESS;
  }
  game.play();
  return Command::EXECUTION_RESULT_SUCCESS;
}
