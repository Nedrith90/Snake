#pragma once


struct  snake
{
	int pos;
	snake *next;
};

class Logic
{
private:
	snake *head;
	int size;
	int l_size;
	int move;

public:
	Logic(int size, int l_size);
	void Move();
	int CheckCollision(unsigned char *board, unsigned char bound, unsigned char snake_chunk, unsigned char apple);
	void SetRandomApplePos(unsigned char *board, unsigned char apple);
	void SetMoveDirection(int move);
	void AddNewSnakeChunk(unsigned char *board);
	void AddSnakeToBoard(unsigned char *board, unsigned char snake_chunk);
};