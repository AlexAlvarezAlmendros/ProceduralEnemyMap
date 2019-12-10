#pragma once

// José's Logic

double clockToMilliseconds(clock_t ticks);

void initMap(char(&map)[width][heigth], const int w, const int h);

void drawMap(char(&map)[width][heigth], const int w, const int h);


//	OUR Logic

void initList(List<Enemy> & _enemylist);

void enemyIntoMap(char(&_map)[width][heigth], List<Enemy> _enemyList);

void checkMapBalls(char(&map)[width][heigth], List<Enemy> &_enemyList, const int _characterX, const int _characterY, int &vplayerh);

void checkDoors(char(&map)[width][heigth], const int w, const int h, int _characterX, int _characterY);

void enemyMovement(char(&_map)[width][heigth], List<Enemy>& _enemyList, const int _characterX, const int _characterY);

