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

using std::string;

class GameUI;

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
    // Processes a given input command
    //
    int input(string command);

    //--------------------------------------------------------------------------
    // Forwards a given output to View
    //
    void output(string output);

    //--------------------------------------------------------------------------
    // Setter Methods
    //
    void setView(GameUI* view)
    {
      this->view_ = view;
    }

  private:
    //--------------------------------------------------------------------------
    // The hold instance of the games View
    //
    GameUI* view_ = NULL;
};

#endif /* GAMEHANDLER_H_INCLUDED */
