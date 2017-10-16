#include "Logic.h"
#include <stdlib.h>
#include <time.h>
#include <iostream>

Logic::Logic(int size, int l_size)
{
	this->l_size = l_size;
	this->size = size;
	head = new snake;
	head->next = NULL;
	head->pos = (((l_size / 2) * l_size) + (l_size / 2));
	move = -50;
}

void Logic::AddNewSnakeChunk(unsigned char *board)
{
	snake *temp = new snake;
	int newChunkPos = head->pos;

	/*if (board[(newChunkPos + l_size)] == ' ' && (newChunkPos + l_size) < l_size)
	{
		temp->pos = (newChunkPos + l_size);
		temp->next = head;
		head = temp;
		return;
	}
	if (board[(newChunkPos - l_size)] == ' ' && (newChunkPos - l_size) > 0)
	{
		temp->pos = (newChunkPos - l_size);
		temp->next = head;
		head = temp;
		return;
	}
	if (board[(newChunkPos + 1)] == ' ' && (newChunkPos + 1) < l_size)
	{
		temp->pos = (newChunkPos + 1);
		temp->next = head;
		head = temp;
		return;
	}
	if (board[(newChunkPos - 1)] == ' ' && (newChunkPos - 1) > 0)
	{
		temp->pos = (newChunkPos - 1);
		temp->next = head;
		head = temp;
		return;
	}*/
	temp->pos = (newChunkPos + (-move));
	temp->next = head;
	head = temp;
	return;
}

void Logic::AddSnakeToBoard(unsigned char *board, unsigned char snake_chunk)
{
	snake *tmp = new snake;
	tmp = head;

	for (int i = 0; i < size; i++)
	{
		if (board[i] == snake_chunk)
			board[i] = ' ';
	}

	while(1)
	{
		board[tmp->pos] = snake_chunk;
		if (tmp->next == NULL)
			break;
		tmp = tmp->next;
	} 
}

void Logic::Move()
{
	snake *tmp = new snake;
	tmp = head;
	while (1)
	{
		if (tmp->next != NULL)
		{
			tmp->pos = tmp->next->pos;
			tmp = tmp->next;
		}
		else
		{
			tmp->pos += move;
			break;
		}
	}
}

int Logic::CheckCollision(unsigned char *board, unsigned char bound, unsigned char snake_chunk, unsigned char apple)
{
	snake *tmp = new snake;
	tmp = head;

	while (1)
	{
		if (tmp->next != NULL)
			tmp = tmp->next;
		else
			break;
	}

	if (board[tmp->pos] == bound || board[tmp->pos] == snake_chunk)
		return 1;
	if (board[tmp->pos] == apple)
		return 2;

	return 0;
}

void Logic::SetRandomApplePos(unsigned char *board, unsigned char apple)
{
	srand(time(NULL));
	int posX;
	int posY;
	int pos;
	do {
		posX = rand() % (l_size - 1) + 1;
		posY = rand() % (l_size - 1) + 1;
		pos = posY*l_size + posX;
	} while (board[pos] != ' ');
	board[pos] = apple;
}

void Logic::SetMoveDirection(int move)
{
	this->move = move;
}