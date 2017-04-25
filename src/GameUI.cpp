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
#include <algorithm>

#include "GameHandler.h"
#include "CommandQuit.h"
#include "CommandEcho.h"
#include "CommandQuote.h"
#include "CommandBalance.h"
#include "CommandRecipe.h"

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

vector<string> GameUI::split(const string& original, char separator)
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
void GameUI::run()
{
  string input_line;

  vector<Command*> commands =
  { new CommandEcho(), new CommandQuit(), new CommandBalance(),
      new CommandQuote(), new CommandRecipe() };
  vector<Command*>::iterator cmd;

  //command loop
  while (true)
  {
    //print prompt
    cout << CMD_PROMPT;

    //wait for and read command line
    if (!std::getline(cin, input_line))
    {
      // exit if reading went wrong (i.e. EOF)
      break;
    }

    //process input_line
    vector<string> params = split(input_line, ' ');
    string command = params[0];

    // transform command to lowercase to be case insensitive
    std::transform(command.begin(), command.end(), command.begin(), ::tolower);

    // remove first element (the command name) from vector
    params.erase(params.begin());

    // find and execute the correct command
    for (cmd = commands.begin(); cmd != commands.end(); cmd++)
    {
      if ((*cmd)->getName() == command)
      {
        int result = (*cmd)->execute(*handler_, params);
        // terminate if requested
        if (result == Command::EXECUTION_RESULT_REQUEST_TERMINATION)
        {
          // delete Command objects
          for (unsigned int idx = 0; idx < commands.size(); idx++)
          {
            delete commands[idx];
          }
          return;
        }
        break;
      }
    }
  }
}

//------------------------------------------------------------------------------
void GameUI::output(string output)
{
  cout << output;
}
