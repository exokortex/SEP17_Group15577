//------------------------------------------------------------------------------
// GameUI.h
//
// Group: Group 15577, study assistant Roman Walch
//
// Authors: Johannes Haring 1611655
//          Thomas Moder 1615103
//          Verena Buder 1312723
//------------------------------------------------------------------------------
//

#ifndef GAMEUI_H_INCLUDED
#define GAMEUI_H_INCLUDED

#include <string>
#include <vector>
#include <memory>

#include "HTMLWriterBalance.h"
#include "HTMLWriterEnvironment.h"

using std::string;
using std::vector;

class GameHandler;

//------------------------------------------------------------------------------
// class GameUI
// The View class for the game
//
class GameUI
{
  public:
    //--------------------------------------------------------------------------
    // Constructor
    //
    GameUI();

    //--------------------------------------------------------------------------
    // Prints a given output
    //
    void output(string output);

    //--------------------------------------------------------------------------
    // Writes the balance file
    //
    void ouputBalance(int lemon, int sugar, int cash, int delta);

    //--------------------------------------------------------------------------
    // Writes the balance file
    //
    void ouputEnvironment(EnvironmentalCondition& ec);

    //--------------------------------------------------------------------------
    // Reads a new command
    //
    string nextUserCommand();

  private:
    //--------------------------------------------------------------------------
    // the command prompt
    //
    static const string CMD_PROMPT;

    std::unique_ptr<HTMLWriterBalance> writer_balance_;
    std::unique_ptr<HTMLWriterEnvironment> writer_environment_;

    //--------------------------------------------------------------------------
    // Private copy constructor
    //
    GameUI(const GameUI& original) = delete;

    //--------------------------------------------------------------------------
    // Private assignment operator
    //
    GameUI& operator=(const GameUI& original) = delete;
};

#endif /* GAMEUI_H_INCLUDED */
