#pragma once
#include "Constants.h"
#include <vector>
#include "List.h"
#include "Array.h"

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
	const int size = rand() + 15 % 50;
	Array map;

	void initList(List<Enemy> _enemyList)
	{
		Enemy p;

		for (int i = 0; i < 5; i++)
		{
			randPos(p, i);
			_enemyList.addItem(p);
		}
		return;
	};

	/*void ballsIntoMap(Array(&_map), List<Enemy> _ballsList)
	{
		int auxLength = _ballsList.getLength();
		Enemy aux;
		for (size_t i = 0; i < auxLength; i++)
		{
			aux = _ballsList.getItem(i);
			_map[aux.pos.X][aux.pos.Y] = aux.skin;
		}
	};*/
};