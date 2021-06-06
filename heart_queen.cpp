#include "heart_queen.h"

heart_queen::heart_queen() : monster(25) {}

void heart_queen::takeDamage(int _damage) {
	this->healthPoints -= _damage;
}

int heart_queen::doDamage() const {
	return this->damage;
}

bool heart_queen::isDead() const {
	return (this->healthPoints <= 0);
}

void heart_queen::startBattle() {
	this->healthPoints = 100;
}

void heart_queen::defeat() {
	this->defeated = true;
}

bool heart_queen::isDefeated() const {
	return this->defeated;
}

int heart_queen::getHealth() const {
	return this->healthPoints;
}

void heart_queen::represent() const {
	std::cout << "heart queen";
}

string heart_queen::visuals() const {
	char location[] = "monsters_representation/queen.txt";
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

monster* heart_queen::clone() const {
	heart_queen* toReturn = new heart_queen(*this);
	return toReturn;
}

heart_queen::~heart_queen() {}
