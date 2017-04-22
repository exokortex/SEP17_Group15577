//------------------------------------------------------------------------------
// GameGUI.h
//
// Group: Group 15577, study assistant Roman Walch
//
// Authors: Johannes Haring 1611655
//          Thomas Moder 1615103
//          Verena Buder 1312723
//------------------------------------------------------------------------------
//

#ifndef GAMEGUI_H_INCLUDED
#define GAMEGUI_H_INCLUDED

#include <string>

using std::string;

class GameHandler;

//------------------------------------------------------------------------------
// class GameGUI
// The UI (View) class for the game
//
class GameGUI
{
  public:
    //--------------------------------------------------------------------------
    // Constructor
    //
    GameGUI();

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

#endif /* GAMEGUI_H_INCLUDED */
