##
## Makefile for NuclearPowerPlant in /home/xobtah/Projects/NuclearPowerPlant
##
## Made by xobtah
## Login   <xobtah@epitech.net>
##
## Started on  Tue Jan 23 09:09:28 2018 xobtah
## Last update Sun Jan 28 15:24:21 2018 xobtah
##

NAME	= npp

SRC	= src/main.cpp \
	src/ReactorCore.cpp \
	src/ReactorCoolantPump.cpp \
	src/ReactorCoolantCircuit.cpp \
	src/ReactorHeatExchanger.cpp \
	src/NuclearReactor.cpp \
	src/Operator.cpp \

OBJ	= $(SRC:.cpp=.o)

CXXFLAGS	= -std=c++11 -W -Wall -Werror

all: $(NAME)

$(NAME): $(OBJ)
	g++ -o $@ $^

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all
