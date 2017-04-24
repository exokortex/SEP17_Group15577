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
    GameUI(GameHandler* handler);

    //--------------------------------------------------------------------------
    // Runs the UI process
    //
    void run();

    //--------------------------------------------------------------------------
    // Prints a given output
    //
    void output(string output);

    //--------------------------------------------------------------------------
    // Getter Methods
    //
    GameHandler* getHandler() const
    {
      return handler_;
    }

  private:
    //--------------------------------------------------------------------------
    // the command prompt
    //
    static const string CMD_PROMPT;

    //--------------------------------------------------------------------------
    // stringsplit into vecor of string
    //
    vector<string> split(const string& original, char separator);

    //--------------------------------------------------------------------------
    // The hold instance of the GameHandler
    //
    GameHandler* handler_;
};

#endif /* GAMEUI_H_INCLUDED */
