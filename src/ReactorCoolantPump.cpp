//
// ReactorCoolantPump.cpp for ReactorCoolantPump in /home/xobtah/Projects/NuclearPowerPlant
//
// Made by xobtah
// Login   <xobtah@epitech.net>
//
// Started on  Tue Jan 23 11:24:50 2018 xobtah
// Last update Thu Jan 25 20:30:18 2018 xobtah
//

#include "ReactorCoolantPump.hpp"

namespace	NuclearPowerPlant
{
  /*
  **	Ctor & Dtor
  */

  ReactorCoolantPump::ReactorCoolantPump() : _power(0), _powerTarget(0) {}

  ReactorCoolantPump::ReactorCoolantPump(const ReactorCoolantPump &old)
  {
    (void) old;
  }

  ReactorCoolantPump &ReactorCoolantPump::operator=(const ReactorCoolantPump &old)
  {
    if (&old != this)
      {
	
      }
    return (*this);
  }

  ReactorCoolantPump::~ReactorCoolantPump() {}

  /*
  **	Public member functions
  */

  void ReactorCoolantPump::update(double delta)
  {
    double rccNb = _reactorCoolantCircuits.size();
    /*double rateDelta = 0;
      double newRate = 0;*/

    _power -= (_power - _powerTarget) * delta;
    for (std::vector<ReactorCoolantCircuit*>::iterator it = _reactorCoolantCircuits.begin();
	 it != _reactorCoolantCircuits.end(); it++)
      {
	/*rateDelta = 0.2 * _power * delta / rccNb;
	if (!_power)
	  rateDelta = -0.2 * delta;
	newRate = (*it)->getRate() + rateDelta;

	if (newRate > 1)
	  newRate = 1;
	else if (newRate < 0)
	  newRate = 0;

	  (*it)->setRate(newRate);*/
	(*it)->givePower(_power / rccNb, delta);
      }
  }

  double ReactorCoolantPump::getPower() const { return (_power); }
  void ReactorCoolantPump::setPower(double powerTarget) { _powerTarget = powerTarget; }
}

std::ostream &operator<<(std::ostream &os, const NuclearPowerPlant::ReactorCoolantPump &rcp)
{
  os << "Power: " << rcp.getPower() * 100 << '%';
  return (os);
}
