//
// Operator.cpp for Operator in /home/xobtah/Projects/NuclearPowerPlant
//
// Made by xobtah
// Login   <xobtah@epitech.net>
//
// Started on  Tue Jan 23 13:23:53 2018 xobtah
// Last update Tue Jan 23 14:56:13 2018 xobtah
//

#include <locale>

#include "Operator.hpp"

namespace	NuclearPowerPlant
{
  /*
  **	Ctor & Dtor
  */

  Operator::Operator(NuclearReactor &nr) : _nr(nr)
  {
    _instructionList["NEW"] = &Operator::newModule;
  }

  Operator::~Operator() {}

  /*
  **	Public member functions
  */

  std::string	Operator::execute(const std::string &cmd)
  {
    std::vector<std::string>	cmdTab;

    if (!cmd.length())
      return ("");
    /*for (std::string::size_type i = 0; i < cmd.length(); i++)
      cmd[i] = std::toupper(cmd[i]);*/
    cmdTab = this->parseCmd(cmd);
    if (_instructionList[cmdTab[0]])
      return ((this->*_instructionList[0])(cmdTab[1]));
    return ("Unknown command " + cmdTab[0]);
  }

  /*
  **	Private member functions
  */

  std::vector<std::string>	Operator::parseCmd(const std::string &cmd)
  {
    std::string			s = cmd;
    std::vector<std::string>	cmdTab;
    size_t			pos = 0;
    std::string			token;

    while ((pos = s.find(" ")) != std::string::npos)
      {
	cmdTab.push_back(s.substr(0, pos));
	s.erase(0, pos + 1);
      }
    cmdTab.push_back(s);
    return (cmdTab);
  }

  std::string	Operator::newModule(const std::string &cmd)
  {
    return (cmd);
  }
}
