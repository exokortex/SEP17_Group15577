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
// The handler (controller) class for the game
//
class GameHandler
{
  public:
    //--------------------------------------------------------------------------
    // Constructor
    // Creates an object and sets the games View
    //
    GameHandler(GameUI* view);

    //--------------------------------------------------------------------------
    // Processes a given input command
    //
    int input(string command);

    //--------------------------------------------------------------------------
    // Forwards a given output to View
    //
    void output(string output);

  private:
    //--------------------------------------------------------------------------
    // The hold instance of the games View
    //
    GameUI* view_;
};

#endif /* GAMEHANDLER_H_INCLUDED */
