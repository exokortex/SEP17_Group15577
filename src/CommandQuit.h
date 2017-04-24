//------------------------------------------------------------------------------
// CommandQuit.h
//
// Group: Group 15577, study assistant Roman Walch
//
// Authors: Johannes Haring 1611655
//          Thomas Moder 1615103
//          Verena Buder 1312723
//------------------------------------------------------------------------------
//

#ifndef COMMAND_QUIT_H_INCLUDED
#define COMMAND_QUIT_H_INCLUDED

#include <string>
#include <vector>

#include "Command.h"

using std::string;
using std::vector;

class GameHandler;

class CommandQuit : public Command
{
  private:
    //--------------------------------------------------------------------------
    // name of the command
    //
    static const string NAME;

    //--------------------------------------------------------------------------
    // the quit message
    //
    static const string MESSAGE;

  public:
    //--------------------------------------------------------------------------
    // Constructor
    //
    CommandQuit();

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

#endif //COMMAND_QUIT_H_INCLUDED
