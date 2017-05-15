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

#include "EnvironmentalEngine.h"
#include "EnvironmentalCondition.h"

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
    GameHandler(int price_lemonade, int price_lemon, int price_sugar);

    //--------------------------------------------------------------------------
    // Forwards a given output to View
    //
    void output(string output);

    //--------------------------------------------------------------------------
    // Setter Methods
    //
    void setView(std::unique_ptr<GameUI> view);

    //--------------------------------------------------------------------------
    // Runs the game loop
    //
    void run();

    //--------------------------------------------------------------------------
    // Executes one round of the game
    //
    void play();

  private:
    static const int BASE_SUGAR = 6;
    static const int BASE_LEMON = 6;
    static const int BASE_WATERW = 88;
    //--------------------------------------------------------------------------
    // The hold instance of the games View
    //
    std::unique_ptr<GameUI> view_;

    int recipeSugar_;
    int recipeLemon_;
    int recipeWater_;

    int stockSugar_;
    int stockLemon_;
    int cache_;

    int price_lemonade_;
    int price_lemon_;
    int price_sugar_;

    int income_;
    int expence_;
    int balance_;

    EnvironmentalEngine* wheather_engine;
    EnvironmentalCondition* current_weather;
    EnvironmentalCondition* next_weather;


    vector<std::unique_ptr<Command>> commands_;

    //--------------------------------------------------------------------------
    // stringsplit into vecor of string
    //
    vector<string> split(const string& original, char separator);

};

#endif /* GAMEHANDLER_H_INCLUDED */
