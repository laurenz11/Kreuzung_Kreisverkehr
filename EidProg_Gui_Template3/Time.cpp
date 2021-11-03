#include "Time.h"
Time::Time() {
	this->clock.restart();
}

Time::~Time() {
}

void Time::startSimulation() {
	this->clock.restart();
}

unsigned int Time::getElapsedTime()
{
	return this->clock.getElapsedTime().asSeconds();
}
