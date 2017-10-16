#pragma once
class Board
{

private:
	unsigned char *board;
	int size;
	int l_size;

public:
	Board(unsigned char *board, int size, int l_size);
	void CreateBoard(unsigned char bound);
	void RefreshBoard(unsigned char bound);
	unsigned char* GetBoardPtr();
	int GetBoardSize();
	int GetBoardLineSize();
};