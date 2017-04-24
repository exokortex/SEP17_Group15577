//------------------------------------------------------------------------------
// CommandEcho.cpp
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

#include "CommandEcho.h"
#include "Command.h"
#include "GameHandler.h"

const string CommandEcho::NAME = "echo";
const string CommandEcho::SEPERATOR = " ";
const string CommandEcho::TERMINAL_STRING = "\n";

//------------------------------------------------------------------------------
CommandEcho::CommandEcho() :
    Command(NAME)
{
}

//------------------------------------------------------------------------------
int CommandEcho::execute(GameHandler& game, vector<string>& params)
{
  std::ostringstream out;
  vector<string>::iterator param;
  for (param = params.begin(); param != params.end(); param++)
  {
    out << *param;
    if (param + 1 != params.end())
      out << SEPERATOR;
  }
  out << TERMINAL_STRING;
  game.output(out.str());
  return Command::EXECUTION_RESULT_SUCCESS;
}
