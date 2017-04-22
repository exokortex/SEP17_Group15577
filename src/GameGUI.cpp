#include <iostream>
#include <string>

#include "GameGUI.h"

using std::cout;
using std::cin;
using std::string;

const string CMD_PROMPT = "sep> ";

//------------------------------------------------------------------------------
GameGUI::GameGUI()
{
  //create game handler and set this instance as View
  this->handler_ = GameHandler(this);
}

//------------------------------------------------------------------------------
void GameHandler::output(string output)
{
  cout << output;
}

int main()
{
  string input_line;

  //create View (UI) object
  GameGUI view = GameGUI();

  //command loop
  while(true)
  {
    //print prompt
    cout << CMD_PROMPT;
    //wait for and read command line
    std::getline(cin, input_line);
    //forward input line to handler
    view.getHandler().input(input_line);
  }

  return 0;
}
