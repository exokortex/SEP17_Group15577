//------------------------------------------------------------------------------
// GameHandler.cpp
//
// Group: Group 15577, study assistant Roman Walch
//
// Authors: Johannes Haring 1611655
//          Thomas Moder 1615103
//          Verena Buder 1312723
//------------------------------------------------------------------------------
//

#include <stdlib.h>
#include <algorithm>
#include <memory>

#include "GameHandler.h"
#include "GameUI.h"
#include "Command.h"
#include "StringUtil.h"

#include "CommandQuit.h"
#include "CommandEcho.h"
#include "CommandQuote.h"
#include "CommandBalance.h"
#include "CommandRecipe.h"
#include "CommandSetweather.h"
#include "CommandBuy.h"
#include "CommandPlay.h"

//------------------------------------------------------------------------------
GameHandler::GameHandler(int price_lemonade, int price_lemon, int price_sugar) :
    price_lemonade_(price_lemonade), price_lemon_(price_lemon), price_sugar_(
        price_sugar)
{
  commands_.push_back(std::unique_ptr<Command>(new CommandEcho()));
  commands_.push_back(std::unique_ptr<Command>(new CommandQuit()));
  commands_.push_back(std::unique_ptr<Command>(new CommandBalance()));
  commands_.push_back(std::unique_ptr<Command>(new CommandQuote()));
  commands_.push_back(std::unique_ptr<Command>(new CommandRecipe()));
  commands_.push_back(std::unique_ptr<Command>(new CommandSetweather()));
  commands_.push_back(std::unique_ptr<Command>(new CommandBuy()));
  commands_.push_back(std::unique_ptr<Command>(new CommandPlay()));

  weather_engine_ = std::unique_ptr<EnvironmentalEngine>(
      new EnvironmentalEngine());
  current_weather_ = weather_engine_->createCondition();
  next_weather_ = weather_engine_->createCondition();
}

//------------------------------------------------------------------------------
void GameHandler::setView(std::unique_ptr<GameUI> view)
{
  this->view_ = std::move(view);
}

void GameHandler::setNextWeather(
    std::unique_ptr<EnvironmentalCondition> next_weather)
{
  next_weather_ = std::move(next_weather);
}

//------------------------------------------------------------------------------
void GameHandler::output(string output)
{
  view_->output(output);
}

//------------------------------------------------------------------------------
void GameHandler::run()
{
  string input_line;

  vector<std::unique_ptr<Command>>::iterator cmd;

  //command loop
  while (true)
  {
    input_line = view_->nextUserCommand();

    //process input_line
    vector<string> params = StringUtil::split(input_line, ' ');

    // ignore empty lines
    if (params.size() == 0)
      continue;

    string command = params[0];

    // transform command to lowercase to be case insensitive
    std::transform(command.begin(), command.end(), command.begin(), ::tolower);

    // remove first element (the command name) from vector
    params.erase(params.begin());

    // find and execute the correct command
    for (cmd = commands_.begin(); cmd != commands_.end(); cmd++)
    {
      if ((*cmd)->getName() == command)
      {
        int result = (*cmd)->execute(*this, params);
        // terminate if requested
        if (result == Command::EXECUTION_RESULT_REQUEST_TERMINATION)
        {
          return;
        }
        break;
      }
    }
    // display error if command is unknown
    if (cmd == commands_.end())
      view_->output("[ERR] Unknown command.\n");
  }
}

//------------------------------------------------------------------------------
void GameHandler::play()
{
  //limonade

  int sell_factor = 100; //%

  if (current_weather_->isItHot())
  {
    //hot weather
    if (recipe_sugar_ < BASE_SUGAR)
      sell_factor += 20;
    else if (recipe_sugar_ > BASE_SUGAR)
      sell_factor -= 20;
    if (recipe_lemon_ > BASE_LEMON)
      sell_factor += 20;
  }
  else if (current_weather_->isItCold())
  {
    //cold weather
    if (recipe_sugar_ > BASE_SUGAR)
      sell_factor += 20;
    else if (recipe_sugar_ < BASE_SUGAR)
      sell_factor -= 20;
    if (recipe_lemon_ > BASE_LEMON)
      sell_factor -= 20;
  }
  //general factors
  if (recipe_sugar_ > 20)
    sell_factor -= 100;
  else if (recipe_sugar_ > 15)
    sell_factor -= 50;
  if (recipe_lemon_ > 18)
    sell_factor -= 100;
  else if (recipe_lemon_ > 12)
    sell_factor -= 50;
  if (recipe_water_ > 98)
    sell_factor -= 100;
  else if (recipe_water_ > 95)
    sell_factor -= 50;

  sell_factor = std::max(sell_factor, -100);

  //customers

  int customers = 500;

  if (current_weather_->isItHot())
    customers *= 1.5;
  else if (current_weather_->getSkyCover() == EnvironmentalCondition::OVERCAST)
    customers *= 0.8;
  else if (current_weather_->isItStormy())
    customers *= 0.1;
  else if (current_weather_->isItRainy())
    customers *= 0.5;

  //consumption

  //take # of customers or cache, whichever is lower
  int consumption = std::min(customers, stock_cash_);
  //find next |4 value for consumption
  while (consumption % 4 != 0)
    consumption++;

  //reduce cache
  stock_cash_ -= consumption;

  //calc new income, expence and balance members
  income_ = consumption * price_lemonade_;
  expence_ = 0; //TODO!!!!!
  balance_ = income_ - expence_;

  viewUpdateBalance();
  viewUpdateEnvironment();
  next_weather_ = weather_engine_->createCondition();
}

void GameHandler::viewUpdateBalance()
{
  view_->ouputBalance(stock_lemon_, stock_sugar_, stock_cash_, balance_);
}

void GameHandler::viewUpdateEnvironment()
{
  view_->ouputEnvironment(*next_weather_);
}

