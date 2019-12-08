#include <iostream>
#include <time.h>
#include "List.h"

int playerhp = 10;

const short Min_MainPath = 5;
const short Max_MainPath = 10;
const short MinRamificationLength = 2;
const short MaxRamificationLength = 5;
const short MinRamifications = 0;
const short MaxRamifications = 1;

struct Position2D
{
	int X, Y;
};

struct Player
{
	char skin = 'O';
	Position2D pos;
};

struct Enemy
{
	char skin = 'X';
	Position2D pos;
};

void randPos(Enemy & _p, int _i)
{
	srand(time(NULL));
	_p.pos.X = (rand() % 20 + 5) / (_i + 1);
	_p.pos.Y = (rand() % 20 + 5) / (_i + 1);
	return;
};

struct room
{
	room * north = nullptr;
	room * south = nullptr;
	room * east = nullptr;
	room * west = nullptr;
	List<Enemy> enemyList;
	Player player;
	const int size = rand() + 15 % 50;
};

int main()
{
	//FASE 1
	short mainPathSize = rand() % Max_MainPath + Min_MainPath;
	List<room> roomList;
	room auxroom;
	for (size_t i = 0; i < mainPathSize; i++) //GENERACION DE ROOMS
	{	
		roomList.addItem(auxroom);
		if (i != 0)
		{
			srand(time(NULL));
			auxroom.size;
		}
	}
}