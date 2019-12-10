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
	
	
}