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

using std::string;

class GameHandler;

//------------------------------------------------------------------------------
// class GameUI
// The UI (View) class for the game
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
    // Getter Methods
    //
    GameHandler* getHandler() const
    {
      return handler_;
    }

  private:
    //--------------------------------------------------------------------------
    // The hold instance of the GameHandler
    //
    GameHandler* handler_;
};

#endif /* GAMEUI_H_INCLUDED */
