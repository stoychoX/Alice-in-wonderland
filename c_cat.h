#pragma once
#include"monster.h"
class c_cat : public monster{
public:
	c_cat();

	//damage:
	virtual void takeDamage(int _damage);
	virtual int doDamage() const;

	//start and end of battle
	virtual bool isDead() const;
	virtual void startBattle();

	//DEFEAT:
	virtual void defeat();
	virtual bool isDefeated() const;

	//info:
	virtual int getHealth() const;
	virtual void represent() const;
	virtual string visuals() const;

	//clone:
	monster* clone() const override;

	//destruct:
	~c_cat();
};