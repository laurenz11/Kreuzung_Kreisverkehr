#pragma once
#include "SFML/System/Clock.hpp"
#include <iostream>


class Time
{
public: 
	Time();
	~Time();
	sf::Clock clock;

	void startSimulation();
	void stopSimulation();
	unsigned int getElapsedTime();
};

