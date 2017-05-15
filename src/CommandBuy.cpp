//------------------------------------------------------------------------------
// CommandBuy.cpp
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

#include "CommandBuy.h"
#include "Command.h"
#include "GameHandler.h"
#include "StringUtil.h"

const string CommandBuy::NAME = "buy";
const string CommandBuy::USAGE_STRING = "[ERR] Usage: buy <lemon> <sugar>\n";
const string CommandBuy::ERROR_NOT_ENOUGH_MONEY =
    "[WARN] Not enough money. I buy what I can.\n";

CommandBuy::CommandBuy() :
    Command(NAME)
{
}

//------------------------------------------------------------------------------
int CommandBuy::execute(GameHandler& game, vector<string>& params)
{
  if (params.size() != PARAMETER_COUNT)
  {
    game.output(USAGE_STRING);
    return Command::EXECUTION_RESULT_NO_SUCCESS;
  }

  int lemon;
  int sugar;

  // if params are not strictly a number or lower zero
  if (!StringUtil::strictParseInt(params[0], &lemon) || lemon < 0
      || !StringUtil::strictParseInt(params[1], &sugar) || sugar < 0)
  {
    game.output(USAGE_STRING);
    return Command::EXECUTION_RESULT_NO_SUCCESS;
  }

  int total_cost;
  // reduce amount until price is payable
  // TODO: fix problem with buying multiple times in the same round
  while ((total_cost = lemon * game.getPriceLemon()
      + sugar * game.getPriceSugar() + game.getExpence()) > game.getStockCash())
  {
    lemon = std::max(0, lemon - 1);
    sugar = std::max(0, sugar - 1);
  }

  game.setExpence(total_cost);
  game.setStockLemon(game.getStockLemon() + lemon);
  game.setStockSugar(game.getStockSugar() + sugar);

  std::ostringstream out;
  out << "Bought:\n";
  out << "L: " << lemon << "\n";
  out << "S: " << sugar << "\n";
  game.output(out.str());
  return Command::EXECUTION_RESULT_SUCCESS;
}

