#include "hat.h"


hat::hat() : weapon(0) {}

void hat::represent() const {
	std::cout << "Invisible hat!" << " - " << std::endl;
	if (this->isUsed())
		std::cout << " - Used!" << std::endl;
}

size_t hat::getDamage() const {
	return 400; //a specific code for this weapon.
}

weapon* hat::clone() const {
	hat* toReturn = new hat(*this);
	return toReturn;
}

void hat::use()
{
	this->used = true;
}

bool hat::isUsed() const
{
	return this->used;
}

hat::~hat() {}
