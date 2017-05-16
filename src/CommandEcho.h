//------------------------------------------------------------------------------
// CommandEcho.h
//
// Group: Group 15577, study assistant Roman Walch
//
// Authors: Johannes Haring 1611655
//          Thomas Moder 1615103
//          Verena Buder 1312723
//------------------------------------------------------------------------------
//

#ifndef COMMAND_ECHO_H_INCLUDED
#define COMMAND_ECHO_H_INCLUDED

#include "Command.h"

class GameHandler;

//------------------------------------------------------------------------------
// class CommandEcho
// the echo command
//
class CommandEcho : public Command
{
  private:
    //--------------------------------------------------------------------------
    // name of the command
    //
    static const string NAME;

    //--------------------------------------------------------------------------
    // parameter seperator for output
    //
    static const string SEPERATOR;

    //--------------------------------------------------------------------------
    // last output string
    //
    static const string TERMINAL_STRING;

  public:
    //--------------------------------------------------------------------------
    // Constructor
    //
    CommandEcho();

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

#endif //COMMAND_ECHO_H_INCLUDED
