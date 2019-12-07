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
	setlocale(LC_ALL, "");
	
	// DURAS DECLARACIONES

	List<room> level = Init();	
	




	Destroy(level);
	return 0;
}






















//void main2()
//{
//	init();
//
//	gameloop()
//	{
//		room actualroom = level.getFirst()->data1;
//		room nextroom;
//		while (playerhp > 0)
//		{
//
//			nextroom = fdepartida(actualroom);
//			actualroom = nextroom;
//
//		}
//	}
//
//	Destroy();
//
//	return 0
//}