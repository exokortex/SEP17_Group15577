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
const string CommandRecipe::ERROR_SUM = "[ERR] The sum of parts must be 100.\n";

CommandRecipe::CommandRecipe() :
    Command(NAME)
{
}

//------------------------------------------------------------------------------
int CommandRecipe::execute(GameHandler& game, vector<string>& params)
{
  if (params.size() != PARAMETER_COUNT)
  {
    game.output(USAGE_STRING);
    return Command::EXECUTION_RESULT_NO_SUCCESS;
  }
  int numbers[PARAMETER_COUNT];
  for (int i = 0; i < PARAMETER_COUNT; i++)
  {
    if (!StringUtil::strictParseInt(params[i], &(numbers[i])) || numbers[i] < 0)
    {
      // if param is not strictly a number or lower zero
      game.output(USAGE_STRING);
      return Command::EXECUTION_RESULT_NO_SUCCESS;
    }
  }
  if (numbers[0] + numbers[1] + numbers[2] != EXPECTED_SUM)
  {
    game.output(ERROR_SUM);
    return Command::EXECUTION_RESULT_NO_SUCCESS;
  }
  std::ostringstream out;
  out << "L: " << numbers[0] << "%\n";
  out << "S: " << numbers[1] << "%\n";
  out << "W: " << numbers[2] << "%\n";
  game.output(out.str());
  return Command::EXECUTION_RESULT_SUCCESS;
}
