//
// ReactorCore.cpp for ReactorCore in /home/xobtah/Projects/NuclearPowerPlant
//
// Made by xobtah
// Login   <xobtah@epitech.net>
//
// Started on  Tue Jan 23 09:32:17 2018 xobtah
// Last update Sun Jan 28 15:16:10 2018 xobtah
//

#include "ReactorCore.hpp"

namespace	NuclearPowerPlant
{
  /*
  **	Ctor & Dtor
  */

  ReactorCore::ReactorCore(int maxHeat) : _heat(0), _maxHeat(maxHeat), _heatVector(0), _controlRods(0), _controlRodsTarget(0), _fuel(1) {}

  ReactorCore::~ReactorCore() {}

  /*
  **	Public member functions
  */

  void ReactorCore::update(double delta)
  {
    double maxHeatCoef = 30.0;
    double maxCoolCoef = 10.0;

    _controlRods -= (_controlRods - _controlRodsTarget) * delta;
    _fuel -= 0.000001 * delta;

    if (_controlRods > 0)
      _heatVector += maxHeatCoef * _controlRods * delta * _fuel;
    else
      _heatVector -= maxCoolCoef * delta;

    if (_heatVector > maxHeatCoef)
      _heatVector = maxHeatCoef;
    else if (_heatVector < -maxCoolCoef)
      _heatVector = -maxCoolCoef;

    for (std::vector<ReactorCoolantCircuit*>::iterator it = _reactorCoolantCircuits.begin();
	 it != _reactorCoolantCircuits.end(); it++)
      {
	(*it)->setHeat((*it)->getRate() * _heat);
	_heatVector -= maxHeatCoef * ((*it)->getRate() / 2) * delta;
      }

    _heat += _heatVector * delta;
    if (_heat < 0)
      _heat = 0;
  }

  double ReactorCore::getControlRods() const { return (_controlRods); }
  void ReactorCore::setControlRods(double target) { _controlRodsTarget = target; }

  double ReactorCore::getHeat() const { return (_heat); }

  double ReactorCore::getMaxHeat() const { return (_maxHeat); }
  void ReactorCore::setMaxHeat(double maxHeat) { _maxHeat = maxHeat; }

  double ReactorCore::getFuel() const { return (_fuel); }
  void ReactorCore::setFuel(double fuel) { _fuel = fuel; }
}

std::ostream &operator<<(std::ostream &os, const NuclearPowerPlant::ReactorCore &rc)
{
  os
    << "Heat: " << rc.getHeat() << ", "
    << "Control Rods: " << rc.getControlRods() * 100 << "%, "
    << "Fuel: " << rc.getFuel() * 100 << '%';
  return (os);
}
