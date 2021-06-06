#pragma once
#include"weapon.h"
class eat_me : public weapon{
public:
	eat_me();
	virtual void represent() const;
	virtual size_t getDamage() const;
	
	//clone
	weapon* clone() const override;

	//use:
	virtual void use() override;
	virtual bool isUsed() const override;

	//destruct:
	~eat_me();
};

