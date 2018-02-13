//
// NuclearReactor.hpp for NuclearReactor in /home/xobtah/Projects/NuclearPowerPlant
//
// Made by xobtah
// Login   <xobtah@epitech.net>
//
// Started on  Tue Jan 23 09:47:53 2018 xobtah
// Last update Wed Jan 24 15:09:23 2018 xobtah
//

#ifndef NUCLEARREACTOR_HPP_
#define NUCLEARREACTOR_HPP_

#include <map>
#include <exception>

#include "ReactorCoolantPump.hpp"
#include "ReactorCore.hpp"
#include "ReactorCoolantCircuit.hpp"

namespace	NuclearPowerPlant
{
  class NuclearReactor
  {
  public:
    NuclearReactor();
    NuclearReactor(const NuclearReactor &old);
    NuclearReactor	&operator=(const NuclearReactor &old);
    virtual ~NuclearReactor();

    virtual void	update(double);

    ReactorCoolantCircuit *newReactorCoolantCircuit();
    ReactorCore *newReactorCore();
    ReactorCoolantPump *newReactorCoolantPump();

    ReactorCoolantCircuit *reactorCoolantCircuit(int);
    ReactorCore *reactorCore(int);
    ReactorCoolantPump *reactorCoolantPump(int);

  private:
    std::vector<ReactorCoolantCircuit*> _nppReactorCoolantCircuits;
    std::vector<ReactorCore*> _nppReactorCores;
    std::vector<ReactorCoolantPump*> _nppReactorCoolantPumps;
  };
}

#endif
