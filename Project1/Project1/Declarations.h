#pragma once
#include <ctime>
#include "Structures.h"

void Init(room* &_start, room* &_end);

char AskDifficulty();

void InitRoomList(List<room> &_level, char &_difficulty, room* &_start, room* &_end);

void BasicInitRoom(room &_room, char &_difficulty);

int SetDifficulty(room &_room, char &_difficulty);

void InitEnemyList(List<Enemy> &_enemyList, int _enemyNum, int _size);


void GameLoop();

double clockToMilliseconds(clock_t ticks);

void enemyIntoMap(room &_room);

void drawMap(room &_room);

void checkMapBalls(room &_room);

void checkDoors(room &_room);

room *FrameRate(room &_room, int &_playerhp, int _listRoomLength/* List<room> _listRoom*/);


void Destroy(List<room> &_roomList);

//void InitGame(room &_room, char& _difficulty);
