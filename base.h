#pragma once
#include"weapon.h"
class base : public weapon {
public:
	base();
	virtual void represent() const;
	virtual size_t getDamage() const;

	//clone:
	weapon* clone() const override;

	//use:
	virtual void use() override;
	virtual bool isUsed() const override;

	//destruct:
	~base();
};

