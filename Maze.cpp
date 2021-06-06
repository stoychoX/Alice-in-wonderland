#include "Maze.h"
#include"incl_monster.h"
#include"weapon_incl.h"
#include"classes/string.h"

Maze::Maze() : wid_len_size(0, 0), start_pos(0, 0), end_pos(0, 0), next(nullptr) {
	m_alice.setPos(0, 0);
}

Maze::Maze(const char* location) {
	try {
		initMaze(location);
	}
	catch (const std::exception&) {	}
}

void Maze::makeMove(const char move) {
	this->m_alice.makeMove(move);
}

bool Maze::isEndMove(int x, int y) const {
	return (x == end_pos.first && y == end_pos.second);
}

Maze::~Maze() { free(); }

Maze& Maze::operator=(const Maze& other) {
	if (this != &other) {
		this->free();
		copyFrom(other);
	}

	return *this;
}

void Maze::showMonsters() const {
	int index = 1;

	if (monstersInMaze.isEmpty()) {
		std::cout << "Don't worry! No monsters in the maze!\n";
		return;
	}
	std::cout << "Monsters in maze:" << std::endl;
	for (auto _arg : monstersInMaze) {
		std::cout << index++ << ". ";
		_arg->represent();
		if (_arg->isDefeated())
			std::cout << " - Defeated!" << std::endl;
		else
			std::cout << "\n- Looking for you!" << std::endl;
	}
	std::cout << std::endl;
}

void Maze::showWeapons() const {
	int index = 1;

	if (weaponsInMaze.isEmpty()) {
		std::cout << "\nNo weapons in this maze!" << std::endl;
		return;
	}

	std::cout << "Weapons in maze: " << std::endl;
	for (auto _arg : weaponsInMaze) {
		std::cout << index++ << ". ";

		_arg->represent();

		if (_arg->isObtained())
			std::cout << " - Obtained!" << std::endl;
		else
			std::cout << " - Yet to find!" << std::endl;
	}
}

void Maze::initMaze(const char* location) {
	std::ifstream inFile(location);

	if (inFile.bad())
		throw std::exception("invalid location!");

	//1) width and length
	inFile >> this->wid_len_size.first;
	inFile >> this->wid_len_size.second;

	//2) link to the next maze
	string locNext;
	inFile >> locNext;

	if (locNext == "END_DIR") {
		next = nullptr;
	}
	else {
		Maze* nMaze = new Maze(locNext.c_str());
		this->next = nMaze;
	}
	//Monsters:
	int nMonsters;
	inFile >> nMonsters;

	for (int i = 0; i < nMonsters; i++) {
		char c;
		inFile >> c;

		monster* toAdd = nullptr;

		switch (c) {
		case 'c': toAdd = new c_cat; break;
		case 'q': toAdd = new heart_queen; break;
		case 'r': toAdd = new white_rabbit; break;
		case 'h': toAdd = new crazy_hatman; break;
		default: break;
		}

		int x, y;
		inFile >> x >> y;

		toAdd->setCoord(x, y);
		this->monstersInMaze.push_back(toAdd); //TODO
	}

	//weapon:
	int nWeapons;
	inFile >> nWeapons;
	for (int i = 0; i < nWeapons; i++) {
		char c;
		inFile >> c;

		weapon* toAdd = nullptr;

		switch (c) {
		case 't': toAdd = new teleport; break;
		case'd':  toAdd = new drink_me; break;
		case'e':  toAdd = new eat_me; break;
		case'f':  toAdd = new fan; break;
		case'h': toAdd = new hat; break;
		case'r': toAdd = new rose; break;
		default: break;
		}

		int x, y;
		inFile >> x >> y;
		toAdd->setCoord(x, y);
		this->weaponsInMaze.push_back(toAdd);
	}

	//start and end position:
	inFile >> this->start_pos.first;
	inFile >> this->start_pos.second;

	m_alice.setPos(this->start_pos.first, this->start_pos.second);

	inFile >> this->end_pos.first;
	inFile >> this->end_pos.second;

	for (int i = 0; i < wid_len_size.second; i++) {
		vector<int> curr;
		for (int j = 0; j < wid_len_size.first; j++) {
			char c;
			inFile >> c;
			curr.push_back(c - '0');
		}
		data.push_back(curr);
	}

	inFile.close();
}

bool Maze::isValidMove(int x, int y) const {
	if (x < 0 || y < 0 || x > this->wid_len_size.second - 1 || y >this->wid_len_size.first - 1)
		return false;

	if (data[x][y] == 1)
		return false;

	return true;
}

void Maze::free() {
	this->data.clear();

	for (auto _arg : monstersInMaze)
		delete _arg;

	for (auto _arg : weaponsInMaze)
		delete _arg;

	this->monstersInMaze.clear();
	this->weaponsInMaze.clear();
}

void Maze::copyFrom(const Maze& other) {
	for (auto _arg : other.monstersInMaze)
		this->monstersInMaze.push_back(_arg->clone());

	for (auto _arg : other.weaponsInMaze)
		this->weaponsInMaze.push_back(_arg->clone());

	for (int i = 0; i < other.data.Size(); i++) {
		this->data.push_back(other.data[i]);
	}

	this->m_alice.setPos(other.m_alice.getX(), other.m_alice.getY());

	if (other.next != nullptr) //exception! 
		this->next = other.next;
	else
		this->next = nullptr;

	this->wid_len_size = other.wid_len_size;
	this->start_pos = other.start_pos;
	this->end_pos = other.end_pos;
}
