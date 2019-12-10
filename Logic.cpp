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

void initList(List<Enemy> & _enemyList)
{
	Enemy p;

	for (int i = 0; i < 5; i++)
	{
		randPos(p, i);

		_enemyList.addItem(p);
	}
	return;
}
void enemyIntoMap(char(&_map)[width][heigth], List<Enemy> _enemyList)
{
	int auxLength = _enemyList.getLength();
	Enemy aux;
	for (size_t i = 0; i < auxLength; i++)
	{
		aux = _enemyList.getItem(i);

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
			if ((i == w - w && j != h / 2) || (i == w - 1 && j != h / 2))
			{	
				if (j + 1== h)
				{
					std::cout << "º\n";		//	ULTIMA CASILLA DEL TEJADO
				}
				else if (j != h)
				{
					std::cout << 'º';		//	PUERTA TECHO Y TECHO && PUERTA SUELO Y SUELO
				}
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
		else if (i != 0)				//
		{	
			if (i+1 == w)
			{
				std::cout << "\n";
			}
			else
			{
				std::cout << "|\n";			//	PARED DERECHA
			}
			//std::cout << "\n";		//	SIN PARED DERECHA
		}
	}
}


void checkMapBalls(char(&map)[width][heigth], List<Enemy> &_enemyList, const int _characterX, const int _characterY, int &vplayerh)
{
	Enemy bAux;
	int NumBalls = _enemyList.getLength();
	for (int i = 0; i < _enemyList.getLength(); i++)
	{
		bAux = _enemyList.getItem(i);
		if (map[_characterX][_characterY] != bAux.skin && (_characterX == bAux.pos.X && _characterY == bAux.pos.Y))
		{
			_enemyList.removeItem(i);
			vplayerh--;
			NumBalls--;
			return;
		}
	}
	std::cout << std::endl << "Total bolas: " << NumBalls << std::endl << "Vida: " << vplayerh << std::endl;
}

void checkDoors(char(&map)[width][heigth], const int w, const int h, int _characterX, int _characterY)
{
	if (map[w / 2][h - h - 1] == 'O' && (_characterX == w / 2 && _characterY == h - h - 1))		//	COMPRUEBA LA PUERTA IZQUIERDA
	{																							//
		std::cout << "Puerta izquierda";														//	INDICA LA PUERTA IZQUIERDA
	}
	else if (map[w / 2][h] == 'O' && (_characterX == w / 2 && _characterY == h))				//	COMPRUEBA LA PUERTA DERECHA
	{																							//
		std::cout << "Puerta derecha";															//	INDICA LA PUERTA DERECHA
	}
	else if (map[w][h / 2] == 'O' && (_characterX == w && _characterY == h / 2))				//	COMPRUEBA LA PUERTA INFERIOR
	{																							//
		std::cout << "Puerta inferior";															//	INDICA LA PUERTA INFERIOR
	}
	else if (map[w - w][h / 2 + 1] == 'O' && (_characterX == w - w && _characterY == h / 2 + 1))//	COMPRUEBA LA PUERTA SUPERIOR
	{																							//
		std::cout << "Puerta superior";															//	INDICA LA PUERTA SUPERIOR
	}
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
