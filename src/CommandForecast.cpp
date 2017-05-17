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

const string CommandForecast::NAME = "balance";
const string CommandForecast::USAGE_STRING = "[ERR] Usage: balance\n";

//------------------------------------------------------------------------------
CommandForecast::CommandForecast() :
    Command(NAME)
{
}

//------------------------------------------------------------------------------
int CommandForecast::execute(GameHandler& game, vector<string>& params)
{

}
