#include "arena.h"

arena::arena(monster* monster, Alice* alice) {
	this->alice_fighter = alice;
	this->monster_fighter = monster;
}

void arena::startBattle() {
	alice_fighter->startBattle();
	monster_fighter->startBattle();
}

void arena::visualize() const {
	system("CLS");
	string toRepMonster = this->monster_fighter->visuals();
	string toRepAlice = this->alice_fighter->visuals();
	std::cout << toRepAlice;
	for (int i = 0; i < 45; i++)
		std::cout << '=';
	std::cout << std::endl << toRepMonster;

	std::cout << "\nAlice health: " << this->alice_fighter->getHealth() << std::endl <<
		"Monster health: " << this->monster_fighter->getHealth() << std::endl;
}

void arena::figth(bool& startOver) {
	this->startBattle();
	bool alice_turn = true;

	while (!(alice_fighter->dead() || monster_fighter->isDead())) {
		visualize();
		if (alice_turn == true) {
			monster_fighter->takeDamage(alice_fighter->doDamage());
			alice_turn = false;
		}
		else {
			alice_fighter->takeDamage(monster_fighter->doDamage());
			alice_turn = true;
		}
		system("PAUSE");
	}

	if (alice_fighter->dead())
		startOver = true;
	else
		this->monster_fighter->defeat();
}

arena::~arena() {

}
