#pragma once
#include"monster.h"

class white_rabbit : public monster {
public:
	white_rabbit();

	//take - do damage:
	virtual void takeDamage(int _damage);
	virtual int doDamage() const;

	//start - end battle
	virtual bool isDead() const;
	virtual void startBattle();

	//defeat:
	virtual void defeat();
	virtual bool isDefeated() const;

	//info:
	virtual int getHealth() const;
	virtual void represent() const;
	virtual string visuals() const;

	//clone:
	monster* clone() const override;

	//destruct:
	~white_rabbit();
};

