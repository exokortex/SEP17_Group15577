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
GameHandler::GameHandler()
{
  //nothing to do
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

  vector<Command*> commands =
  { new CommandEcho(), new CommandQuit(), new CommandBalance(),
      new CommandQuote(), new CommandRecipe() };
  vector<Command*>::iterator cmd;

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
    for (cmd = commands.begin(); cmd != commands.end(); cmd++)
    {
      if ((*cmd)->getName() == command)
      {
        int result = (*cmd)->execute(*this, params);
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
