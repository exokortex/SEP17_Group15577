//------------------------------------------------------------------------------
// CommandQuit.cpp
//
// Group: Group 15577, study assistant Roman Walch
//
// Authors: Johannes Haring 1611655
//          Thomas Moder 1615103
//          Verena Buder 1312723
//          Tutors
//------------------------------------------------------------------------------
//

#include <string>

#include "CommandQuit.h"
#include "Command.h"

using std::string;

const string NAME = "quit";

//------------------------------------------------------------------------------
CommandQuit::CommandQuit(vector<string>* params) :
    Command::Command(NAME, params)
{
  //nothing to do
}

//------------------------------------------------------------------------------
int CommandQuit::validate(GameHandler& game)
{
  return 1;
}

//------------------------------------------------------------------------------
int CommandQuit::execute(GameHandler& game)
{
  return 1;
}
