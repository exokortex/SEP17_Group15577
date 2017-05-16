//------------------------------------------------------------------------------
// CommandRecipe.cpp
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

#include "CommandRecipe.h"
#include "Command.h"
#include "GameHandler.h"
#include "StringUtil.h"

const string CommandRecipe::NAME = "recipe";
const string CommandRecipe::USAGE_STRING =
    "[ERR] Usage: recipe [lemon] [sugar] [water]\n";
const string CommandRecipe::ERROR_WRONG_PARAM = "[ERR] Wrong parameter.\n";
const string CommandRecipe::ERROR_SUM = "[ERR] The sum of parts must be 100.\n";
const string CommandRecipe::ERROR_LEMON =
    "[ERR] The value of Lemon must be a multiple of 3.\n";
const string CommandRecipe::ERROR_SUGAR =
    "[ERR] The value of Sugar must be a multiple of 2.\n";

CommandRecipe::CommandRecipe() :
    Command(NAME)
{
}

//------------------------------------------------------------------------------
int CommandRecipe::execute(GameHandler& game, vector<string>& params)
{
  if (params.size() != PARAMETER_COUNT && params.size() != 0)
  {
    game.output(USAGE_STRING);
    return Command::EXECUTION_RESULT_NO_SUCCESS;
  }
  if (params.size() == PARAMETER_COUNT)
  {
    int lemon;
    int sugar;
    int water;

    // if params are not strictly a number or lower zero
    if (!StringUtil::strictParseInt(params[0], &lemon) || lemon < 0
        || !StringUtil::strictParseInt(params[1], &sugar) || sugar < 0
        || !StringUtil::strictParseInt(params[2], &water) || water < 0)
    {
      game.output(ERROR_WRONG_PARAM);
      return Command::EXECUTION_RESULT_NO_SUCCESS;
    }
    if (lemon + sugar + water != EXPECTED_SUM)
    {
      game.output(ERROR_SUM);
      return Command::EXECUTION_RESULT_NO_SUCCESS;
    }
    if (lemon % LEMON_MULTIPLES != 0)
    {
      game.output(ERROR_LEMON);
      return Command::EXECUTION_RESULT_NO_SUCCESS;
    }
    if (sugar % SUGAR_MULTIPLES != 0)
    {
      game.output(ERROR_SUGAR);
      return Command::EXECUTION_RESULT_NO_SUCCESS;
    }
    game.setRecipeLemon(lemon);
    game.setRecipeSugar(sugar);
    game.setRecipeWater(water);
  }
  std::ostringstream out;
  out << "L: " << game.getRecipeLemon() << "%\n";
  out << "S: " << game.getRecipeSugar() << "%\n";
  out << "W: " << game.getRecipeWater() << "%\n";
  game.output(out.str());
  return Command::EXECUTION_RESULT_SUCCESS;
}
