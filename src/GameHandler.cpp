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

//------------------------------------------------------------------------------
GameHandler::GameHandler(GameGUI view)
{
  this->view_ = view;
}

//------------------------------------------------------------------------------
int GameHandler::input(string command)
{
  return 1;
}

//------------------------------------------------------------------------------
void GameHandler::output(string output)
{
  this->view_.output(output);
}
