//
// ReactorCoolantCircuit.hpp for ReactorCoolantCircuit in /home/xobtah/Projects/NuclearPowerPlant
//
// Made by xobtah
// Login   <xobtah@epitech.net>
//
// Started on  Tue Jan 23 11:48:16 2018 xobtah
// Last update Thu Jan 25 20:28:22 2018 xobtah
//

#ifndef REACTORCOOLANTCIRCUIT_HPP_
#define REACTORCOOLANTCIRCUIT_HPP_

#include <ostream>

namespace	NuclearPowerPlant
{
  class ReactorCoolantCircuit
  {
  public:
    ReactorCoolantCircuit();
    ReactorCoolantCircuit(const ReactorCoolantCircuit &old);
    ReactorCoolantCircuit &operator=(const ReactorCoolantCircuit &old);
    virtual ~ReactorCoolantCircuit();

    void givePower(double, double);

    int getVolume() const;
    void setVolume(int);

    double getPressure() const;
    void setPressure(double);

    double getRate() const;
    void setRate(double);

    int getHeat() const;
    void setHeat(int);

  private:
    double _rate;
    double _rateVector;
    int _heat;
    int _volume; // m3/hr
    double _pressure; // megapascal MPa
  };
}

std::ostream &operator<<(std::ostream&, const NuclearPowerPlant::ReactorCoolantCircuit&);

#endif
