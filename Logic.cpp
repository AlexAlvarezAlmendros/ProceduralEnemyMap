//#include <string>
//#include <iostream>
//#include <ctime>
//
//#include "List.h"
////#include "Declarations.h"
//#include "Structures.h"
//
////void randPos(Enemy & _p, int _i)
////{
////	_p.pos.X = (rand() % 20 + 5) / (_i + 1);
////	_p.pos.Y = (rand() % 20 + 5) / (_i + 1);
////	return;
////};
//
//
//
//double clockToMilliseconds(clock_t ticks) {
//	// units/(units/time) => time (seconds) * 1000 = milliseconds
//	return (ticks / (double)CLOCKS_PER_SEC)*1000.0;
//}
//...

//void initMap(Array(&map), const int _size)
//{
//	for (size_t i = 0; i < _size; i++)
//	{
//		for (size_t j = 0; j < _size; j++)
//		{
//			map[i][j] = ' ';
//		}
//	}
//}

//void drawMap(Array(&map), const int w, const int h)
//{
//	system("cls");
//	std::cout << '|';
//	for (size_t i = 0; i < w; i++)
//	{
//		for (size_t j = 0; j < h; j++)
//		{
//			std::cout << map[i][j];
//		}
//		//	CON MARCO
//		std::cout << "|\n";
//		std::cout << '|' ;
//		//	SIN MARCO
//		//std::cout << "\n";
//	}
//}

//void checkMapBalls(Array(&map), List<Enemy> _ballsList, const int w, const int h)
//{
//	Enemy bAux;
//	Enemy bAux2;
//	int NumBalls = 0;
//	int AuxNumBalls;
//	AuxNumBalls = _ballsList.getLength();
//	int AuxLength = _ballsList.getLength();
//
//	for (size_t i = 0; i < w; i++)
//	{
//		for (size_t j = 0; j < h; j++)
//		{
//			if (map[i][j] == bAux.skin)
//			{
//				NumBalls++;
//				std::cout << "BOLA" << NumBalls << ". X=" << j << " Y=" << i << "\t";
//			}
//			/*else if (map[i][j] != bAux.skin)
//			{
//				size_t lul = 0;
//				for (int o = 0; o < AuxLength - 1; o++)
//				{
//
//					bAux2 = _ballsList.getItem(lul);
//					if (map[i][j] != bAux2.skin && i == bAux2.pos.X && j == bAux2.pos.Y)
//					{
//						_ballsList.removeItem(lul);
//					}
//				}
//			}*/
//		}
//	}
//
//
//	int BallsDestroyed = AuxNumBalls - NumBalls;
//	std::cout << std::endl << "Total bolas: " << NumBalls << std::endl << "Bolas conseguidas: " << BallsDestroyed << std::endl;
//}

