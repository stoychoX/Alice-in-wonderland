#pragma once
#include"weapon.h"
class drink_me : public weapon {
public:
	drink_me();
	virtual void represent() const;
	virtual size_t getDamage() const;

	//clone:
	weapon* clone() const override;

	//use:
	virtual void use() override;
	virtual bool isUsed() const override;

	//destruct:
	~drink_me();
};

