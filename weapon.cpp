#include "weapon.h"

size_t weapon::getDamage() const {
	return this->damage;
}

weapon::weapon(size_t _pDamage) {
	this->damage = _pDamage;
	this->obtained = false;
	this->used = false;
}

void weapon::setDamage(size_t damage) {
	this->damage = damage;
	//setCoord(-1, -1) deleted!
}

void weapon::obtain() {
	this->obtained = true;
}

bool weapon::isObtained() const {
	return this->obtained;
}

bool weapon::isWeaponLocation(int x, int y) const {
	return (this->x_y_coord.first == x && this->x_y_coord.second == y);
}

void weapon::setCoord(int x, int y) {
	this->x_y_coord.first = x;
	this->x_y_coord.second = y;
}

weapon::~weapon() {}
