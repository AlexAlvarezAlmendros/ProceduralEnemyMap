#include <ctime>
#include <iostream>

#include "Declarations.h"

char AskDifficulty()
{
	setlocale(LC_ALL, "");
	//FASE 1
	char difficulty;
	bool temporal = true;
	std::cout << "¿Vas a jugar en modo fácil o difícil? (f/m/d)\n Respuesta: ";
	while (temporal)
	{
		std::cin >> difficulty;
		if (difficulty != 'f' && difficulty != 'F' && difficulty != 'd' && difficulty != 'D' && difficulty != 'm' && difficulty != 'M')
		{
			system("CLS");
			std::cout << "Por favor, introduzca una respuesta válida (f/m/d)\n Respuesta: ";
		}
		else
		{
			temporal = false;
		}
	}
	return difficulty;
}

void InitRoomList(List<room> &_level, char &_difficulty, room* &_start, room* &_end)
{
	srand(time(NULL));
	short mainPathSize = rand() % Max_MainPath + Min_MainPath;

	//	FASE 1 DOORS
	for (size_t i = 0; i < mainPathSize; i++) //GENERACION DE ROOMS
	{
		room* room1 = new room();
		BasicInitRoom(*room1, _difficulty);
		if (i != 0)
		{
			room *prevroom = &_level.getFirst()->data;
			room* room2 = new room();
			short random = 4;

			if (i == 1)
			{
				short rands = rand() % 4;
				switch (rands)
				{
				case 0:
					room2->west = prevroom;
					prevroom->east = room2;
					break;
				case 1:
					room2->east = prevroom;
					prevroom->west = room2;
					break;

				case 2:
					room2->south = prevroom;
					prevroom->north = room2;
					break;
				case 3:
					room2->north = prevroom;
					prevroom->south = room2;
					break;
				default:
					break;
				}
			}

			if (prevroom->east != nullptr)
			{
				while (random == 4 || random == 0)
				{
					srand(time(NULL));
					random = rand() % 4;
				}
			}
			else if (prevroom->west != nullptr)
			{
				while (random == 4 || random == 1)
				{
					srand(time(NULL));
					random = rand() % 4;
				}
			}
			else if (prevroom->north != nullptr)
			{
				while (random == 4 || random == 2)
				{
					srand(time(NULL));
					random = rand() % 4;
				}
			}
			else if (prevroom->south != nullptr)
			{
				while (random == 4 || random == 3)
				{
					srand(time(NULL));
					random = rand() % 4;
				}
			}

			switch (random)
			{
			case 0:
				room2->west = prevroom;
				prevroom->east = room2;
				break;
			case 1:
				room2->east = prevroom;
				prevroom->west = room2;
				break;

			case 2:
				room2->south = prevroom;
				prevroom->north = room2;
				break;

			case 3:
				room2->north = prevroom;
				prevroom->south = room2;
				break;
			default:
				break;
			}
			if (i == mainPathSize - 1)
			{
				_end = room1;
			}
			_level.addItem(*room2);
		}
		else
		{
			_level.addItem(*room1);
			_start = &_level.getFirst()->data;
		}
		if (i == mainPathSize--)
		{
			_end = &_level.getFirst()->data;
		}
	}
	return;
}

void BasicInitRoom(room &_room, char &_difficulty)
{
	SetDifficulty(_room, _difficulty);

	InitEnemyList(_room.enemyList, _room.startEnemyNum, _room.size);

	_room.map.resize(_room.size);
	for (size_t i = 0; i < _room.size; i++)
	{
		_room.map[i].resize(_room.size);
		for (size_t j = 0; j < _room.size; j++)
		{
				_room.map[i][j] = ' ';
		}
	}
	_room.player.pos.X = _room.size / 2;
	_room.player.pos.Y = _room.size / 2;
}

int SetDifficulty(room &_room, char &_difficulty)
{
	srand(time(NULL));
	_room.size = rand() % 10 + 20;

	switch (_difficulty)
	{
	case 'f':
	case 'F':
		_room.startEnemyNum = rand() % 3 + 1;
		break;
	case 'm':
	case 'M':
		_room.startEnemyNum = rand() % 6 + 3;
		break;
	case 'd':
	case 'D':
		_room.startEnemyNum = rand() % 8 + 6;
		break;
	default:
		break;
	}
	return _room.startEnemyNum;
}

void InitEnemyList(List<Enemy> &_enemyList, int _enemyNum, int _size)
{
	Enemy p;

	for (int i = 0; i < _enemyNum; i++)
	{
		p.pos.X = rand() % (_size - 2) + 1;

		p.pos.Y = rand() % (_size - 2) + 1;

		_enemyList.addItem(p);
	}
	for (int i = 0; i < _enemyNum; i++)
	{
		Enemy Aux1 = _enemyList.getItem(i);
		for (int j = i + 1; j < _enemyNum; j++)
		{
			Enemy Aux2 = _enemyList.getItem(j);
			if (Aux1.pos.X == Aux2.pos.X && Aux1.pos.Y == Aux2.pos.Y)
			{
				Aux1.pos.X = rand() % (_size - 2) + 1;
				Aux1.pos.Y = rand() % (_size - 2) + 1;
			}
		}
	}
};