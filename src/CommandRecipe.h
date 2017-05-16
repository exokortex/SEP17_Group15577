//------------------------------------------------------------------------------
// CommandRecipe.h
//
// Group: Group 15577, study assistant Roman Walch
//
// Authors: Johannes Haring 1611655
//          Thomas Moder 1615103
//          Verena Buder 1312723
//------------------------------------------------------------------------------
//

#ifndef COMMAND_RECIPE_H_INCLUDED
#define COMMAND_RECIPE_H_INCLUDED

#include "Command.h"

class GameHandler;

//------------------------------------------------------------------------------
// class CommandRecipe
// the recipe command
//
class CommandRecipe : public Command
{
  private:
    //--------------------------------------------------------------------------
    // number of parameters
    //
    static const int PARAMETER_COUNT = 3;

    //--------------------------------------------------------------------------
    // lemon must be multiple of this
    //
    static const int LEMON_MULTIPLES = 3;

    //--------------------------------------------------------------------------
    // sugar must be multiple of this
    //
    //
    static const int SUGAR_MULTIPLES = 2;

    //--------------------------------------------------------------------------
    // name of the command
    //
    static const string NAME;

    //--------------------------------------------------------------------------
    // usage string
    //
    static const string USAGE_STRING;

    //--------------------------------------------------------------------------
    // error string for wrong parameters
    //
    static const string ERROR_WRONG_PARAM;

    //--------------------------------------------------------------------------
    // error string for wrong sum
    //
    static const string ERROR_SUM;

    //--------------------------------------------------------------------------
    // error string for wrong lemon
    //
    static const string ERROR_LEMON;

    //--------------------------------------------------------------------------
    // error string for wrong sugar
    //
    static const string ERROR_SUGAR;

    //--------------------------------------------------------------------------
    // the sum of all arguments
    //
    static const int EXPECTED_SUM = 100;

  public:
    //--------------------------------------------------------------------------
    // Constructor
    //
    CommandRecipe();

    //--------------------------------------------------------------------------
    // Executes the command.
    // @param game The game where action should be performed on
    // @param params Possible parameters neede for the execution
    // @return Integer representing the success of the action
    //         0 for normal execution
    //         -1 for a request to stop the program
    //         positive numbers: unsuccessful
    //         see Command::EXECUTION_RESULT_* for all options
    //
    virtual int execute(GameHandler& game, vector<string>& params);
};

#endif //COMMAND_RECIPE_H_INCLUDED
