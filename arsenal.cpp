#include "arsenal.h"

void arsenal::free() {
	for (auto _arg : _arsenal)
		delete[] _arg;

	delete[] curr;
}

arsenal::arsenal() {
	base* _base = new base();
	this->addWeapon(_base);

	this->curr = nullptr;
}

void arsenal::setWeapon(int index) {
	this->curr = _arsenal[index]->clone();
	this->_arsenal[index]->use();
}

int arsenal::size() const {
	return this->_arsenal.Size();
}

int arsenal::attack() const {
	return curr->getDamage();
}

void arsenal::showArsenal() const {
	int index = 0;
	std::cout << std::endl;
	for (auto _arg : _arsenal) {
		std::cout << index++ << ": ";
		_arg->represent();
		std::cout << std::endl;
	}
}

void arsenal::addWeapon(weapon* toAdd) {
	_arsenal.push_back(toAdd->clone());
}

bool arsenal::isUsed(int index) const {
	return _arsenal[index]->isUsed();
}

arsenal::~arsenal() {
	free();
}


