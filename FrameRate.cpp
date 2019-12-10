<<<<<<< Updated upstream
#include <time.h>
#include <iostream>
#include <thread>
#include <array>
#include <conio.h>

#include "List.h"
#include "Declarations.h"
#include "Structures.h"

int main()
{
	List<Enemy> ballsList;
	initList(ballsList);
	clock_t timer = 0;
	double deltaTime;
	unsigned int frames = 0;
	double  frameRate = 120;
	char map[width][heigth];
	initMap(map,width, heigth);
	int characterX = heigth / 2;
	int characterY = width / 2;
	
	clock_t time = 0;
	while (true) {
		
		std::chrono::high_resolution_clock::time_point beginFrame = std::chrono::high_resolution_clock::now();
		std::this_thread::sleep_for(std::chrono::milliseconds(10));
		int c = 0;
		ballsIntoMap(map, ballsList);

			if (_kbhit()) {
				switch ((c = _getch())) {

				case KEY_UP:
				case KEY_W:
				case KEY_w:
					if (characterX > width - width) 
					{
						map[characterX][characterY] = '|';
						characterX--;
					}
					std::cout << std::endl << "Up" << std::endl; //key up
					break;

				case KEY_DOWN:
				case KEY_S:
				case KEY_s:
					if (characterX < width - 1)
					{
						map[characterX][characterY] = '|';
						characterX++;
					}
					std::cout << std::endl << "Down" << std::endl; // key down
					break;

				case KEY_LEFT:
				case KEY_A:
				case KEY_a:
					if (characterY > heigth - heigth)
					{
						map[characterX][characterY] = '--';
						characterY--;
					}
					std::cout << std::endl << "Left" << std::endl; // key left
					break;

				case KEY_RIGHT:
				case KEY_D:
				case KEY_d:
					if (characterY < heigth-1)
					{
						map[characterX][characterY] = '--';
						characterY++;
					}
					std::cout << std::endl << "Right" << std::endl; // key right
					break;

				case 63:
					initMap(map, 25, 25);
					std::cout << std::endl << "CLEAR PATH" << std::endl; // clear path from screen
					break;

				default:

					std::cout << std::endl << c << "null" << std::endl; // not arrow

					break;

				}
			}
			map[characterX][characterY] = 'O';

			system("cls");
			drawMap(map,width, heigth);
			checkMapBalls(map, ballsList, width, heigth);

			
		std::chrono::high_resolution_clock::time_point endFrame = std::chrono::high_resolution_clock::now();

		deltaTime = std::chrono::duration_cast<std::chrono::milliseconds>(endFrame - beginFrame).count();
		timer += deltaTime;
		time += deltaTime;
		frames++;
		std::cout <<"\nDelta Time: " << deltaTime / 1000.0f << std::endl;
		std::cout << time/1000.0f << std::endl;
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
			 frames = 0;
			 timer = 0.0f;
		 }
	}
	ballsList.clear();
	return 0;
=======
#include <time.h>
#include <iostream>
#include <thread>
#include <array>
#include <conio.h>

#include "List.h"
#include "Constants.h"
#include "Declarations.h"
#include "Structures.h"

int main()
{
	List<Enemy> enemyList;
	initList(enemyList);
	clock_t timer = 0;
	double deltaTime;
	unsigned int frames = 0;
	double  frameRate = 120;
	char map[width][heigth];
	initMap(map,width, heigth);
	enemyIntoMap(map, enemyList);
	int vplayerh = playerhealth;
	int characterX = widthPlayer;
	int characterY = heigthPlayer;

	clock_t time = 0;
	while (true) {
		
		std::chrono::high_resolution_clock::time_point beginFrame = std::chrono::high_resolution_clock::now();
		std::this_thread::sleep_for(std::chrono::milliseconds(10));
		int c = 0;

			if (_kbhit()) {
				switch ((c = _getch())) {

				case KEY_UP:
				case KEY_W:
				case KEY_w:
					if (characterX > width - width + 1)									//
					{																	//
						map[characterX][characterY] = ' ';								//	PINTAR ESTELA
						characterX--;													//	MOVER HACIA ARRIBA
					}
					else if (characterY == heigth / 2 - 1 && characterX == width - width + 1)
					{
						map[characterX][characterY] = ' ';								//	PINTAR ESTELA
						characterX--;													//	MOVER HACIA ARRIBA POR LA PUERTA
					}
					std::cout << std::endl << "Up" << std::endl;						//	KEY UP
					enemyMovement(map, enemyList, characterX, characterY);
					break;

				case KEY_DOWN:
				case KEY_S:
				case KEY_s:
					if (characterX < width - 2)											//
					{																	//
						map[characterX][characterY] = '|';								//	PINTAR ESTELA
						characterX++;													//	MOVER HACIA ABAJO
					}
					else if (characterY == heigth / 2 && characterX <= width)	//
					{																	//
						map[characterX][characterY] = '|';								//	PINTAR ESTELA
						characterX++;													// MOVER HACIA ABAJO POR LA PUERTA
					}
					std::cout << std::endl << "Down" << std::endl;						//	KEY DOWN
					enemyMovement(map, enemyList, characterX, characterY);
					break;

				case KEY_LEFT:
				case KEY_A:
				case KEY_a:
					if (characterY > heigth - heigth)									//
					{																	//
							map[characterX][characterY] = '--';							//	PINTAR ESTELA
							characterY--;												//	MOVER HACIA LA IZQUIERDA
					}
					else if (characterY == heigth - heigth && characterX == width / 2)	//
					{																	//
						map[characterX][characterY] = '--';								//	PINTAR ESTELA
						characterY--;													//	MOVER HACIA LA IZQUIERDA POR LA PUERTA
					}
					std::cout << std::endl << "Left" << std::endl;						//	KEY LEFT
					enemyMovement(map, enemyList, characterX, characterY);
					break;

				case KEY_RIGHT:
				case KEY_D:
				case KEY_d:
					if (characterY < heigth - 1)										//
					{																	//
						map[characterX][characterY] = '--';								//	PINTAR ESTELA
						characterY++;													//	MOVER HACIA LA DERECHA
					}
					else if (characterY < heigth && characterX == width / 2)			//
					{																	//
						map[characterX][characterY] = '--';								//	PINTAR ESTELA
						characterY++;													//	MOVER HACIA LA DERECHA POR LA PUERTA
					}
					std::cout << std::endl << "Right" << std::endl;						//	KEY RIGHT
					enemyMovement(map, enemyList, characterX, characterY);
					break;

				case 63:
					initMap(map, width, heigth);
					std::cout << std::endl << "CLEAR PATH" << std::endl;				// CLEAR PATH FROM SCREEN
					break;

				default:

					std::cout << std::endl << c << "null" << std::endl;					//	NOT ARROW

					break;

				}
			}
			map[characterX][characterY] = 'O';

			system("cls");
			drawMap(map,width, heigth);
			checkMapBalls(map, enemyList, characterX, characterY, vplayerh);
			checkDoors(map, width, heigth, characterX, characterY);
			
		std::chrono::high_resolution_clock::time_point endFrame = std::chrono::high_resolution_clock::now();

		deltaTime = std::chrono::duration_cast<std::chrono::milliseconds>(endFrame - beginFrame).count();
		timer += deltaTime;
		time += deltaTime;
		frames++;
		std::cout <<"\nDelta Time: " << deltaTime / 1000.0f << std::endl;
		std::cout << time/1000.0f << std::endl;
		std::cout << "List length: " << enemyList.getLength() << std::endl;
		std::cout << "X: " << characterX << " | Y: " << characterY;
		//if you really want FPS
		 if (timer >= 1000.0) { //every second
			 std::cout << " Frames: " << frames << std::endl;
			timer = 0.0f;
			frames = 60;
		

		}
		 /*FrameRate Limit*/
		 else if (frames >= frameRate)
		 {
			 std::cout << "Wait" << std::endl;
			 std::this_thread::sleep_for(std::chrono::milliseconds((long)(1000.0f - timer)));
			 frames = 0;
			 timer = 0.0f;
		 }
	}
	enemyList.clear();
	return 0;
>>>>>>> Stashed changes
}