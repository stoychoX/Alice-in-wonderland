#include "engine.h"
#include"arena.h"
#include<Windows.h>

bool hideMenu = false;

engine::engine() {
	Maze mz(STARTING_POINT);
	viz.setMaze(mz);
}

void engine::run() {
	//enter full screen mode:
	SetConsoleDisplayMode(GetStdHandle(STD_OUTPUT_HANDLE), CONSOLE_FULLSCREEN_MODE, 0);

	int levelReached = 1;
	this->update(levelReached);
	bool startOver = false;

	bool running = true;

	while (running) {
		system("Title = Alice in wonderland");
		pair<int, int> coord = viz.aliceCoordinates();

		if (viz.isEndMove(coord.first, coord.second)) {
			try {
				levelReached++;
				this->viz.next();
				update(levelReached);
			}
			catch (const std::exception&) { system("CLS"); break; } //end of game!
		}

		if (_kbhit()) {
			char c = _getch(); //command

			//getting alice x and y coordinates:
			int x = coord.c_first();
			int y = coord.c_second();

			switch (c) {
			case 's':
				move(x + 1, y, startOver, levelReached, 'd');
				break;
			case 'w':
				move(x - 1, y, startOver, levelReached, 'u');
				break;
			case 'd':
				move(x, y + 1, startOver, levelReached, 'r');
				break;
			case 'a':
				move(x, y - 1, startOver, levelReached, 'l');
				break;
			case 'h':
				hideMenu = !hideMenu;
				this->update(levelReached);
				break;
			case 'x':
				running = false;
				std::cout << "Bye :(";
				exit(1);
				break;
			default:
				break;
			}
		}
	}
	system("CLS");
	std::cout << "You finished all the mazes!!";
}

void engine::move(int x, int y, bool& startOver, int levelReached, char move) {
	bool movedRandomly = false;

	if (viz.isValidMove(x, y)) {
		if (this->viz.getAlice().getMovesLeft() == 0) {
			catchMonster(x, y, startOver, movedRandomly);
		}
		else {
			this->viz.getAlice().incMoves();
		}

		catchWeapon(x, y);
		if (!startOver && !movedRandomly) {
			this->viz.makeMove(move);
			this->update(levelReached);
		}
		else if (movedRandomly == true) {
			movedRandomly = false;
			this->update(levelReached);
		}
		else {
			this->startOver();
			startOver = false;
			this->update(levelReached);
		}
	}
}

void engine::update(const int level) {
	system("CLS");
	viz.display(level, hideMenu);
}

void engine::startOver() {
	viz.setStartPosAlice();
}

void engine::catchMonster(int x, int y, bool& startOver, bool& moved) {
	int indexOfMonster = viz.getMonsterIndex(x, y);

	//booleans indicating if we caught something that would end the battle:
	bool caughtMonsterSuperPower = false;
	bool caughtWeaponSuperPower = false;

	bool validIndex = (indexOfMonster != -1);

	if (validIndex)
		catchMonsterSuperPower(indexOfMonster, caughtMonsterSuperPower, moved);

	if (validIndex && !this->viz.getFighter(indexOfMonster)->isDefeated() && !caughtMonsterSuperPower) {
		system("Title = MONSTER IN OUR WAY!!!");
		std::cout << "\nWAEPONS AVAIABLE:\n";
		this->viz.getAlice().chooseWeapon();

		catchWeaponSuperPower(caughtWeaponSuperPower, moved);

		if (!caughtWeaponSuperPower) {
			arena myArena(this->viz.getFighter(indexOfMonster), &this->viz.getAlice());
			myArena.figth(startOver);
		}
	}
}

void engine::catchWeapon(int x, int y) {

	int index = viz.isWeaponMove(x, y);
	if (index != -1 && !viz.isObtained(index)) {
		this->viz.addWepon(index);
	}
}

void engine::catchMonsterSuperPower(int indexOfMonster, bool& caught, bool& moved) {
	int indexOfSuperPower = viz.getFighter(indexOfMonster)->doDamage();
	switch (indexOfSuperPower)
	{
	case 401:
		caught = true;
		this->moveAliceRandomly(moved);
		break;
	default:
		break;
	}
}

void engine::catchWeaponSuperPower(bool& caught, bool& moved) {
	int indexOfChoosenWeapon = this->viz.getAlice().doDamage();
	switch (indexOfChoosenWeapon) {
	case 400:
		caught = true;
		this->viz.getAlice().setCantBeSeen(2);
		break;
	case 402:
		caught = true;
		moved = true;
		this->moveAliceCloserToTheEnd();
		break;
	default:
		break;
	}
}

void engine::moveAliceRandomly(bool& moved) {
	moved = true;
	srand(time(NULL));

	int x, y;
	do {
		x = rand() % this->viz.getX();
		y = rand() % this->viz.getY();
	} while (!this->viz.isValidMove(x, y));

	this->viz.getAlice().setPos(x, y);

}

void engine::moveAliceCloserToTheEnd() {
	pair<int, int> A(this->viz.aliceCoordinates().c_first(), this->viz.aliceCoordinates().c_second()); //point A

	int move = 3;

	bool found = true;

	while (this->viz.isValidMove(A.first + move, A.second) == false) {
		move++;

		if (A.first + move >= this->viz.getY()) {
			found = false;
			break;
		}
	}

	if (found) this->viz.getAlice().setPos(A.first + move, A.second);
}


void engine::printIntro() const {
}