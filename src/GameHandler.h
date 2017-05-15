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
#include <memory>

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
    void setView(std::unique_ptr<GameUI> view);

    //--------------------------------------------------------------------------
    // Runs the game
    //
    void run();

  private:
    static const int BASE_SUGAR = 6;
    static const int BASE_LEMON = 6;
    static const int BASE_WATERW = 88;
    //--------------------------------------------------------------------------
    // The hold instance of the games View
    //
    std::unique_ptr<GameUI> view_;

    //--------------------------------------------------------------------------
    // stringsplit into vecor of string
    //
    vector<string> split(const string& original, char separator);

    int recipeSugar_;
    int recipeLemon_;
    int recipeWater_;

    int stockSugar_;
    int stockLemon_;
    int cache_;

};

#endif /* GAMEHANDLER_H_INCLUDED */
