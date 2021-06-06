#include "Alice.h"
#include<conio.h>

Alice::Alice() : alice(DEF_ALICE), x_y_pos(0, 0), cantBeSeen(0) {}

Alice::Alice(int startX, int startY) : alice(DEF_ALICE), x_y_pos(startX, startY) {}

int Alice::doDamage() const {
	return myWeapons.attack();
}

void Alice::takeDamage(int _damage) {
	healthPoints -= _damage;
}

bool Alice::dead() const {
	return (healthPoints <= 0);
}

void Alice::startBattle() {
	this->healthPoints = 100;
}

int Alice::getX() const {
	return this->x_y_pos.first;
}

int Alice::getY() const {
	return this->x_y_pos.second;
}

void Alice::makeMove(const char move) {
	switch (move) {
	case 'l':
		this->x_y_pos.second--;
		break;
	case 'r':
		this->x_y_pos.second++;
		break;
	case 'u':
		this->x_y_pos.first--;
		break;
	case 'd':
		this->x_y_pos.first++;
		break;
	default:
		break;
	}
}

void Alice::setPos(int newX, int newY) {
	this->x_y_pos.first = newX;
	this->x_y_pos.second = newY;
}

char Alice::getHead() const {
	return this->alice;
}

void Alice::setHead(char _head) {
	this->alice = _head;
}

int Alice::getHealth() const {
	return this->healthPoints;
}

void Alice::setCantBeSeen(int moves) {
	this->cantBeSeen = moves;
}

int Alice::getMovesLeft() const{
	return this->cantBeSeen;
}

void Alice::incMoves()
{
	this->cantBeSeen--;
}

string Alice::visuals() const
{
	char location[] = "monsters_representation/alice.txt";
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

void Alice::addWepon(weapon* toAdd) {
	myWeapons.addWeapon(toAdd);
}

void Alice::chooseWeapon() {
	int ind = -1;
	do {
		system("CLS");
		std::cout << "MONSTER IN OUR WAY!\n";
		this->myWeapons.showArsenal();
		std::cout << "\nChoose your weapon: " << std::endl << "Make sure it is not used!" << std::endl << "->";

		//deals with string input!
		while (true) {
			if (_kbhit()) {
				char c = _getch();

				switch (c) {
				case '0': case'1': case '2': case '3': case '4': case '5': case '6': case '7': case '8': case '9':
					ind = c - '0'; break;
				default:
					break;
				}
				break;
			}
		}
	} while (ind < 0 || ind > this->myWeapons.size() - 1 || this->myWeapons.isUsed(ind));

	this->myWeapons.setWeapon(ind);
}