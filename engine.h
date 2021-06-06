#ifndef ENGINE_H
#define ENGINE_H
#include"Maze.h"
#include"MazeVizualizer.h"
#include<conio.h>
#include<time.h>
#include<cmath>

const char STARTING_POINT[] = "mazes_data/1.txt";

class engine {
private:
	MazeVizualizer viz;

	void update(const int level);
	void startOver();

	//is monster or is weapon location:
	void catchMonster(int x, int y, bool& startOver, bool& moved);
	void catchWeapon(int x, int y);

	//superpowers:
	void catchMonsterSuperPower(int indexOfMonster, bool& caught, bool& moved);
	void catchWeaponSuperPower(bool& caught, bool& moved);
	void moveAliceRandomly(bool& moved);
	void moveAliceCloserToTheEnd();
public:
	engine();
	void run();
	void move(int x, int y, bool& startOver, int levelReached, char move);
};
#endif
