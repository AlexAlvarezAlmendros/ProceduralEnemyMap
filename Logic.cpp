#include <string>
#include <iostream>
#include <ctime>

#include "List.h"
#include "Declarations.h"
#include "Structures.h"


void initList(List<Enemy> & _ballsList, int _p)
{
	Enemy p;

	for (int i = 0; i < _p; i++)
	{
		randPos(p, i);
		_ballsList.addItem(p);
	}
	return;
};

void ballsIntoMap(char(&_map)[width][heigth], List<Enemy> _ballsList)
{
	int auxLength = _ballsList.getLength();
	Enemy aux;
	for (size_t i = 0; i < auxLength; i++)
	{
		aux = _ballsList.getItem(i);
		_map[aux.pos.X][aux.pos.Y] = aux.skin;
	}
};

double clockToMilliseconds(clock_t ticks) {
	// units/(units/time) => time (seconds) * 1000 = milliseconds
	return (ticks / (double)CLOCKS_PER_SEC)*1000.0;
}
//...

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

void drawMap(char(&map)[width][heigth], const int w, const int h)
{
	system("cls");
	/*std::cout << '|';*/
	for (size_t i = 0; i < w; i++)
	{
		//	CON MARCO
		std::cout << '|';
		for (size_t j = 0; j < h; j++)
		{
			std::cout << map[i][j];
		}
		//	CON MARCO
		std::cout << "|\n";
		//	SIN MARCO
		//std::cout << "\n";
	}
}

void checkMapBalls(char(&map)[width][heigth], List<Enemy> _ballsList, const int w, const int h)
{
	Enemy bAux;
	Enemy bAux2;
	int NumBalls = 0;
	int AuxNumBalls;
	AuxNumBalls = _ballsList.getLength();
	int AuxLength = _ballsList.getLength();

	std::cout << "\n";
	for (size_t i = 0; i < w; i++)
	{
		for (size_t j = 0; j < h; j++)
		{
			if (map[i][j] == bAux.skin)
			{
				NumBalls++;
				std::cout << "BOLA" << NumBalls << ". X=" << j << " Y=" << i << "\t";
			}
			/*else if (map[i][j] != bAux.skin)
			{
				size_t lul = 0;
				for (int o = 0; o < AuxLength - 1; o++)
				{

					bAux2 = _ballsList.getItem(lul);
					if (map[i][j] != bAux2.skin && i == bAux2.pos.X && j == bAux2.pos.Y)
					{
						_ballsList.removeItem(lul);
					}
				}
			}*/
		}
	}


	int BallsDestroyed = AuxNumBalls - NumBalls;
	std::cout << std::endl << "Total bolas: " << NumBalls << std::endl << "Bolas conseguidas: " << BallsDestroyed << std::endl;
}

void enemyMovement(char(&_map)[width][heigth], List<Enemy> &_enemyList, const int _characterX, const int _characterY)
{
	Enemy aux;
	for (size_t i = 0; i < _enemyList.getLength(); i++)
	{

		aux = _enemyList.getItem(i);
		int x = aux.pos.X;
		int y = aux.pos.Y;
		if (_characterX > aux.pos.X and _characterY > aux.pos.Y)
		{
			_map[x][y] = ' ';
			aux.pos.X++;
			aux.pos.Y++;

		}
		else if (_characterX < aux.pos.X and _characterY < aux.pos.Y)
		{
			_map[x][y] = ' ';

			aux.pos.X--;
			aux.pos.Y--;

		}
		else if (_characterY > aux.pos.Y and _characterX < aux.pos.X)
		{
			_map[x][y] = ' ';
			aux.pos.Y++;
			aux.pos.X--;

		}
		else if (_characterY < aux.pos.Y and _characterX > aux.pos.X)
		{
			_map[x][y] = ' ';
			aux.pos.Y--;
			aux.pos.X++;

		}
		else if (_characterY == aux.pos.Y and _characterX < aux.pos.X)
		{
			_map[x][y] = ' ';
			aux.pos.X--;

		}
		else if (_characterY == aux.pos.Y and _characterX > aux.pos.X)
		{
			_map[x][y] = ' ';
			aux.pos.X++;

		}
		else if (_characterY < aux.pos.Y and _characterX == aux.pos.X)
		{
			_map[x][y] = ' ';
			aux.pos.Y--;

		}
		else if (_characterY > aux.pos.Y and _characterX == aux.pos.X)
		{
			_map[x][y] = ' ';
			aux.pos.Y++;

		}
		else
		{
			return;
		}
		_map[aux.pos.X][aux.pos.Y] = aux.skin;
		_enemyList.getItem(i) = aux;

	}
	return;
}