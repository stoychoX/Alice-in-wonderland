//
//A maze vizualizer class used to vizualize everything happening in the maze
//

#ifndef MAZE_VIZ_H
#define MAZE_VIZ_H
#include<iostream>
#include"classes/pair.hpp"
#include"Maze.h"

class MazeVizualizer {
protected:
	Maze toViz;
public:
	//construct:
	MazeVizualizer();
	MazeVizualizer(Maze& toViz);

	//helpers:
	//void setMaze @param toViz: changing the current maze to the arg passed
	void setMaze(Maze& toViz);
	
	//void display @param level: printing the maze, using level to indicate which maze we are exploring
	void display(const int level, bool& hideMenu) const;

	//void showMazeInfo: showing the information about monsters/weapons and other maze-related information
	void showMazeInfo(int level) const;

	//pair<int, int> aliceCoordinates: returns current alice coordinates
	pair<int, int> aliceCoordinates() const;

	//map:
	//void next: moving to the next maze
	void next();

	//move related:
	void makeMove(const char move);
	bool isValidMove(int x, int y) const;

	int getMonsterIndex(int x, int y) const;
	int isWeaponMove(int x, int y) const;

	bool isEndMove(int x, int y) const;

	//get coordinates of current map:
	int getX() const;
	int getY() const;
	int getEndX() const;
	int getEndY() const;

	//add wepon to arsenal:
	void addWepon(int index);

	//isObtained:
	bool isObtained(int index) const;

	//get Alice:
	Alice& getAlice();
	void setStartPosAlice();
	monster* getFighter(int ind);
};
#endif // !MAZE_VIZ_H