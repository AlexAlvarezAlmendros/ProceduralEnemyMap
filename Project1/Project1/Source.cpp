#include <iostream>

#include "Declarations.h"

List<room> roomList;
room *start;
room *end;

void Init(room* &_start, room* &_end)
{
	char difficulty = AskDifficulty();
	InitRoomList(roomList, difficulty, _start, _end);
}

void GameLoop()
{
	room *nextRoom;
	room *actualRoom = start;
	int playerhp = 10;
	nextRoom = FrameRate(*actualRoom, playerhp, roomList.getLength());
	if (nextRoom == end)
	{
		system("CLS");
		std::cout << "YOU WIN!";
		return;
	}
	actualRoom = nextRoom;
}

int main()
{

	Init(start, end);
	GameLoop();
	Destroy(roomList);
	return 0;
}