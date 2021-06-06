#include "c_cat.h"

c_cat::c_cat() : monster(0) {}

int c_cat::getHealth() const {
	return this->healthPoints;
}

void c_cat::represent() const {
	std::cout << "cat";
}

string c_cat::visuals() const {
	char location[] = "monsters_representation/cat.txt";
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

monster* c_cat::clone() const {
	c_cat* toReturn = new c_cat(*this);
	return toReturn;
}

c_cat::~c_cat() {}

void c_cat::takeDamage(int damage) {
	this->healthPoints -= damage;
}

int c_cat::doDamage() const {
	return 401;
}

bool c_cat::isDead() const {
	return (this->healthPoints <= 0);
}

void c_cat::startBattle() {
	this->healthPoints = 100;
}

void c_cat::defeat() {
	this->defeated = true;
}

bool c_cat::isDefeated() const {
	return this->defeated;
}
