//------------------------------------------------------------------------------
// CommandBalance.cpp
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

#include "CommandBalance.h"
#include "Command.h"
#include "GameHandler.h"

const string CommandBalance::NAME = "balance";
const string CommandBalance::USAGE_STRING =
    "[ERR] Usage: balance\n";

CommandBalance::CommandBalance():
    Command(NAME)
{
}

//------------------------------------------------------------------------------
int CommandBalance::execute(GameHandler& game, vector<string>& params)
{
  if (params.size() != PARAMETER_COUNT)
  {
    game.output(USAGE_STRING);
    return Command::EXECUTION_RESULT_NO_SUCCESS;
  }
  std::ostringstream out;
  {
    out << "L: 100\n";
    out << "S: 100\n";
    out << "----------\n";
    out << "C: 1000 $\n";
  }
  game.output(out.str());
  return Command::EXECUTION_RESULT_SUCCESS;
}
