//------------------------------------------------------------------------------
// GameMain.cpp
//
// Group: Group 15577, study assistant Roman Walch
//
// Authors: Johannes Haring 1611655
//          Thomas Moder 1615103
//          Verena Buder 1312723
//------------------------------------------------------------------------------
//

#include <iostream>

#include "GameHandler.h"
#include "GameUI.h"

int main()
{
  //create game Controller object reference
  GameHandler* handler = new GameHandler();

  //create game View object reference
  GameUI* view = new GameUI(handler);
  //set View on Controller
  handler->setView(view);

  //start program
  handler->run();

  delete handler;
  delete view;

  return 0;
}
