

int main()
{
	setlocale(LC_ALL, "");
	//FASE 1

	char difficulty;
	bool temporal = true;
	std::cout << "¿Vas a jugar en modo fácil o difícil? (f/m/d)\n Respuesta: ";
	while (temporal)
	{
		std::cin >> difficulty;
		if (difficulty != 'f' && difficulty != 'F' && difficulty != 'd' && difficulty != 'D' && difficulty != 'm' && difficulty != 'M')
		{
			system("CLS");
			std::cout << "Por favor, introduzca una respuesta válida (f/m/d)\n Respuesta: ";
		}
		else
		{
			temporal = false;
		}
	}
	srand(time(NULL));
	short mainPathSize = rand() % Max_MainPath + Min_MainPath;
	List<room> roomList;
	room auxroom;
	for (size_t i = 0; i < mainPathSize; i++) //GENERACION DE ROOMS
	{
		auxroom.basicInitRoom(difficulty);
		if (i != 0)
		{

			//aqui es donde hay que mirar las puertas
		}

		roomList.addItem(auxroom);
	}
	drawMap(roomList.getFirst()->data.map, roomList.getFirst()->data.size);

	return 0;
}