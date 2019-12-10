#include <ctime>
#include <iostream>
#include <thread>
#include <array>
#include <conio.h>

#include "Constants.h"
#include "Declarations.h"

void FrameRate(room)
{
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
				if (characterY < heigth - 1)
				{
					map[characterX][characterY] = '--';
					characterY++;
				}
				std::cout << std::endl << "Right" << std::endl; // key right
				break;

			case KEY_F5:
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
		drawMap(map, width, heigth);
		checkMapBalls(map, ballsList, width, heigth);


		std::chrono::high_resolution_clock::time_point endFrame = std::chrono::high_resolution_clock::now();

		deltaTime = std::chrono::duration_cast<std::chrono::milliseconds>(endFrame - beginFrame).count();
		timer += deltaTime;
		time += deltaTime;
		frames++;
		std::cout << "\nDelta Time: " << deltaTime / 1000.0f << std::endl;
		std::cout << time / 1000.0f << std::endl;
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
}