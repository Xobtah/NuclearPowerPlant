//
// main.cpp for main in /home/xobtah/Projects/NuclearPowerPlant
//
// Made by xobtah
// Login   <xobtah@epitech.net>
//
// Started on  Tue Jan 23 09:11:46 2018 xobtah
// Last update Sun Jan 28 14:32:59 2018 xobtah
//

#include <unistd.h>
#include <csignal>

#include <iostream>
#include <string>
#include <map>
#include <chrono>

#include "NuclearPowerPlant.hpp"

bool main_loop_keeper = true;

int	main()
{
  signal(SIGINT, [](int sig)
	 {
	   (void) sig;
	   main_loop_keeper = false;
	   std::cout << std::endl << "Leaving..." << std::endl;
	 });
  //std::string	cmd;

  std::chrono::duration<double> time_span;
  std::chrono::high_resolution_clock::time_point tp = std::chrono::high_resolution_clock::now();
  std::chrono::high_resolution_clock::time_point prevTp = std::chrono::high_resolution_clock::now();

  NuclearPowerPlant::NuclearReactor nr;
  //NuclearPowerPlant::Operator op(nr);
  NuclearPowerPlant::ReactorCore *reactorCore = NULL;
  NuclearPowerPlant::ReactorCoolantCircuit *reactorCoolantCircuit = NULL;
  NuclearPowerPlant::ReactorCoolantPump *reactorCoolantPump = NULL;

  reactorCore = nr.newReactorCore();
  reactorCoolantCircuit = nr.newReactorCoolantCircuit();
  reactorCoolantPump = nr.newReactorCoolantPump();

  reactorCore->addToCoolantCircuit(reactorCoolantCircuit);
  reactorCoolantPump->addToCoolantCircuit(reactorCoolantCircuit);

  reactorCore->setControlRods(0.5);
  reactorCoolantPump->setPower(1);
  reactorCoolantCircuit->setRate(0.5);

  while (main_loop_keeper)
    {
      tp = std::chrono::high_resolution_clock::now();
      time_span = std::chrono::duration_cast<std::chrono::duration<double>>(tp - prevTp);
      nr.update(time_span.count());
      prevTp = tp;
      std::cout << '\r'
		<< *reactorCore << ", "
		<< *reactorCoolantPump << ", "
		<< *reactorCoolantCircuit << std::flush;
    }
  /*std::cout << "> ";
  while (getline(std::cin, cmd) && cmd != "exit")
    {
      std::cout << op.execute(cmd) << std::endl;
      std::cout << "> ";
      }*/
  return (0);
}
