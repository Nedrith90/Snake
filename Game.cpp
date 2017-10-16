#include "Game.h"
#include <windows.h>
#include <iostream>
#include <stdlib.h>
#include <time.h>

Game::Game(unsigned char *board, int size, int l_size, unsigned char bound, unsigned char snake, unsigned char apple)
{
	this->b = new Board(board, size, l_size);
	this->l = new Logic(size, l_size);
	this->l_size = l_size;
	this->bound = bound;
	this->apple = apple;
	this->snake = snake;
	blockX = false;
	blockY = true;
}

void Game::Start()
{
	b->CreateBoard(bound);
	int col = 0;
	l->SetRandomApplePos(b->GetBoardPtr(), apple);
	while (1) 
	{
		Move();
		l->Move();
		col = l->CheckCollision(b->GetBoardPtr(), bound, snake, apple);
		if (col == 1)
		{
			End();
			break;
		}
		if (col == 2)
		{
			l->SetRandomApplePos(b->GetBoardPtr(), apple);
			l->AddNewSnakeChunk(b->GetBoardPtr());
		}
		l->AddSnakeToBoard(b->GetBoardPtr(), snake);
		Draw();
		Sleep(100);
	}
}

void Game::End()
{
	system("cls");
	std::cout << "\t\t\t\tGAME OVER!!!!! \n" << std::endl;
	std::cin.get();
	exit(0);
}

void Game::Move()
{
	if ((GetAsyncKeyState(0x57) || GetAsyncKeyState(VK_UP)) && blockY == false)
	{
		l->SetMoveDirection(-l_size);
		blockY = true;
		blockX = false;
	}
	if ((GetAsyncKeyState(0x53) || GetAsyncKeyState(VK_DOWN)) && blockY == false)
	{
		l->SetMoveDirection(l_size);
		blockY = true;
		blockX = false;
	}
	if ((GetAsyncKeyState(0x41) || GetAsyncKeyState(VK_LEFT)) && blockX == false)
	{
		l->SetMoveDirection(-1);
		blockX = true;
		blockY = false;
	}
	if ((GetAsyncKeyState(0x44) || GetAsyncKeyState(VK_RIGHT)) && blockX == false)
	{
		l->SetMoveDirection(1);
		blockX = true;
		blockY = false;
	}
}

void Game::Draw()
{
	system("cls");
	b->RefreshBoard(bound);
	std::cout << b->GetBoardPtr();
}