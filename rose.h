#pragma once
#include<cstdlib> //rand
#include"weapon.h"
class rose : public weapon {
	bool _rose;
	void setRose();
public:
	rose();
	virtual void represent() const;
	virtual size_t getDamage() const;

	//use:
	virtual void use() override;
	virtual bool isUsed() const override;

	//clone:
	weapon* clone() const override;

	//destruct:
	~rose();
};

