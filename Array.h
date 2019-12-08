#pragma once

#include <iostream>

struct Array {
	int length;
	unsigned int actualPosition = 0;

	char* dataArray = nullptr;

	void resizeArray()
	{
		if (length == 0)
		{
			allocateMemory(5);
			return;
		}

		char* aux = new char[length * 2];
		for (size_t i = 0; i < actualPosition; i++)
		{
			aux[i] = dataArray[i];
		}
		delete[] dataArray;
		dataArray = aux;
		length = length * 2;
		std::cout << "Array size: " << length << std::endl;
	}

	void setActualPosition(int i)
	{
		if (i < length && i >= 0) { actualPosition = i; }
		return;
	}

	void allocateMemory(int size)
	{
		if (dataArray == nullptr)
		{
			dataArray = new char
				[size];
			length = size;
			actualPosition = 0;
			std::cout << "Array size: " << length << std::endl;
			return;
		}
		else
		{
			if (size > length)
			{
				deleteMemory();
				allocateMemory(size);
				return;
			}
			else {
				actualPosition = 0;
				return;
			}
		}
	}

	void deleteMemory()
	{
		delete[] dataArray;
		actualPosition = 0;
		length = 0;
		dataArray = nullptr;
		std::cout << "Array size: " << length << std::endl;
		return;
	}

	void addData(int p)
	{
		if (actualPosition == length)
		{
			resizeArray();
		}
		dataArray[actualPosition] = p;
		actualPosition++;
		return;
	}

	void removeData(int id)
	{
		if (id > actualPosition)
		{
			return;
		}
		else
		{
			for (size_t i = id; i < actualPosition; i++)
			{
				dataArray[i] = dataArray[i + 1];
			}
			actualPosition--;
			return;
		}
	}
};