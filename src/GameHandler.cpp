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

#include "GameHandler.h"
#include "GameUI.h"
#include "Command.h"

//------------------------------------------------------------------------------
GameHandler::GameHandler(int price_lemonade, int price_lemon, int price_sugar) :
    price_lemonade_(price_lemonade), price_lemon_(price_lemon),
    price_sugar_(price_sugar)
{
  commands_.push_back(std::unique_ptr<Command>(new CommandEcho()));
  commands_.push_back(std::unique_ptr<Command>(new CommandQuit()));
  commands_.push_back(std::unique_ptr<Command>(new CommandBalance()));
  commands_.push_back(std::unique_ptr<Command>(new CommandQuote()));
  commands_.push_back(std::unique_ptr<Command>(new CommandRecipe()));

  wheather_engine = std::move(new EnvironmentalEngine());
}

void GameHandler::setView(std::unique_ptr<GameUI> view)
{
  this->view_ = std::move(view);
}

//------------------------------------------------------------------------------
void GameHandler::output(string output)
{
  view_->output(output);
}

//------------------------------------------------------------------------------
vector<string> GameHandler::split(const string& original, char separator)
{
  std::vector<std::string> results;
  std::string::const_iterator start = original.begin();
  std::string::const_iterator end = original.end();
  std::string::const_iterator next = std::find(start, end, separator);
  while (next != end)
  {
    // ignore empty parts
    if (start != next)
      results.push_back(std::string(start, next));
    start = next + 1;
    next = std::find(start, end, separator);
  }
  results.push_back(std::string(start, next));
  return results;
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
    vector<string> params = split(input_line, ' ');
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
    // TODO: maybe replace with command class
    if ((*cmd)->getName() == "play")
      play();
  }
}

//------------------------------------------------------------------------------
void GameHandler::play()
{
  //limonade

  int sell_factor = 100; //%

  if (current_weather->isItHot())
  {
    //hot weather
    if (recipe_sugar_ < BASE_SUGAR)
      sell_factor += 20;
    else if (recipe_sugar_ > BASE_SUGAR)
      sell_factor -= 20;
    if (recipe_lemon_ > BASE_LEMON)
      sell_factor += 20;
  }
  else if (current_weather->isItCold())
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

  if(current_weather->isItHot())
    customers *= 1.5;
  else if(current_weather->getSkyCover() == EnvironmentalCondition::OVERCAST)
    customers *= 0.8;
  else if(current_weather->isItStormy())
    customers *= 0.1;
  else if(current_weather->isItRainy())
    customers *= 0.5;

  //consumption

  //take # of customers or cache, whichever is lower
  int consumption = std::min(customers, cache_);
  //find next |4 value for consumption
  while(consumption % 4 != 0)
    consumption++;

  //reduce cache
  cache_ -= consumption;

  //calc new income, expence and balance members
  income_ = consumption * price_lemonade_;
  expence_ = 0; //TODO!!!!!
  balance_ = income_ - expence_;
}

