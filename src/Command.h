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

class GameHandler;

class Command
{
  private:
    //--------------------------------------------------------------------------
    // Private copy constructor

    Command(const Command& original);

    //--------------------------------------------------------------------------
    // Private assignment operator

    Command& operator=(const Command& original);

    //--------------------------------------------------------------------------
    /// Name of this command
    std::string command_name_;

    //--------------------------------------------------------------------------
    /// User-input parameters
    std::vector<std::string>& input_params_;

  public:
    //--------------------------------------------------------------------------
    // Constructor

    Command(std::string name);

    //--------------------------------------------------------------------------
    // Destructor

    virtual ~Command();

    //--------------------------------------------------------------------------
    // Validates the commands params.
    // @param game The game where action should be performed on
    // @param params Possible parameters neede for the execution
    // @return Integer representing if the command is valid

    virtual int validate(GameHandler& game) = 0;

    //--------------------------------------------------------------------------
    // Executes the command.
    // @param game The game where action should be performed on
    // @param params Possible parameters neede for the execution
    // @return Integer representing the success of the action

    virtual int execute(GameHandler& game) = 0;

    //--------------------------------------------------------------------------
    // Getter Methods
    const std::string& getName() const;
    const std::string& getInputParams() const;
};

#endif //COMMAND_H_INCLUDED
