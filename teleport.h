#pragma once
#include"weapon.h"
class teleport : public weapon {
public:
	teleport();
	virtual size_t getDamage() const;
	virtual void represent() const;

	//clone:
	weapon* clone() const override;

	//use:
	virtual void use() override;
	virtual bool isUsed() const override;

	//destruct:
	~teleport();
};

