#pragma once
#include "Constants.h"
#include <vector>

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
	char skin = enemySkin;
	Position2D pos;
};

struct room
{

	room * north = nullptr;
	room * south = nullptr;
	room * east = nullptr;
	room * west = nullptr;
	Player player;
	List<Enemy> enemyList;
	int size = rand() + 15 % 50;
	vectorbi map;
};


