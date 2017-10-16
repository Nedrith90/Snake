#pragma once

#include "Logic.h"
#include "Board.h"

class Game
{
private:
	Logic *l;
	Board *b;

	unsigned char bound;
	unsigned char snake;
	unsigned char apple;

	bool blockX;
	bool blockY;

	int l_size;

public:
	Game(unsigned char *board, int size, int l_size, unsigned char bound, unsigned char snake, unsigned char apple);
	void Start();
	void End();
	void Move();
	void Draw();
};