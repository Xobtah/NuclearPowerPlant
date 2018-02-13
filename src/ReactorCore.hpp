//
// ReactorCore.hpp for ReactorCore in /home/xobtah/Projects/NuclearPowerPlant
//
// Made by xobtah
// Login   <xobtah@epitech.net>
//
// Started on  Tue Jan 23 09:28:22 2018 xobtah
// Last update Thu Jan 25 20:28:45 2018 xobtah
//

#ifndef REACTORCORE_HPP_
#define REACTORCORE_HPP_

#include <ostream>

#include "IModule.hpp"

namespace	NuclearPowerPlant
{
  class ReactorCore : public IModule
  {
  public:
    ReactorCore(int maxHeat = 750);
    ReactorCore(const ReactorCore &old);
    ReactorCore &operator=(const ReactorCore &old);
    virtual ~ReactorCore();

    virtual void update(double);

    double getControlRods() const;
    void setControlRods(double);

    double getHeat() const;

    double getMaxHeat() const;
    void setMaxHeat(double);

    double getFuel() const;
    void setFuel(double);

    //double getHeatVector() { return (_heatVector); }

  private:
    double _heat;
    double _maxHeat;
    double _heatVector;
    double _controlRods;
    double _controlRodsTarget;
    double _fuel;
  };
}

std::ostream &operator<<(std::ostream&, const NuclearPowerPlant::ReactorCore&);

#endif
