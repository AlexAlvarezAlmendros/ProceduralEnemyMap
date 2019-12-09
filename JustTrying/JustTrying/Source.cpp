#include <iostream>
#include <time.h>
#include "List.h"
#include <vector>

typedef std::vector<std::vector<char>> charbivector;
int playerhp = 10;

const short Min_MainPath = 5;
const short Max_MainPath = 10;
const short MinRamificationLength = 2;
const short MaxRamificationLength = 5;
const short MinRamifications = 0;
const short MaxRamifications = 1;

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

void randPos(Enemy & _p, int _i)
{
	srand(time(NULL));
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
	List<Enemy> enemyList;
	Player player;
	charbivector map;
	int size;
	int startEnemyNum;

	void basicInitRoom(char &_difficulty)
	{
		srand(time(NULL));
		size = rand() % 50 + 20;

		switch (_difficulty)
		{
		case 'f':
		case 'F':
			startEnemyNum = 1 + (rand() % 3);
			break;
		case 'm':
		case 'M':
			startEnemyNum = 3 + (rand() % (6 -2));
			break;
		case 'd':
		case 'D':
			startEnemyNum = 5 + (rand() % (8 - 4));
			break;
		default:
			break;
		}

		Enemy auxenemy;
		for (size_t i = 0; i < startEnemyNum; i++)
		{
			srand(time(NULL));
			auxenemy.pos.X = rand() % size;
			srand(time(NULL));
			auxenemy.pos.Y = rand() % size;
			enemyList.addItem(auxenemy);
		}

		map.resize(size);
		for (size_t i = 0; i < size; i++)
		{
			map[i].resize(size);
			for (size_t j = 0; j < size; j++)
			{
				if (i == 0 || j == 0 || i == size - 1 || j == size - 1)
				{
					map[i][j] = '#';
				}
				else
				{
					map[i][j] = ' ';
				}
			}
		}
		player.pos.X = size / 2;
		player.pos.Y = size / 2;
	}
};

void drawMap(charbivector(&map), int _size)
{
	system("cls");
	std::cout << '|';
	for (size_t i = 0; i < _size; i++)
	{
		for (size_t j = 0; j < _size; j++)
		{
			std::cout << map[i][j];
		}
		std::cout << "\n";
	}
	std::cout << "\n Size = " << _size;
}

int main()
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
	srand(time(NULL));
	short mainPathSize = rand() % Max_MainPath + Min_MainPath;
	List<room> roomList;
	room auxroom;
	for (size_t i = 0; i < mainPathSize; i++) //GENERACION DE ROOMS
	{
		auxroom.basicInitRoom(difficulty);
		if (i != 0)
		{
			
			//aqui es donde hay que mirar las puertas
		}

		roomList.addItem(auxroom);
	}
	drawMap(roomList.getFirst()->data.map, roomList.getFirst()->data.size);

	return 0;
}