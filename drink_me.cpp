#include "drink_me.h"

drink_me::drink_me() : weapon(10) {}

void drink_me::represent() const {
	std::cout << "Drink me poison!" << std::endl;
	if (this->isUsed())
		std::cout << " - Used!" << std::endl;
}

size_t drink_me::getDamage() const {
	return this->damage;
}

weapon* drink_me::clone() const {
	drink_me* toreturn = new drink_me(*this);
	return toreturn;
}

void drink_me::use()
{
	this->used = true;
}

bool drink_me::isUsed() const
{
	return this->used;
}

drink_me::~drink_me() {}
