//
// Operator.hpp for Operator in /home/xobtah/Projects/NuclearPowerPlant
//
// Made by xobtah
// Login   <xobtah@epitech.net>
//
// Started on  Tue Jan 23 13:23:11 2018 xobtah
// Last update Tue Jan 23 14:50:56 2018 xobtah
//

#ifndef OPERATOR_HPP_
#define OPERATOR_HPP_

#include <string>
#include <map>
#include <exception>

#include "NuclearReactor.hpp"

namespace	NuclearPowerPlant
{
  class Operator
  {
  public:
    Operator(NuclearReactor&);
    virtual ~Operator();

    std::string	execute(const std::string&);

  private:
    NuclearReactor	&_nr;

    std::vector<std::string>	parseCmd(const std::string&);
    std::map<std::string, std::string (Operator::*)(const std::string&)>	_instructionList;

    std::string	newModule(const std::string&);
  };
}

#endif
