#include "crazy_hatman.h"
#include<time.h>

crazy_hatman::crazy_hatman() : monster(10) {
	int assign = getRandom();
	this->setDamage(assign);
}

void crazy_hatman::takeDamage(int _damage) {
	this->healthPoints -= _damage;
}

int crazy_hatman::doDamage() const {
	return this->damage;
}

bool crazy_hatman::isDead() const {
	return (this->healthPoints <= 0);
}

void crazy_hatman::startBattle()
{
	this->healthPoints = 100;
}

void crazy_hatman::defeat() {
	this->defeated = true;
}

bool crazy_hatman::isDefeated() const {
	return this->defeated;
}

int crazy_hatman::getHealth() const
{
	return this->healthPoints;
}

void crazy_hatman::represent() const {
	std::cout << "crazy hitman";
}

//void??
string crazy_hatman::visuals() const {
	char location[] = "monsters_representation/madman.txt";
	std::ifstream inFile(location);

	string toReturn;

	if (inFile.bad())
		throw std::exception("invalid location!");

	while (!inFile.eof()) {
		char buff[1024];
		inFile.getline(buff, 1024);
		toReturn += buff;
		toReturn += "\n";
	}
	inFile.close();
	return toReturn;
}

int crazy_hatman::getRandom() const {
	srand(time(NULL));
	return rand() % 20 + 10;
}

monster* crazy_hatman::clone() const {
	crazy_hatman* toReturn = new crazy_hatman(*this);
	return toReturn;
}

crazy_hatman::~crazy_hatman() {}
