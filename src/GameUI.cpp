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
#include "CommandQuit.h"

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
    if (!std::getline(cin, input_line))
    {
      // exit if reading went wrong (i.e. EOF)
      break;
    }

    //process input line
    vector<string> c(0);
    CommandQuit* cmd = new CommandQuit(&c);
    this->handler_->command(cmd);
  }
}

//------------------------------------------------------------------------------
void GameUI::output(string output)
{
  cout << output;
}
