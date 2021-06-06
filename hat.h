#pragma once
#include"weapon.h"
class hat : public weapon{
public:
	hat();
	virtual void represent() const;
	virtual size_t getDamage() const;
	
	//clone:
	weapon* clone() const override;

	//use:
	virtual void use() override;
	virtual bool isUsed() const override;

	//destruct:
	~hat();
};

