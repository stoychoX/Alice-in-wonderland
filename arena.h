#pragma once
#include"Alice.h"
#include"monster.h"
#include"classes/string.h"
#include<thread>
#include<chrono>

class arena {
private:
	//fighters:
	Alice* alice_fighter;
	monster* monster_fighter;

	//battle:
	void startBattle();
	void visualize() const;

	//void free(); TODO
public:
	arena(monster* monster, Alice* alice);
	void figth(bool& startOver);

	~arena();
};

