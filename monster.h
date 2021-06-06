#ifndef MONSTER_H
#define MONSTER_H
#include<iostream>
#include"classes/string.h"
#include"classes/pair.hpp"
#include<fstream>

class monster {
protected:
	int damage;
	int healthPoints;
	bool defeated;

	pair<int, int> x_y_coord;

	void setDamage(int _damage);
public:
	monster(int _damage);

	//coord:
	virtual void setCoord(int x, int y);
	virtual bool isMonsterLocation(int x, int y) const;
	virtual void defeat() = 0;
	virtual bool isDefeated() const = 0;

	//battle:
	virtual void takeDamage(int _damage) = 0;
	virtual int doDamage() const = 0;
	virtual bool isDead() const = 0;
	virtual void startBattle() = 0;

	//info:
	virtual int getHealth() const = 0;
	virtual void represent() const = 0;
	virtual string visuals() const = 0;

	//clone:
	virtual monster* clone() const = 0;

	//destructor:
	virtual ~monster();
};

#endif // !MONSTER_H