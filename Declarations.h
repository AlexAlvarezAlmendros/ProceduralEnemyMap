#pragma once

void Init();

char AskDifficulty();

void InitRoomList(List<room> &_level, char &_difficulty);

void BasicInitRoom(room &_room, char &_difficulty);

int SetDifficulty(room &_room, char &_difficulty);

void InitEnemyList(List<Enemy> &_enemyList, int _enemyNum, int _size);


void GameLoop();

void FrameRate(room &_room, int _playerhp)


void Destroy();

void FrameRate();

void InitGame(room& _room, char& _difficulty);
