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

//template <class T>
//struct Door
//{
//	Door<T> * north;
//	Door<T> * south;
//	Door<T> * east;
//	Door<T> * west;
//};
//
//template <class T>
//struct Room
//{
//	Door<T> * doors;
//	Player player;
//	List<Enemy> enemyList;
//	int width, heigth;
//	char map[width][heigth];
//};