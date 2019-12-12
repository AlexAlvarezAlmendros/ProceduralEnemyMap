#include <iostream>

#include "Declarations.h"

List<room> roomList;

void Init()
{
	char difficulty = AskDifficulty();
	InitRoomList(roomList, difficulty);
}

void GameLoop()
{
	room *nextRoom;
	room *actualRoom = start;

	nextRoom = FrameRate(*actualRoom, playerhp);
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
	Init();
	GameLoop();
	Destroy(roomList);
	return 0;
}