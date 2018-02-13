//
// ReactorCoolantCircuit.cpp for ReactorCoolantCircuit in /home/xobtah/Projects/NuclearPowerPlant
//
// Made by xobtah
// Login   <xobtah@epitech.net>
//
// Started on  Tue Jan 23 11:48:53 2018 xobtah
// Last update Thu Jan 25 20:37:17 2018 xobtah
//

#include "ReactorCoolantCircuit.hpp"

namespace	NuclearPowerPlant
{
  /*
  **	Ctor & Dtor
  */

  ReactorCoolantCircuit::ReactorCoolantCircuit()
    : _rate(0), _rateVector(0), _heat(0), _volume(80000), _pressure(15.5)
  {}

  ReactorCoolantCircuit::ReactorCoolantCircuit(const ReactorCoolantCircuit &old)
  {
    (void) old;
  }

  ReactorCoolantCircuit	&ReactorCoolantCircuit::operator=(const ReactorCoolantCircuit &old)
  {
    if (&old != this)
      {
	
      }
    return (*this);
  }

  ReactorCoolantCircuit::~ReactorCoolantCircuit() {}

  /*
  **	Public member functions
  */

  void ReactorCoolantCircuit::givePower(double power, double delta)
  {
    _rateVector += (power - _rate) * delta;

    _rate += _rateVector - _rate;
    if (_rate < 0)
      _rate *= -1;
  }

  int ReactorCoolantCircuit::getVolume() const { return (_volume); }
  void ReactorCoolantCircuit::setVolume(int volume) { _volume = volume; }

  double ReactorCoolantCircuit::getPressure() const { return (_pressure); }
  void ReactorCoolantCircuit::setPressure(double pressure) { _pressure = pressure; }

  double ReactorCoolantCircuit::getRate() const { return (_rate); }
  void ReactorCoolantCircuit::setRate(double rate) { _rate = rate; }

  int ReactorCoolantCircuit::getHeat() const { return (_heat); }
  void ReactorCoolantCircuit::setHeat(int heat) { _heat = heat; }
}

std::ostream &operator<<(std::ostream &os, const NuclearPowerPlant::ReactorCoolantCircuit &rcc)
{
  os << "Heat: " << rcc.getHeat() << ", Rate: " << rcc.getRate() * 100 << '%';
  return (os);
}
