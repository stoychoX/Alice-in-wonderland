#pragma once
#include"monster.h"
#include<cstdlib>
class crazy_hatman : public monster {
public:
	crazy_hatman();

	//damage:
	virtual void takeDamage(int _damage);
	virtual int doDamage() const;

	//start - end battle:
	virtual bool isDead() const;
	virtual void startBattle();

	//defeat:	
	virtual void defeat();
	virtual bool isDefeated() const;

	//info:
	virtual int getHealth() const;
	virtual void represent() const;
	virtual string visuals() const;

	//get random:
	int getRandom() const;
	
	//clone
	monster* clone() const override;

	//destruct:
	~crazy_hatman();
};

