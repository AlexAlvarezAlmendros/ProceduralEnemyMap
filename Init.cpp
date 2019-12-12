#include <ctime>
#include <iostream>

#include "Declarations.h"

char AskDifficulty()
{
	setlocale(LC_ALL, "");
	//FASE 1
	char difficulty;
	bool temporal = true;
	std::cout << "�Vas a jugar en modo f�cil o dif�cil? (f/m/d)\n Respuesta: ";
	while (temporal)
	{
		std::cin >> difficulty;
		if (difficulty != 'f' && difficulty != 'F' && difficulty != 'd' && difficulty != 'D' && difficulty != 'm' && difficulty != 'M')
		{
			system("CLS");
			std::cout << "Por favor, introduzca una respuesta v�lida (f/m/d)\n Respuesta: ";
		}
		else
		{
			temporal = false;
		}
	}
	return difficulty;
}

void InitRoomList(List<room> &_level, char &_difficulty)
{
	srand(time(NULL));
	short mainPathSize = rand() % Max_MainPath + Min_MainPath;

	//	FASE 1 DOORS
	room room1;
	for (size_t i = 0; i < mainPathSize; i++) //GENERACION DE ROOMS
	{

		BasicInitRoom(room1, _difficulty);
		if (i != 0)
		{
			room *prevroom = &_level.getFirst()->data;
			room room2;
			short random = 4;

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
				room2.west = prevroom;
				prevroom->east = &room2;

				break;
			case 1:
				room2.east = prevroom;
				prevroom->west = &room2;

				break;

			case 2:
				room2.south = prevroom;
				prevroom->north = &room2;

				break;

			case 3:
				room2.north = prevroom;
				prevroom->south = &room2;

				break;
			default:
				break;
			}
			if (i == mainPathSize - 1)
			{
				end = &room1;
			}
			_level.addItem(room2);
		}
		else
		{
			_level.addItem(room1);
			start = &_level.getFirst()->data;
		}
		if (i == mainPathSize - 1)
		{
			end = &_level.getFirst()->data;
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

int SetDifficulty(room &_room, char &_difficulty)
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
	return _room.startEnemyNum;
}

void InitEnemyList(List<Enemy> &_enemyList, int _enemyNum, int _size)
{
	Enemy p;

	for (int i = 0; i < _enemyNum; i++)
	{
		srand(time(NULL));
		p.pos.X = rand() % _size;
		srand(time(NULL));
		p.pos.Y = rand() % _size;

		_enemyList.addItem(p);
	}
	return;
};