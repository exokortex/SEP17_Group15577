//------------------------------------------------------------------------------
// GameUI.cpp
//
// Group: Group 15577, study assistant Roman Walch
//
// Authors: Johannes Haring 1611655
//          Thomas Moder 1615103
//          Verena Buder 1312723
//------------------------------------------------------------------------------
//

#include "GameUI.h"

#include <iostream>
#include <string>

#include "GameHandler.h"

using std::cout;
using std::cin;
using std::string;

const string CMD_PROMPT = "sep> ";

//------------------------------------------------------------------------------
GameUI::GameUI(GameHandler* handler)
{
  //create game handler and set this instance as View
  this->handler_ = handler;
}

//------------------------------------------------------------------------------
void GameUI::run()
{
  string input_line;

  //command loop
  while(true)
  {
    //print prompt
    cout << CMD_PROMPT;

    //wait for and read command line
    std::getline(cin, input_line);

    //process input line
    this->handler_->input(input_line);
  }
}

//------------------------------------------------------------------------------
void GameUI::output(string output)
{
  cout << output;
}
