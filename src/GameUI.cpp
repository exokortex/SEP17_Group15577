#include "GameUI.h"

#include <iostream>
#include <string>

#include "GameHandler.h"

using std::cout;
using std::cin;
using std::string;

const string CMD_PROMPT = "sep> ";

//------------------------------------------------------------------------------
GameUI::GameUI()
{
  //create game handler and set this instance as View
  this->handler_ = new GameHandler(this);
}

//------------------------------------------------------------------------------
void GameUI::output(string output)
{
  cout << output;
}

int main()
{
  string input_line;

  //create View (UI) object
  GameUI view = GameUI();

  //command loop
  while(true)
  {
    //print prompt
    cout << CMD_PROMPT;
    //wait for and read command line
    std::getline(cin, input_line);
    //forward input line to handler
    view.getHandler()->input(input_line);
  }

  return 0;
}
