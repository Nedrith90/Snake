#include <iostream>
#include "Game.h"

#define SIZE 30

int main()
{
	Game g(new unsigned char[SIZE*SIZE + 1], SIZE*SIZE + 1, SIZE, '*', 'H', 'a'); //plansza potrzebuje dodatkowego pola dla terminatora ciagu dlatego SIZE*SIZE+1
	g.Start();
	return 0;
}