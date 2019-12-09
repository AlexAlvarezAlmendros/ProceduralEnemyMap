#include <ctime>

#include "Declarations.h"
#include "Structures.h"

void InitGame(room &_room, char &_difficulty)
{
	srand(time(NULL));
	_room.size = rand() % 50 + 20;

	switch (_difficulty)
	{
	case 'f':
	case 'F':
		_room.startEnemyNum = 1 + (rand() % 3);
		break;
	case 'm':
	case 'M':
		_room.startEnemyNum = 3 + (rand() % (6 - 2));
		break;
	case 'd':
	case 'D':
		_room.startEnemyNum = 5 + (rand() % (8 - 4));
		break;
	default:
		break;
	}
}

void basicInitRoom(room &_room)
{
	_room.map.resize(_room.size);
	for (size_t i = 0; i < _room.size; i++)
	{
		_room.map[i].resize(_room.size);
		for (size_t j = 0; j < _room.size; j++)
		{
			if (i == 0 || j == 0 || i == _room.size - 1 || j == _room.size - 1)
			{
				_room.map[i][j] = '#';
			}
			else
			{
				_room.map[i][j] = ' ';
			}
		}
	}
	_room.player.pos.X = _room.size / 2;
	_room.player.pos.Y = _room.size / 2;
}

void randPos(room &_room, Enemy &_p)
{
	Enemy auxenemy;
	for (size_t i = 0; i < _room.startEnemyNum; i++)
	{
		srand(time(NULL));
		auxenemy.pos.X = rand() % _room.size;
		srand(time(NULL));
		auxenemy.pos.Y = rand() % _room.size;
		_room.enemyList.addItem(auxenemy);
	}
}


// prueba
void initMap(char(&map)[width][heigth], const int w, const int h)
{
	for (size_t i = 0; i < w; i++)
	{
		for (size_t j = 0; j < h; j++)
		{
			map[i][j] = ' ';
		}
	}
}