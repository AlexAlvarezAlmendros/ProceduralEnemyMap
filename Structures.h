#pragma once
#include "List.h"

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

struct room
{
	room * north = nullptr;
	room * south = nullptr;
	room * east = nullptr;
	room * west = nullptr;
	List<Enemy> enemyList;
	Player player;
	charbivector map;
	int size;
	int startEnemyNum;
};