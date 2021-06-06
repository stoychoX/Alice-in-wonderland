#include "teleport.h"
teleport::teleport() : weapon(0) {}

size_t teleport::getDamage() const {
	return 402;
}

void teleport::represent() const {
	std::cout << "Teleport poison!"<< std::endl;
	if (this->isUsed())
		std::cout << " - Used!" << std::endl;
}

weapon* teleport::clone() const {
	teleport* toReturn = new teleport(*this);
	return toReturn;
}

void teleport::use()
{
	this->used = true;
}

bool teleport::isUsed() const
{
	return this->used;
}

teleport::~teleport() {}
