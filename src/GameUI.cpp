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

const string GameUI::CMD_PROMPT = "sep> ";

//------------------------------------------------------------------------------
GameUI::GameUI(GameHandler* handler)
{
  //create game handler and set this instance as View
  this->handler_ = handler;
}

//------------------------------------------------------------------------------
void GameUI::output(string output)
{
  cout << output;
}


//------------------------------------------------------------------------------
string GameUI::nextUserCommand()
{
  string input_line;

  //print prompt
  cout << CMD_PROMPT;

  // TODO: propagate exception when reading fails to the GameHandler
  //wait for and read command line
  if (!std::getline(cin, input_line))
  {
    // exit if reading went wrong (i.e. EOF)
    return "quit";
  }
  return input_line;
}
