//------------------------------------------------------------------------------
// CommandQuote.cpp
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

#include "CommandQuote.h"
#include "Command.h"
#include "GameHandler.h"

const string CommandQuote::NAME = "quote";
const string CommandQuote::USAGE_STRING =
    "[ERR] Usage: quote\n";

CommandQuote::CommandQuote() :
    Command(NAME)
{
}

//------------------------------------------------------------------------------
int CommandQuote::execute(GameHandler& game, vector<string>& params)
{
  if (params.size() != PARAMETER_COUNT)
  {
    game.output(USAGE_STRING);
    return Command::EXECUTION_RESULT_NO_SUCCESS;
  }
  std::ostringstream out;
  {
    out << "L: "<<game.getPriceLemon()<<" $\n";
    out << "S: "<<game.getPriceSugar()<<" $\n";
  }
  game.output(out.str());
  return Command::EXECUTION_RESULT_SUCCESS;
}

