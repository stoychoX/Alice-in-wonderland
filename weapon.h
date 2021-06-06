#pragma once
#include<iostream>
#include"classes/pair.hpp"

class weapon {
protected:
	size_t damage;
	pair<int, int> x_y_coord;
	bool obtained;
	bool used;

public:
	//virtuals:
	virtual size_t getDamage() const;
	virtual void represent() const = 0;

	weapon(size_t _pDamage);
	void setDamage(size_t damage);

	//obtain:
	void obtain();
	bool isObtained() const;

	//coordinates:
	bool isWeaponLocation(int x, int y) const;
	void setCoord(int x, int y);

	//use semantics:
	virtual void use() = 0;
	virtual bool isUsed() const = 0;

	//clone:
	virtual weapon* clone() const = 0;

	//destruct:
	virtual ~weapon();
};