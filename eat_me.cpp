#include "eat_me.h"

eat_me::eat_me() : weapon(40) {}

void eat_me::represent() const {
	std::cout << "Eat me poison!" << std::endl;
	if (this->isUsed())
		std::cout << " - Used!" << std::endl;
}

size_t eat_me::getDamage() const {
	return this->damage;
}

weapon* eat_me::clone() const {
	eat_me* toreturn = new eat_me(*this);
	return toreturn;
}

void eat_me::use()
{
	this->used = true;
}

bool eat_me::isUsed() const
{
	return this->used;
}


eat_me::~eat_me() {}
