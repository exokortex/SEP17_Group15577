//------------------------------------------------------------------------------
// GameHandler.h
//
// Group: Group 15577, study assistant Roman Walch
//
// Authors: Johannes Haring 1611655
//          Thomas Moder 1615103
//          Verena Buder 1312723
//------------------------------------------------------------------------------
//

#ifndef GAMEHANDLER_H_INCLUDED
#define GAMEHANDLER_H_INCLUDED

#include <string>
#include <algorithm>

#include "CommandQuit.h"
#include "CommandEcho.h"
#include "CommandQuote.h"
#include "CommandBalance.h"
#include "CommandRecipe.h"

using std::string;
using std::vector;

class GameUI;
class Command;

//------------------------------------------------------------------------------
// class GameHandler
// The Controller class for the game
//
class GameHandler
{
  public:
    //--------------------------------------------------------------------------
    // Constructor
    //
    GameHandler();

    //--------------------------------------------------------------------------
    // Forwards a given output to View
    //
    void output(string output);

    //--------------------------------------------------------------------------
    // Setter Methods
    //
    inline void setView(GameUI* view)
    {
      this->view_ = view;
    }

    //--------------------------------------------------------------------------
    // Runs the game
    //
    void run();

  private:
    //--------------------------------------------------------------------------
    // The hold instance of the games View
    //
    GameUI* view_ = NULL;

    //--------------------------------------------------------------------------
    // stringsplit into vecor of string
    //
    vector<string> split(const string& original, char separator);
};

#endif /* GAMEHANDLER_H_INCLUDED */
