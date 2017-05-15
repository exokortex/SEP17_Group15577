//------------------------------------------------------------------------------
// CommandSetweather.h
//
// Group: Group 15577, study assistant Roman Walch
//
// Authors: Johannes Haring 1611655
//          Thomas Moder 1615103
//          Verena Buder 1312723
//------------------------------------------------------------------------------
//

#ifndef COMMAND_SETWEATHER_H_INCLUDED
#define COMMAND_SETWEATHER_H_INCLUDED

#include "Command.h"

class GameHandler;

class CommandSetweather : public Command
{
  private:
    //--------------------------------------------------------------------------
    // number of parameters
    //
    static const int PARAMETER_COUNT = 4;

    //--------------------------------------------------------------------------
    // name of the command
    //
    static const string NAME;

    //--------------------------------------------------------------------------
    // usage string
    //
    static const string USAGE_STRING;

    //--------------------------------------------------------------------------
    // error string for wrong params
    //
    static const string ERROR_PARAM;

    //--------------------------------------------------------------------------
    // the sum of all arguments
    //
    static const int EXPECTED_SUM = 100;

  public:
    //--------------------------------------------------------------------------
    // Constructor
    //
    CommandSetweather();

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

#endif //COMMAND_SETWEATHER_H_INCLUDED
