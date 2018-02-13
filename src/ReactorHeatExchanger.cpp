//
// ReactorHeatExchanger.cpp for ReactorHeatExchanger in /home/xobtah/Projects/NuclearPowerPlant/src
//
// Made by xobtah
// Login   <xobtah@epitech.net>
//
// Started on  Sun Jan 28 15:21:24 2018 xobtah
// Last update Sun Jan 28 15:25:25 2018 xobtah
//

#include "ReactorHeatExchanger.hpp"

namespace NuclearPowerPlant
{
  /*
  **	Ctor & Dtor
  */

  ReactorHeatExchanger::ReactorHeatExchanger() {}

  ReactorHeatExchanger::ReactorHeatExchanger(const ReactorHeatExchanger &old)
  {
    (void) old;
  }

  ReactorHeatExchanger &ReactorHeatExchanger::operator=(const ReactorHeatExchanger &old)
  {
    if (&old != this)
      {
	
      }
    return (*this);
  }

  ReactorHeatExchanger::~ReactorHeatExchanger() {}

  /*
  **	Public member functions
  */

  void ReactorHeatExchanger::update(double delta)
  {
    (void) delta;
  }
}
