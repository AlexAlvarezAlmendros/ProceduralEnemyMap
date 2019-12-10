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