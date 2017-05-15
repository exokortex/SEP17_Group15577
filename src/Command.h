//------------------------------------------------------------------------------
// Command.h
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

using std::string;
using std::vector;

class GameHandler;

class Command
{
  private:
    //--------------------------------------------------------------------------
    // Private copy constructor
    //
    Command(const Command& original);

    //--------------------------------------------------------------------------
    // Private assignment operator
    //
    Command& operator=(const Command& original);

    //--------------------------------------------------------------------------
    // Name of this command
    //
    string command_name_;

  public:
    static const int EXECUTION_RESULT_REQUEST_TERMINATION = -1;
    static const int EXECUTION_RESULT_SUCCESS = 0;
    static const int EXECUTION_RESULT_NO_SUCCESS = 1;

    //--------------------------------------------------------------------------
    // Constructor
    //
    Command(string name);

    //--------------------------------------------------------------------------
    // Destructor
    //
    virtual ~Command();

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
    virtual int execute(GameHandler& game, vector<string>& params) = 0;

    //--------------------------------------------------------------------------
    // Getter Methods
    //
    inline string& getName() const
    {
      return command_name_;
    }
};

#endif //COMMAND_H_INCLUDED
