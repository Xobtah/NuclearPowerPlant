//
// NuclearCore.cpp for NuclearReactor in /home/xobtah/Projects/NuclearPowerPlant
//
// Made by xobtah
// Login   <xobtah@epitech.net>
//
// Started on  Tue Jan 23 09:47:38 2018 xobtah
// Last update Wed Jan 24 17:08:57 2018 xobtah
//

#include <algorithm>

#include "NuclearReactor.hpp"

namespace	NuclearPowerPlant
{
  /*
  **	Ctor & Dtor
  */

  NuclearReactor::NuclearReactor() {}

  NuclearReactor::NuclearReactor(const NuclearReactor &old)
  {
    (void) old;
  }

  NuclearReactor	&NuclearReactor::operator=(const NuclearReactor &old)
  {
    if (&old != this)
      {
	
      }
    return (*this);
  }

  NuclearReactor::~NuclearReactor()
  {
    std::for_each(_nppReactorCoolantPumps.begin(), _nppReactorCoolantPumps.end(),
		  [](ReactorCoolantPump *rcp) { delete rcp; });
    std::for_each(_nppReactorCoolantCircuits.begin(), _nppReactorCoolantCircuits.end(),
		  [](ReactorCoolantCircuit *rcc) { delete rcc; });
    std::for_each(_nppReactorCores.begin(), _nppReactorCores.end(),
		  [](ReactorCore *rc) { delete rc; });
  }

  /*
  **	Public member functions
  */

  void	NuclearReactor::update(double delta)
  {
    std::for_each(_nppReactorCores.begin(), _nppReactorCores.end(),
		  [&delta](ReactorCore *rc) { rc->update(delta); });
    std::for_each(_nppReactorCoolantPumps.begin(), _nppReactorCoolantPumps.end(),
		  [&delta](ReactorCoolantPump *rcp) { rcp->update(delta); });
    /*std::map<std::string, IModule*>::iterator it;

    for (it = _modules.begin(); it != _modules.end(); it++)
    it->second->update();*/
  }

  ReactorCoolantCircuit	*NuclearReactor::newReactorCoolantCircuit()
  {
    _nppReactorCoolantCircuits.push_back(new ReactorCoolantCircuit());
    return (_nppReactorCoolantCircuits.back());
  }

  ReactorCore	*NuclearReactor::newReactorCore()
  {
    _nppReactorCores.push_back(new ReactorCore());
    return (_nppReactorCores.back());
  }

  ReactorCoolantPump	*NuclearReactor::newReactorCoolantPump()
  {
    _nppReactorCoolantPumps.push_back(new ReactorCoolantPump());
    return (_nppReactorCoolantPumps.back());
  }

  ReactorCoolantCircuit	*NuclearReactor::reactorCoolantCircuit(int id)
  { return (_nppReactorCoolantCircuits[id]); }

  ReactorCore	*NuclearReactor::reactorCore(int id) { return (_nppReactorCores[id]); }

  ReactorCoolantPump	*NuclearReactor::reactorCoolantPump(int id)
  { return (_nppReactorCoolantPumps[id]); }
}
