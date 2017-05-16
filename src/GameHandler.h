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
#include <memory>
#include <vector>

#include "EnvironmentalEngine.h"
#include "EnvironmentalCondition.h"
#include "Command.h"

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

    //--------------------------------------------------------------------------
    // Update the balance html file
    //
    void viewUpdateBalance();

    //--------------------------------------------------------------------------
    // Update the environment htm lfile
    //
    void viewUpdateEnvironment();

    //--------------------------------------------------------------------------
    // Getters and Setters
    //
    void setNextWeather(std::unique_ptr<EnvironmentalCondition> next_weather);

    inline int getBalance() const
    {
      return balance_;
    }

    inline void setBalance(int balance)
    {
      balance_ = balance;
    }

    inline int getExpence() const
    {
      return expence_;
    }

    inline void setExpence(int expence)
    {
      expence_ = expence;
    }

    inline int getIncome() const
    {
      return income_;
    }

    inline void setIncome(int income)
    {
      income_ = income;
    }

    inline int getPriceLemon() const
    {
      return price_lemon_;
    }

    inline void setPriceLemon(int priceLemon)
    {
      price_lemon_ = priceLemon;
    }

    inline int getPriceLemonade() const
    {
      return price_lemonade_;
    }

    inline void setPriceLemonade(int priceLemonade)
    {
      price_lemonade_ = priceLemonade;
    }

    inline int getPriceSugar() const
    {
      return price_sugar_;
    }

    inline void setPriceSugar(int priceSugar)
    {
      price_sugar_ = priceSugar;
    }

    inline int getRecipeLemon() const
    {
      return recipe_lemon_;
    }

    inline void setRecipeLemon(int recipeLemon)
    {
      recipe_lemon_ = recipeLemon;
    }

    inline int getRecipeSugar() const
    {
      return recipe_sugar_;
    }

    inline void setRecipeSugar(int recipeSugar)
    {
      recipe_sugar_ = recipeSugar;
    }

    inline int getRecipeWater() const
    {
      return recipe_water_;
    }

    inline void setRecipeWater(int recipeWater)
    {
      recipe_water_ = recipeWater;
    }

    inline int getStockCash() const
    {
      return stock_cash_;
    }

    inline void setStockCash(int stockCash)
    {
      stock_cash_ = stockCash;
    }

    inline int getStockLemon() const
    {
      return stock_lemon_;
    }

    inline void setStockLemon(int stockLemon)
    {
      stock_lemon_ = stockLemon;
    }

    inline int getStockSugar() const
    {
      return stock_sugar_;
    }

    inline void setStockSugar(int stockSugar)
    {
      stock_sugar_ = stockSugar;
    }

  private:
    //--------------------------------------------------------------------------
    // The base lemonade sugar
    //
    static const int BASE_SUGAR = 6;

    //--------------------------------------------------------------------------
    // The base lemonade lemon
    //
    static const int BASE_LEMON = 6;

    //--------------------------------------------------------------------------
    // The base lemonade water
    //
    static const int BASE_WATER = 88;

    //--------------------------------------------------------------------------
    // The hold instance of the games View
    //
    std::unique_ptr<GameUI> view_;

    //--------------------------------------------------------------------------
    // The recipe lemon
    //
    int recipe_lemon_ = BASE_LEMON;

    //--------------------------------------------------------------------------
    // The recipe sugar
    //
    int recipe_sugar_ = BASE_SUGAR;

    //--------------------------------------------------------------------------
    // The recipe water
    //
    int recipe_water_ = BASE_WATER;

    //--------------------------------------------------------------------------
    // The stock sugar
    //
    int stock_sugar_;

    //--------------------------------------------------------------------------
    // The stock lemon
    //
    int stock_lemon_;

    //--------------------------------------------------------------------------
    // The current cash
    //
    int stock_cash_;

    //--------------------------------------------------------------------------
    // The income
    //
    int income_;

    //--------------------------------------------------------------------------
    // The expence
    //
    int expence_;

    //--------------------------------------------------------------------------
    // The balance of the last round
    //
    int balance_;

    //--------------------------------------------------------------------------
    // Price of one lemonade
    //
    int price_lemonade_;

    //--------------------------------------------------------------------------
    // The of one unit of lemon
    //
    int price_lemon_;

    //--------------------------------------------------------------------------
    // Price of one unit of sugar
    //
    int price_sugar_;

    //--------------------------------------------------------------------------
    // The weather engine
    //
    std::unique_ptr<EnvironmentalEngine> weather_engine_;

    //--------------------------------------------------------------------------
    // The next weather
    //
    std::unique_ptr<EnvironmentalCondition> next_weather_;

    //--------------------------------------------------------------------------
    // The vector of valid commands
    //
    vector<std::unique_ptr<Command>> commands_;

    //--------------------------------------------------------------------------
    // Private copy constructor
    //
    GameHandler(const GameHandler& original) = delete;

    //--------------------------------------------------------------------------
    // Private assignment operator
    //
    GameHandler& operator=(const GameHandler& original) = delete;
};

#endif /* GAMEHANDLER_H_INCLUDED */
