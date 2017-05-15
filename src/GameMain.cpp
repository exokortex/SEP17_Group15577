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
#include "StringUtil.h"

int main(int argc, char *argv[])
{
  int price_lemonade;
  int price_lemon;
  int price_sugar;

  // parse params
  if (argc != 4 || !StringUtil::strictParseInt(argv[1], &price_lemonade)
      || !StringUtil::strictParseInt(argv[2], &price_lemon)
      || !StringUtil::strictParseInt(argv[3], &price_sugar))
  {
    std::cout
        << "[ERR] Wrong usage: ./basic <price_lemonade> <price_lemon> <price_sugar>"
        << std::endl;
    return 1;
  }

  // create game Controller object reference
  std::unique_ptr<GameHandler> handler(new GameHandler(price_lemonade, price_lemon, price_sugar));

  // create game View object reference
  std::unique_ptr<GameUI> view(new GameUI());

  // set View on Controller
  handler->setView(std::move(view));

  // start program
  handler->run();

  return 0;
}
