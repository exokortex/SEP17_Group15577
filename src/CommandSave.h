//------------------------------------------------------------------------------
// CommandSave.h
//
// Group: Group 15577, study assistant Roman Walch
//
// Authors: Johannes Haring 1611655
//          Thomas Moder 1615103
//          Verena Buder 1312723
//------------------------------------------------------------------------------
//

#ifndef COMMAND_SAVE_H_INCLUDED
#define COMMAND_SAVE_H_INCLUDED

#include "Command.h"

class GameHandler;

//------------------------------------------------------------------------------
// class CommandSave
// the save command
//
class CommandSave : public Command
{
  private:
    //--------------------------------------------------------------------------
    // number of parameters
    //
    static const int PARAMETER_COUNT = 1;

    //--------------------------------------------------------------------------
    // name of the command
    //
    static const string NAME;

    //--------------------------------------------------------------------------
    // usage string
    //
    static const string USAGE_STRING;

    //--------------------------------------------------------------------------
    // error string for file could not be opened
    //
    static const string ERROR_FILE_NOT_OPEN;

    //--------------------------------------------------------------------------
    // Private copy constructor
    //
    CommandSave(const CommandSave& original) = delete;

    //--------------------------------------------------------------------------
    // Private assignment operator
    //
    CommandSave& operator=(const CommandSave& original) = delete;

  public:
    //--------------------------------------------------------------------------
    // Constructor
    //
    CommandSave();

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

#endif //COMMAND_SAVE_H_INCLUDED
