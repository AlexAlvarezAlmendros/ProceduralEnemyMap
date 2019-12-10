#include "Declarations.h"
#include "Structures.h"

List<room> roomList;

void Init()
{
	char difficulty = AskDifficulty();
	InitRoomList(roomList, difficulty);
}

void GameLoop()
{

}

void Destroy()
{

}

int main()
{
	Init();
	GameLoop();
	Destroy();
	return 0;
}