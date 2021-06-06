#include "white_rabbit.h"

white_rabbit::white_rabbit() : monster(25) {}

void white_rabbit::takeDamage(int _damage) {
	this->healthPoints -= _damage;
}

int white_rabbit::doDamage() const {
	return this->damage;
}

bool white_rabbit::isDead() const {
	return (this->healthPoints <= 0);
}

void white_rabbit::startBattle() {
	this->healthPoints = 100;
}

void white_rabbit::defeat() {
	this->defeated = true;
}

bool white_rabbit::isDefeated() const {
	return this->defeated;
}

int white_rabbit::getHealth() const {
	return this->healthPoints;
}

void white_rabbit::represent() const {
	std::cout << "white rabbit";
}

string white_rabbit::visuals() const {
	char location[] = "monsters_representation/rabit.txt";
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

monster* white_rabbit::clone() const {
	white_rabbit* toReturn = new white_rabbit(*this);
	return toReturn;
}

white_rabbit::~white_rabbit() {}
