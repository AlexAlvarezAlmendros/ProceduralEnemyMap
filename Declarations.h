#pragma once

// José's Logic

double clockToMilliseconds(clock_t ticks);

void initMap(char(&map)[width][heigth], const int w, const int h);

void drawMap(char(&map)[width][heigth], const int w, const int h);


//	OUR Logic

void initList(List<Enemy> & _ballslist);

void ballsIntoMap(char(&_map)[width][heigth], List<Enemy> _ballslist);

void checkMapBalls(char(&map)[width][heigth], List<Enemy> &_ballsList, const int w, const int h);

void checkDoors(char(&map)[width][heigth], const int w, const int h);