#include <iostream>

#include "GameHandler.h"
#include "GameUI.h"

int main()
{
  //create game Controller object reference
  GameHandler* handler = new GameHandler();

  //create and run game View object
  GameUI view = GameUI(handler);
  view.run();

  return 0;
}
