//
//A Maze class containing all the information needed por printing, initializing, walking and deleting a maze.
//

#ifndef MAZE_H
#define MAZE_H
#include<fstream>
#include"classes/vector.hpp"
#include"classes/pair.hpp"
#include"Alice.h"
#include"monster.h"

class Maze {
	//friend class in order to easily access useful methods without making them public to other classes
	friend class MazeVizualizer;

protected:
	//Out main character:
	Alice m_alice;

	//monsters:
	vector<monster*> monstersInMaze;

	//weapons:
	vector<weapon*> weaponsInMaze;

	//A pointer to the next maze
	Maze* next;

	//operator=
	Maze& operator=(const Maze& other);

	//coordinates:
	pair<int, int> wid_len_size;
	pair<int, int> start_pos;
	pair<int, int> end_pos;

	//main data used to print the maze:
	vector<vector<int>> data;

	//show monsters/weapons:
	void showMonsters() const;
	void showWeapons() const;

	//init:
	
	//void initMaze @param: location -> used to locate the file needed to init the maze.
	void initMaze(const char* location);

	//void isValidMove @param x, @param y: used to determine if the move we are about to make is valid
	bool isValidMove(int x, int y) const;

	//free:
	void free();

	//void copyFrom @param other: Maze obj from where we read data.
	void copyFrom(const Maze& other);
public:
	//construct:
	Maze();
	Maze(const char* location);

	//move:
	//void move @param move -> used to indicate which exact move we would like to make
	void makeMove(const char move);

	//void isEndMove @param x, @param y: checks if the move leads to an end portal
	bool isEndMove(int x, int y) const;

	~Maze();
};

#endif // !MAZE_H