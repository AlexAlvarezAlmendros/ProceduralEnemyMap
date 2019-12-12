#include <ctime>
#include <iostream>

#include "Declarations.h"
#include "Structures.h"



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
	for (size_t i = 0; i < mainPathSize; i++) //GENERACION DE ROOMS
	{
		room auxRoom;
		BasicInitRoom(auxRoom, _difficulty);
		if (i != 0)
		{
			//aqui es donde hay que mirar las puertas
		}

		_level.addItem(auxRoom);
	}
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