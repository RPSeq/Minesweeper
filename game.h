//Game class

#ifndef GAME_H
#define GAME_H

#include <iostream>
#include "grid.h"
#include "player.h"

class game
{
private:
	int m_moves;
	bool m_running;
	grid* m_field;
	player m_player;
public:
	game();
	~game() {};
	bool start();
	int moves() {return m_moves;};
	bool running() {return m_running;};
};

#endif
