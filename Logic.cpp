#include <string>
#include <iostream>
#include <ctime>

#include "List.h"
#include "Declarations.h"
#include "Structures.h"

void randPos(Enemy & _p, int _i)
{
	_p.pos.X = (rand() % 20 + 5) / (_i + 1);
	_p.pos.Y = (rand() % 20 + 5) / (_i + 1);
	return;
};

void initList(List<Enemy> & _ballsList)
{
	Enemy p;

	for (int i = 0; i < 5; i++)
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
	std::cout << "\n";
	for (size_t i = 0; i < w ; i++)
	{
		if (i == w / 2)				//
		{							//
			std::cout << " ";		//	PUERTA IZQUIERDA
		}
		else if (i != w - w)		//
		{							//
			std::cout << '|';		//	PARED IZQUIERDA
		}
		for (size_t j = 0; j < h; j++)
		{
			if (i == w - w || i == w - 1)	//
			{								//
				std::cout << '_';			//	TECHO Y SUELO
			}
			else							//
			{								//
				std::cout << map[i][j];		//	MAPA
			}
		}
		if (i == w / 2)					//
		{								//
			std::cout << ' ' << "\n";	//	PUERTA DERECHA
		}
		else							//
		{								//
			std::cout << "|\n";			//	PARED DERECHA
			//std::cout << "\n";		//	SIN PARED DERECHA
		}
	}
}

void checkMapBalls(char(&map)[width][heigth], List<Enemy> &_ballsList, const int w, const int h)
{
	Enemy bAux;
	Enemy bAux2;
	int NumBalls = 0;
	int AuxNumBalls;
	AuxNumBalls = _ballsList.getLength();

	std::cout << "\n";
	for (size_t i = 0; i < w; i++)
	{
		for (size_t j = 0; j < h; j++)
		{
			if (map[i][j] == bAux.skin)
			{
				NumBalls++;
				std::cout << "BOLA " << NumBalls << ". X=" << j << " Y=" << i << "\t";
			}
			else if (map[i][j] != bAux.skin)
			{
				size_t lul = 0;
				for (int o = 0; o < AuxNumBalls - 1; o++)
				{
					lul++;
					bAux2 = _ballsList.getItem(lul);
					if (map[i][j] != bAux2.skin && i == bAux2.pos.X && j == bAux2.pos.Y)
					{
						_ballsList.removeItem(lul);
						return;
					}
				}
			}
		}
	}
	int BallsDestroyed = 0;
	std::cout << std::endl << "Total bolas: " << NumBalls << std::endl << "Bolas conseguidas: " << BallsDestroyed << std::endl;
}

//void checkDoors(char(&map)[width][heigth], const int w, const int h)
//{
//	if ( )
//}