#pragma once
#include "Constants.h"
#include "Declarations.h"



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
	char skin;// = enemySkin;
	Position2D pos;
};

void randPos(Enemy & _p, int _i)
{
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
	Player player;

	List<Enemy> enemyList;
	int size = rand() + 15 % 50;
	Array map;

	//void initList(List<Enemy> _enemyList)
	//{
	//	Enemy p;

	//	for (int i = 0; i < 5; i++)
	//	{
	//		randPos(p, i);
	//		_enemyList.addItem(p);
	//	}
	//	return;
	//};

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

	void Init()
	{
		srand(time(NULL));

		// FASE 1
		short mainPathSize = rand() % Max_MainPath + Min_MainPath;

		char difficulty;
		bool temporal = true;
		std::cout << "¿Vas a jugar en modo fácil o difícil? (f/d)\n Respuesta: ";
		while (temporal)
		{
			std::cin >> difficulty;
			if (difficulty != 'f' && difficulty != 'F' && difficulty != 'd' && difficulty != 'D')
			{
				system("CLS");
				std::cout << "Por favor, introduzca una respuesta válida (f/d)\n Respuesta: ";
			}
			else
			{
				temporal = false;
			}
		}
		return;
	}
};