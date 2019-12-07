#pragma once

typedef std::vector<std::vector<char>> vectorbi;

double clockToMilliseconds(clock_t ticks);

void initMap(vectorbi(&map), const int w, const int h);

void drawMap(vectorbi(&map), const int w, const int h);


//	CARNAL



void initList(List<Enemy> & _ballslist);

void ballsIntoMap(vectorbi(&_map), List<Enemy> _ballslist);

void checkMapBalls(vectorbi(&map), List<Enemy> _ballsList, const int w, const int h);

List<room> Init();

void Destroy(List<room> _level);