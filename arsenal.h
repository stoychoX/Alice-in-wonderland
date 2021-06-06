#pragma once
#include"weapon.h"
#include"base.h"
#include"classes/vector.hpp"

class arsenal {
	vector<weapon*> _arsenal;
	weapon* curr;
	void free();

public:
	arsenal();
	void setWeapon(int index);
	int size() const;

	int attack() const;
	void showArsenal() const;
	void addWeapon(weapon* toAdd);

	//used:
	bool isUsed(int index) const;

	//destructor:
	~arsenal();
};