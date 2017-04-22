//------------------------------------------------------------------------------
// GameHandler.cpp
//
// Group: Group 15577, study assistant Roman Walch
//
// Authors: Johannes Haring 1611655
//          Thomas Moder 1615103
//          Verena Buder 1312723
//------------------------------------------------------------------------------
//

#include <stdlib.h>

#include "GameHandler.h"

#include "GameUI.h"

//------------------------------------------------------------------------------
GameHandler::GameHandler()
{
  //nothing to do
}

//------------------------------------------------------------------------------
int GameHandler::input(string command)
{
  output("test\n");
  return 1;
}

//------------------------------------------------------------------------------
void GameHandler::output(string output)
{
  view_->output(output);
}
