//------------------------------------------------------------------------------
// CommandProduce.cpp
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

#include "CommandProduce.h"
#include "Command.h"
#include "GameHandler.h"
#include "StringUtil.h"

const string CommandProduce::NAME = "produce";
const string CommandProduce::USAGE_STRING = "[ERR] Usage: produce <lemonade>\n";
const string CommandProduce::ERROR_WRONG_PARAM = "[ERR] Wrong parameter.\n";

//------------------------------------------------------------------------------
CommandProduce::CommandProduce() :
    Command(NAME)
{
}

//------------------------------------------------------------------------------
int CommandProduce::execute(GameHandler& game, vector<string>& params)
{
  if (params.size() != PARAMETER_COUNT)
  {
    game.output(USAGE_STRING);
    return Command::EXECUTION_RESULT_NO_SUCCESS;
  }

  int lemonade;

  // if params are not strictly a number or lower zero
  if (!StringUtil::strictParseInt(params[0], &lemonade) || lemonade < 0)
  {
    game.output(ERROR_WRONG_PARAM);
    return Command::EXECUTION_RESULT_NO_SUCCESS;
  }

  int needed_sugar = lemonade * game.getRecipeSugar() / 2;
  int needed_lemon = lemonade * game.getRecipeSugar() / 3;

  // if the production cannot satisfied -> invalid parameter
  if (needed_sugar > game.getStockSugar()
      || needed_lemon > game.getStockLemon())
  {
    game.output(ERROR_WRONG_PARAM);
    return Command::EXECUTION_RESULT_NO_SUCCESS;
  }

  game.setStockSugar(game.getStockSugar() - needed_sugar);
  game.setStockLemon(game.getStockLemon() - needed_lemon);

  game.setLemonade(game.getLemonade() + lemonade);

  return Command::EXECUTION_RESULT_SUCCESS;
}

