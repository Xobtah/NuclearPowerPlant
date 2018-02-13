//
// IModule.hpp for IModule in /home/xobtah/Projects/NuclearPowerPlant
//
// Made by xobtah
// Login   <xobtah@epitech.net>
//
// Started on  Tue Jan 23 09:25:53 2018 xobtah
// Last update Wed Jan 24 16:55:47 2018 xobtah
//

#ifndef IMODULE_HPP_
#define IMODULE_HPP_

#include <string>
#include <vector>
#include <exception>

#include "ReactorCoolantCircuit.hpp"

namespace	NuclearPowerPlant
{
  class IModule
  {
  public:
    IModule() : _damage(0) {}
    virtual ~IModule() {}

    virtual void	update(double) = 0;

    bool	addToCoolantCircuit(ReactorCoolantCircuit *wc)
    {
      std::vector<ReactorCoolantCircuit*>::iterator it;

      for (it = _reactorCoolantCircuits.begin(); it != _reactorCoolantCircuits.end(); it++)
	if (*it == wc)
	  return (false);
      _reactorCoolantCircuits.push_back(wc);
      return (true);
    }

    /*bool	removeReactorCoolantCircuit(std::string id)
    {
      std::vector<ReactorCoolantCircuit*>::iterator it;

      for (it = _reactorCoolantCircuits.begin(); it != _reactorCoolantCircuits.end(); it++)
	if (*it == wc)
	  return (false);
	  }*/

  protected:
    char _damage;
    std::vector<ReactorCoolantCircuit*> _reactorCoolantCircuits;
  };
}

#endif
