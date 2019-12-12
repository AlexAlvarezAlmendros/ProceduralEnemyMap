#pragma once
#include <ctime>
#include "Structures.h"

void Init();

char AskDifficulty();

void InitRoomList(List<room> &_level, char &_difficulty);

void BasicInitRoom(room &_room, char &_difficulty);

int SetDifficulty(room &_room, char &_difficulty);

void InitEnemyList(List<Enemy> &_enemyList, int _enemyNum, int _size);


void GameLoop();

double clockToMilliseconds(clock_t ticks);

void enemyIntoMap(room &_room);

void drawMap(room &_room);

void checkMapBalls(room &_room);

void checkDoors(room &_room);

void enemyMovement(char(&_map)[width][heigth], List<Enemy> &_enemyList, const int _characterX, const int _characterY);

room *FrameRate(room &_room, int &_playerhp);


void Destroy(List<room> &_roomList);

//void InitGame(room &_room, char& _difficulty);
