#include "monster.h"

monster::monster(int _damage) {
	this->damage = _damage;
	setCoord(-1, -1);
	defeated = false;
}

void monster::setDamage(int _damage) {
	this->damage = _damage;
}

void monster::setCoord(int x, int y) {
	this->x_y_coord.first = x;
	this->x_y_coord.second = y;
}

bool monster::isMonsterLocation(int x, int y) const{
	return (this->x_y_coord.first == x && this->x_y_coord.second == y);
}

monster::~monster(){}
