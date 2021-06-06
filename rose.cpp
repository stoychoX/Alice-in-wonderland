#include "rose.h"

void rose::setRose() { //TODO -> real rand
	int ind = rand() % 2;
	this->_rose = ind;
}

rose::rose() : weapon(10) {
	setRose();

	if (_rose)
		this->setDamage(40);
}

void rose::represent() const{
	std::cout << "White or red rose. Which one might it be?" << std::endl;
	if (this->isUsed())
		std::cout << " - Used!" << std::endl;
}

size_t rose::getDamage() const{
	return this->damage;
}

void rose::use()
{
	this->used = true;
}

bool rose::isUsed() const
{
	return this->used;
}

weapon* rose::clone() const{
	rose* toReturn = new rose(*this);
	return toReturn;
}

rose::~rose(){}
