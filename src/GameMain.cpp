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
#include <memory>

#include "GameHandler.h"
#include "GameUI.h"

int main()
{
  // create game Controller object reference
  std::unique_ptr<GameHandler> handler ( new GameHandler() );

  // create game View object reference
  std::unique_ptr<GameUI> view ( new GameUI() );

  // set View on Controller
  handler->setView(std::move(view));

  // start program
  handler->run();

  return 0;
}
