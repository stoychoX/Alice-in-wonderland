#pragma once
#include"weapon.h"
class fan : public weapon{
public:
	fan();
	virtual void represent() const;
	virtual size_t getDamage() const;

	//clone:
	weapon* clone() const override;

	//use:
	virtual void use() override;
	virtual bool isUsed() const override;

	//destruct:
	~fan();
};

