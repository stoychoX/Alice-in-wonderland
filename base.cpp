#include "base.h"

base::base() : weapon(15) {
}

void base::represent() const {
	std::cout << "Base skill" << std::endl;
}

size_t base::getDamage() const {
	return this->damage;
}

weapon* base::clone() const {
	base* toReturn = new base(*this);
	return toReturn;
}

void base::use()
{
	this->used = false;
}

bool base::isUsed() const
{
	return this->used;
}

base::~base() {}
