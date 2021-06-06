#include "MazeVizualizer.h"

const int MAZES_COUNT = 17;

MazeVizualizer::MazeVizualizer() {}

MazeVizualizer::MazeVizualizer(Maze& toViz) {
	this->toViz = toViz;
}

void MazeVizualizer::setMaze(Maze& toViz) {
	this->toViz = toViz;
}

void MazeVizualizer::display(const int level, bool& hideMenu) const {
	int wid = toViz.wid_len_size.c_first();
	int len = toViz.wid_len_size.c_second();

	for (int i = 0; i < len; i++) {
		for (int j = 0; j < wid; j++) {
			if (i == toViz.m_alice.getX() && j == toViz.m_alice.getY()) {
				std::cout << toViz.m_alice.getHead();
				continue;
			}

			int curr = toViz.data[i][j];

			if (curr == 1)
				std::cout << '*';
			else
				std::cout << ' ';

		}
		std::cout << std::endl;
	}
	if (!hideMenu)
		showMazeInfo(level);
}

void MazeVizualizer::showMazeInfo(int level) const {
	std::cout << "\nABOUT THIS WORLD:" << std::endl;

	std::cout << "SIZE OF MAZE: " << this->toViz.wid_len_size.c_first() << " " << this->toViz.wid_len_size.c_second() << std::endl;

	std::cout << "\nEND OF MAZE: " << this->toViz.end_pos.first << " " << this->toViz.end_pos.second <<
		"\n\nCURRENT MAZE: " << level << std::endl << std::endl;
	std::cout << "MAZES LEFT: " << MAZES_COUNT - level << std::endl << std::endl;

	this->toViz.showMonsters();
	this->toViz.showWeapons();

	std::cout << std::endl << "PRESS h TO HIDE THIS INFO OR SHOW IT AGAIN!"<<std::endl;
	std::cout << std::endl << "PRESS x TO EXIT THE GAME!"<<std::endl;
	std::cout << std::endl << "PRESS v TO SHOW ARSENAL"<<std::endl;
}

pair<int, int> MazeVizualizer::aliceCoordinates() const {
	return pair<int, int>(toViz.m_alice.getX(), toViz.m_alice.getY());
}

void MazeVizualizer::next() {
	if (toViz.next == nullptr)
		throw std::exception("End of game"); //end of game

	this->toViz.free(); //added 2.6.2021, important for memory optimization!
	this->toViz = *toViz.next;
}

void MazeVizualizer::makeMove(const char move) {
	this->toViz.makeMove(move);
}

bool MazeVizualizer::isValidMove(int x, int y) const {
	return toViz.isValidMove(x, y);
}

int MazeVizualizer::getMonsterIndex(int x, int y) const {
	int index = 0;
	for (auto _arg : this->toViz.monstersInMaze) {
		if (_arg->isMonsterLocation(x, y))
			return index;
		index++;
	}
	return -1;
}

int MazeVizualizer::isWeaponMove(int x, int y) const {
	int index = 0;
	for (auto _arg : this->toViz.weaponsInMaze) {
		if (_arg->isWeaponLocation(x, y))
			return index;
		index++;
	}
	return -1;
}

bool MazeVizualizer::isEndMove(int x, int y) const {
	return toViz.isEndMove(x, y);
}

int MazeVizualizer::getX() const
{
	return this->toViz.wid_len_size.c_first();
}

int MazeVizualizer::getY() const {
	return this->toViz.wid_len_size.c_second();
}

int MazeVizualizer::getEndX() const
{
	return this->toViz.end_pos.c_first();
}

int MazeVizualizer::getEndY() const
{
	return this->toViz.end_pos.c_second();
}

void MazeVizualizer::addWepon(int index) {
	this->toViz.m_alice.addWepon(this->toViz.weaponsInMaze[index]);
	this->toViz.weaponsInMaze[index]->obtain();
}

bool MazeVizualizer::isObtained(int index) const {
	return this->toViz.weaponsInMaze[index]->isObtained();
}

Alice& MazeVizualizer::getAlice() {
	return this->toViz.m_alice;
}
void MazeVizualizer::setStartPosAlice() {
	this->toViz.m_alice.setPos(this->toViz.start_pos.first, this->toViz.start_pos.second);
}
monster* MazeVizualizer::getFighter(int ind) {
	return this->toViz.monstersInMaze[ind];
}
