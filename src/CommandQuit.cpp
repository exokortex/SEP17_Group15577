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
#include "GameHandler.h"

const string NAME = "quit";

//------------------------------------------------------------------------------
CommandQuit::CommandQuit() :
    Command(NAME)
{
  //nothing to do
}

//------------------------------------------------------------------------------
int CommandQuit::execute(GameHandler& game, vector<string>& params)
{
  game.output("Going out of business!\n");
  return -1;
}
