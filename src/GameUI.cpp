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
GameUI::GameUI()
{
  writer_balance_ = std::unique_ptr<HTMLWriterBalance>(
      new HTMLWriterBalance("Balance.html"));
  writer_environment_ = std::unique_ptr<HTMLWriterEnvironment>(
      new HTMLWriterEnvironment("Environment.html"));
}

//------------------------------------------------------------------------------
void GameUI::output(string output)
{
  cout << output;
}

//------------------------------------------------------------------------------
void GameUI::ouputBalance(int lemon, int sugar, int cash, int balance)
{
  writer_balance_->writeFile(lemon, sugar, cash, balance);
}

//------------------------------------------------------------------------------
void GameUI::ouputEnvironment(EnvironmentalCondition& ec)
{
  writer_environment_->writeFile(ec);
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
