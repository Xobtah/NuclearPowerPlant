//
// ReactorCoolantPump.hpp for ReactorCoolantPump in /home/xobtah/Projects/NuclearPowerPlant
//
// Made by xobtah
// Login   <xobtah@epitech.net>
//
// Started on  Tue Jan 23 11:23:38 2018 xobtah
// Last update Thu Jan 25 20:27:03 2018 xobtah
//

#ifndef REACTORCOOLANTPUMP_HPP_
#define REACTORCOOLANTPUMP_HPP_

#include <ostream>

#include "IModule.hpp"

namespace	NuclearPowerPlant
{
  class ReactorCoolantPump : public IModule
  {
  public:
    ReactorCoolantPump();
    ReactorCoolantPump(const ReactorCoolantPump &old);
    ReactorCoolantPump &operator=(const ReactorCoolantPump &old);
    virtual ~ReactorCoolantPump();

    virtual void	update(double);

    double getPower() const;
    void setPower(double);

  private:
    double _power;
    double _powerTarget;
  };
}

std::ostream &operator<<(std::ostream&, const NuclearPowerPlant::ReactorCoolantPump&);

#endif
