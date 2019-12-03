#pragma once
#include "Constants.h"

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

template <class T>
struct room
{
	room<T> * north = nullptr;
	room<T> * south = nullptr;
	room<T> * east = nullptr;
	room<T> * west = nullptr;
};