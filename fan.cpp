#include "fan.h"

fan::fan() : weapon(35){}

void fan::represent() const{
	std::cout << "The magical fan!" << " - " << std::endl;
	if (this->isUsed())
		std::cout << " - Used!" << std::endl;
}

size_t fan::getDamage() const{
	return this->damage;
}

weapon* fan::clone() const{
	fan* toreturn = new fan(*this);
	return toreturn;
}

void fan::use()
{
	this->used = true;
}

bool fan::isUsed() const
{
	return this->used;
}

fan::~fan(){}
