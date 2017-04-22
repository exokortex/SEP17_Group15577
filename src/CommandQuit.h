//------------------------------------------------------------------------------
// CommandQuit.h
//
// Group: Group 15577, study assistant Roman Walch
//
// Authors: Johannes Haring 1611655
//          Thomas Moder 1615103
//          Verena Buder 1312723
//          Tutors
//------------------------------------------------------------------------------
//

#ifndef COMMAND_H_INCLUDED
#define COMMAND_H_INCLUDED

#include <string>
#include <vector>

#include "Command.h"

class GameHandler;

class CommandQuit : Command
{
  public:
    CommandQuit(vector<string>* params);

    //--------------------------------------------------------------------------
    // Validates the commands params.
    // @param game The game where action should be performed on
    // @param params Possible parameters neede for the execution
    // @return Integer representing if the command is valid

    int validate(GameHandler& game);

    //--------------------------------------------------------------------------
    // Executes the command.
    // @param game The game where action should be performed on
    // @param params Possible parameters neede for the execution
    // @return Integer representing the success of the action

    int execute(GameHandler& game);
};

#endif //COMMAND_H_INCLUDED
