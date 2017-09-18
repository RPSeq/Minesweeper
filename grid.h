//Grid class

#ifndef GRID_H
#define GRID_H

#include <iostream>
#include <vector>
#include "panel.h"

class grid	//Represents a grid of minesweeper panels.
{
private:
	int width;
	int height;
	int mines;
	int cleared_count;
	bool m_win;
	bool m_lose;
	std::vector<panel*> array;
	
public:
	grid(int x, int y, int n);
	grid();
	~grid();
	panel* index(int x, int y);
	int get_width() {return width;};
	int get_height() {return height;};
    void minecount(int x, int y);
    void uncover(int x, int y);
    void expand(int x, int y);
    void display();
	bool win() { return m_win;};
	bool lose() { return m_lose;};
};

#endif
