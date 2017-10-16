#include "Board.h"

Board::Board(unsigned char *board, int size, int l_size)
{
	this->board = board;
	this->size = size;
	this->l_size = l_size;
}

void Board::CreateBoard(unsigned char bound)
{
	int temp;
	for (int i = 0; i < l_size; i++)
	{
		temp = (i * l_size + l_size - 1);
		for (int j = (i * l_size); j < temp; j++)
		{
			if (i == 0 || i == (l_size - 1) || j == (i * l_size) || j == (temp - 1))
				board[j] = bound;
			else
				board[j] = ' ';
		}
		board[temp] = '\n';
	}
	board[size - 1] = 0;
}

void Board::RefreshBoard(unsigned char bound)
{
	int temp;
	for (int i = 0; i < l_size; i++)
	{
		temp = (i * l_size + l_size - 1);
		for (int j = (i * l_size); j < temp; j++)
		{
			if ((i == 0 || i == (l_size - 1) || j == (i * l_size) || j == (temp - 1)) && board[j] != bound)
				board[j] = bound;
		}
	}
}

unsigned char* Board::GetBoardPtr()
{
	return board;
}
int Board::GetBoardLineSize()
{
	return l_size;
}
int Board::GetBoardSize()
{
	return size;
}