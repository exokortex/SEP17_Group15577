//------------------------------------------------------------------------------
// Command.cpp
//
// Group: Group 15577, study assistant Roman Walch
//
// Authors: Johannes Haring 1611655
//          Thomas Moder 1615103
//          Verena Buder 1312723
//------------------------------------------------------------------------------
//

#include "Command.h"


//------------------------------------------------------------------------------
Command::Command(string name, vector<string>* params)
{
  this->command_name_ = name;
  this->params_ = params;
}

//------------------------------------------------------------------------------
Command::~Command()
{
}

//------------------------------------------------------------------------------
const string &Command::getName() const
{
  return command_name_;
}

//------------------------------------------------------------------------------
const vector<string> *Command::getParams() const
{
  return params_;
}
