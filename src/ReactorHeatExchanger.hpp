//
// ReactorHeatExchanger.hpp for ReactorHeatExchanger in /home/xobtah/Projects/NuclearPowerPlant/src
//
// Made by xobtah
// Login   <xobtah@epitech.net>
//
// Started on  Sun Jan 28 15:20:29 2018 xobtah
// Last update Sun Jan 28 15:23:47 2018 xobtah
//

#ifndef REACTORHEATEXCHANGER_HPP_
#define REACTORHEATEXCHANGER_HPP_

#include "IModule.hpp"

namespace NuclearPowerPlant
{
  class ReactorHeatExchanger : public IModule
  {
  public:
    ReactorHeatExchanger();
    ReactorHeatExchanger(const ReactorHeatExchanger &old);
    ReactorHeatExchanger &operator=(const ReactorHeatExchanger &old);
    virtual ~ReactorHeatExchanger();

    void update(double);
  };
}

#endif
