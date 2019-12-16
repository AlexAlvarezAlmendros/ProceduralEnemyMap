#include <ctime>
#include <iostream>
#include <thread>
#include <array>
#include <conio.h>

#include "Declarations.h"

double clockToMilliseconds(clock_t ticks) {
	// units/(units/time) => time (seconds) * 1000 = milliseconds
	return (ticks / (double)CLOCKS_PER_SEC) * 1000.0;
}
//...

void enemyIntoMap(room &_room)
{
	Enemy aux;
	short length = _room.enemyList.getLength();
	for (size_t i = 0; i < length; i++)
	{
		aux = _room.enemyList.getItem(i);
		_room.map[aux.pos.X][aux.pos.Y] = aux.skin;
	}
}

void drawMap(room &_room)
{
	short int roomSize = _room.size;
	system("cls");
	std::cout << "\n";
	for (size_t i = 0; i < roomSize; i++)
	{
		for (size_t j = 0; j < roomSize; j++)
		{
			if ((i == 0 /*roomSize - roomSize*/ && j != roomSize / 2) || (i == roomSize - 1 && j != roomSize / 2))
			{
				if (j + 1 == _room.size)
				{
					//	ultima casilla del tejado
					std::cout << "º\n";
				}
				else if (j == 0 /*roomSize - roomSize*/ && i == 0 /*roomSize - roomSize*/)
				{
					std::cout << " ";
				}
				else if (j != roomSize)
				{
					//	PUERTA TECHO Y TECHO && PUERTA SUELO Y SUELO
					std::cout << 'º';
				}
			}
			else if (i != roomSize / 2 && j == 0)
			{
				
				//	PARED Y PUERTA IZQUIERDA
				std::cout << '|';
			}
			else
			{
				//	MAPA
				std::cout << _room.map[i][j];
			}
		}
		if (i == roomSize / 2)
		{
			//	PUERTA DERECHA
			std::cout << ' ' << "\n";
		}
		else if (i != roomSize / 2 && i != 0)
		{
			if (i + 1 == roomSize)
			{
				std::cout << "\n";
			}
			else
			{
				//	PARED DERECHA
				std::cout << "|\n";
			}
			//	SIN PARED DERECHA
			//std::cout << "\n";
		}
	}
}


void checkMapBalls(room &_room)
{
	Enemy bAux;
	/*int NumBalls = 0;*/
	for (size_t i = 0; i < _room.enemyList.getLength(); i++)
	{
		bAux = _room.enemyList.getItem(i);
		if (_room.map[_room.player.pos.X][_room.player.pos.Y] != bAux.skin && (_room.player.pos.X == bAux.pos.X && _room.player.pos.Y == bAux.pos.Y))
		{
			_room.enemyList.removeItem(i);
			return;
		}
	}
	/*int BallsDestroyed = 0;
	std::cout << std::endl << "Total bolas: " << NumBalls << std::endl << "Bolas conseguidas: " << BallsDestroyed << std::endl;*/
}

void checkDoors(room &_room)
{
	//	COMPRUEBA LA PUERTA IZQUIERDA
	if (_room.player.pos.X == _room.size / 2 && _room.player.pos.Y == _room.size - _room.size)
	{
		//	INDICA LA PUERTA IZQUIERDA
		std::cout << "Puerta izquierda";
	}
	//	COMPRUEBA LA PUERTA DERECHA
	else if (_room.player.pos.X == _room.size / 2 && _room.player.pos.Y == _room.size)
	{
		//	INDICA LA PUERTA DERECHA
		std::cout << "Puerta derecha";
	}
	//	COMPRUEBA LA PUERTA INFERIOR
	else if (_room.player.pos.X == _room.size - 1 && _room.player.pos.Y == _room.size / 2)
	{
		//	INDICA LA PUERTA INFERIOR
		std::cout << "Puerta inferior";
	}
	//	COMPRUEBA LA PUERTA SUPERIOR
	else if (_room.player.pos.X == _room.size - _room.size && _room.player.pos.Y == _room.size / 2)
	{
		//	INDICA LA PUERTA SUPERIOR
		std::cout << "Puerta superior";
	}
}

room *FrameRate(room &_room, int &_playerhp)
{
	room *nextRoom;
	clock_t timer = 0;
	clock_t time = 0;
	clock_t deltaTime;
	unsigned int frames = 0;
	double frameRate = 120;

	while (true) {

		std::chrono::high_resolution_clock::time_point beginFrame = std::chrono::high_resolution_clock::now();
		std::this_thread::sleep_for(std::chrono::milliseconds(10));
		int c = 0;
		enemyIntoMap(_room);

		if (_kbhit()) {
			switch ((c = _getch())) {

			case KEY_UP:
			case KEY_W:
			case KEY_w:
				if (_room.player.pos.X > _room.size - _room.size + 1)
				{
					_room.map[_room.player.pos.X][_room.player.pos.Y] = ' ';
					_room.player.pos.X--;
				}
				else if (_room.player.pos.Y == _room.size / 2 && _room.player.pos.X == _room.size - _room.size + 1)
				{
					_room.map[_room.player.pos.X][_room.player.pos.Y] = ' ';
					_room.player.pos.X--;
				}
				std::cout << std::endl << "Up" << std::endl; //key up
				break;

			case KEY_DOWN:
			case KEY_S:
			case KEY_s:
				if (_room.player.pos.X < _room.size - 2)
				{
					_room.map[_room.player.pos.X][_room.player.pos.Y] = ' ';
					_room.player.pos.X++;
				}
				else if (_room.player.pos.Y == _room.size / 2 && _room.player.pos.X < _room.size - 1)
				{
					_room.map[_room.player.pos.X][_room.player.pos.Y] = ' ';
					_room.player.pos.X++;
				}
				std::cout << std::endl << "Down" << std::endl; // key down
				break;

			case KEY_LEFT:
			case KEY_A:
			case KEY_a:
				if (_room.player.pos.Y > _room.size - _room.size + 1)
				{
					_room.map[_room.player.pos.X][_room.player.pos.Y] = ' ';
					_room.player.pos.Y--;
				}
				else if (_room.player.pos.Y > _room.size - _room.size && _room.player.pos.X == _room.size / 2)
				{
					_room.map[_room.player.pos.X][_room.player.pos.Y] = ' ';
					_room.player.pos.Y--;
				}
				std::cout << std::endl << "Left" << std::endl; // key left
				break;

			case KEY_RIGHT:
			case KEY_D:
			case KEY_d:
				if (_room.player.pos.Y < _room.size - 1)
				{
					_room.map[_room.player.pos.X][_room.player.pos.Y] = ' ';
					_room.player.pos.Y++;
				}
				else if (_room.player.pos.Y < _room.size && _room.player.pos.X == _room.size / 2)
				{
					_room.map[_room.player.pos.X][_room.player.pos.Y] = ' ';
					_room.player.pos.Y++;
					std::cout << "Puerta derecha";
				}
				std::cout << std::endl << "Right" << std::endl; // key right
				break;

			case KEY_F5:
				//initMap(map, 25, 25);
				std::cout << std::endl << "CLEAR PATH" << std::endl; // clear path from screen
				break;

			default:

				std::cout << std::endl << c << "null" << std::endl; // not arrow

				break;
			}
		}
		_room.map[_room.player.pos.X][_room.player.pos.Y] = 'O';

		system("cls");
		drawMap(_room);
		checkMapBalls(_room);
		checkDoors(_room);

		std::chrono::high_resolution_clock::time_point endFrame = std::chrono::high_resolution_clock::now();

		deltaTime = std::chrono::duration_cast<std::chrono::milliseconds>(endFrame - beginFrame).count();
		timer += deltaTime;
		time += deltaTime;
		frames++;
		std::cout << "\nDelta Time: " << deltaTime / 1000.0f;
		std::cout << "\nTiempo: " << time / 1000.0f;
		std::cout << "\nX: " << _room.player.pos.X << " Y: " << _room.player.pos.Y;
		std::cout << "\nRoom Size: " << _room.size;
		std::cout << "\nList length: " << _room.enemyList.getLength() << std::endl;
		//if you really want FPS
		if (timer >= 1000.0) { //every second
			std::cout << "Frames:" << frames << std::endl;
			timer = 0.0f;
			frames = 60;


		}
		/*FrameRate Limit*/
		else if (frames >= frameRate)
		{
			std::cout << "Wait" << std::endl;
			std::this_thread::sleep_for(std::chrono::milliseconds((long)(1000.0f - timer)));
			time += 1000.0f - timer;
			frames = 0;
			timer = 0.0f;
		}
	}
	//ballsList.clear();
	return nextRoom;
}