#ifndef ALICE_H
#define ALICE_H
#include"classes/pair.hpp"
#include"classes/string.h"
#include"arsenal.h"
#include<fstream>

const char DEF_ALICE = 'A';

class Alice {
	char alice;
	pair<int, int> x_y_pos;
	arsenal myWeapons;
	int healthPoints;

	int cantBeSeen;

public:
	//construct:
	Alice();
	Alice(int startX, int startY);

	//fight:
	int doDamage() const;
	void takeDamage(int _damage);
	bool dead() const;
	void startBattle();

	//move:
	int getX() const;
	int getY() const;

	//position helpers:
	void makeMove(const char move);
	void setPos(int newX, int newY);
	char getHead() const;

	//other helpers:
	void setHead(char _head);
	int getHealth() const;

	//invinsible:
	void setCantBeSeen(int moves);
	int getMovesLeft() const; //-- included!!!
	void incMoves();

	//visuals:
	string visuals() const;
	void showArsenal() const;

	//weapon:
	void addWepon(weapon* toAdd);
	void chooseWeapon();

	//TODO: show Weapon

	//operator= -> we dont need
};
#endif // !ALICE_D
