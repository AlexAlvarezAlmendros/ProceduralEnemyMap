#pragma once
#pragma once
#include "Constants.h"
#include "Structures.h"

template <class T>
struct Node
{
	T data;
	Node<T>* next = nullptr;
	Node<T>* back = nullptr;
};

template <class T>
struct List
{
private:
	Node<T> * front = nullptr;
	Node<T> * tail = nullptr;
	int length = 0;

#pragma region COMPROBACIÓN DE SI ESTÁ EN LA LISTA
	Node<T> * getNode(int id)
	{
		if (id < 0 || id >= length) {
			return nullptr;
		}
		bool isBackwards = id > length >> 1 ? true : false;

		Node<T> * count = isBackwards ? tail : front;

		if (isBackwards)
		{
			for (int i = length - 1; i != id; i--)
			{
				count = count->back;
			}
		}
		else
		{
			for (int i = 0; i != id; i++)
			{
				count = count->next;
			}
		}
		return count;
	}
#pragma endregion

public:

#pragma region RETORNA EL LENGTH0
	int & getLength()
	{
		return length;
	}
#pragma endregion

#pragma region AÑADE UN NODO AL PRINCIPIO (FORMA PREDETERMINADA)
	void addItem(T & item)
	{
		Node<T> * newNode = new Node<T>;
		newNode->data = item;
		if (front == nullptr)
		{
			front = newNode;
			tail = newNode;
			newNode->back = nullptr;
		}
		else
		{
			newNode->next = front;
			newNode->back = nullptr;
			front->back = newNode;

			front = newNode;
		}
		length++;
	}
#pragma endregion

#pragma region AÑADE UN NODO DONDE QUERAMOS
	void addItem(T & item, int id)
	{
		if (id < 0 || id > length) return;
		if (id == 0) { addItem(item); return; }
		if (id == length) { pushBack(item); return; }

		Node<T> * countNode = getNode(id);
		if (countNode != nullptr)
		{
			Node<T> * newNode = new Node<T>;
			newNode->data = item;
			newNode->next = countNode;
			newNode->back = countNode->back;
			countNode->back->next = newNode;
			countNode->back = newNode;

			length++;
		}
	}
#pragma endregion

#pragma region AÑADE UN NODO AL PRINCIPIO
	void pushFront(T & item)
	{
		addItem(item);
	}
#pragma endregion

#pragma region ELIMINA EL NODO DEL PRINCIPIO
	void popFront()
	{
		if (front == nullptr) return;
		Node<T> * countNode = front->next;
		if (countNode == nullptr)
		{
			delete front;
			front = nullptr;
		}
		else {
			countNode->back = nullptr;
			delete front;
			front = countNode;
		}
		if (length == 1) {
			front = nullptr;
			tail = nullptr;
		}
		length--;
	}
#pragma endregion

#pragma region AÑADE UN NODO AL FINAL
	void pushBack(T & item)
	{
		if (tail == nullptr)
		{
			addItem(item);
			return;
		}
		Node<T> * newNode = new Node<T>;
		newNode->data = item;
		tail->next = newNode;
		newNode->back = tail;
		tail = newNode;
		length++;
	}
#pragma endregion

#pragma region ELIMINA EL NODO DEL FINAL
	void popBack()
	{
		if (tail == nullptr) return;

		Node<T> * countNode = tail->back;

		delete tail;
		tail = countNode;
		tail->next = nullptr;
		if (length == 1)
		{
			front = nullptr;
			tail = nullptr;
		}
		length--;
	}
#pragma endregion

#pragma region BORRA EL NODO QUE QUERAMOS
	void removeItem(const size_t id)
	{
		if (id < 0 || id > length)
		{
			return;
		}
		else if (id == 0)
		{
			popFront();
			return;
		}
		else if (id == length - 1)
		{
			popBack();
			return;
		}

		Node<T> * deleteNode = getNode(id);
		deleteNode->next->back = deleteNode->back;
		deleteNode->back->next = deleteNode->next;

		delete deleteNode;
		length -= 1;
	}
#pragma endregion

#pragma region LIMPIA LA LISTA
	void clear()
	{
		while (front != nullptr)
		{
			popFront();
		}
	}
#pragma endregion

#pragma region AÑADE UNA LISTA AL FINAL DE OTRA
	void merge(List & otherList)
	{
		if (front == nullptr)
		{
			front = otherList.front;
			tail = otherList.tail;
		}
		else
		{
			tail->next = otherList.front;
			otherList.front->back = tail;
			if (otherList.tail != nullptr)
			{
				tail = otherList.tail;
			}
		}
		length += otherList.length;
	}
#pragma endregion

#pragma region MUESTRA LA INFORMACIÓN DEL NODO QUE QUERAMOS
	T & getItem(const size_t id)
	{
		return getNode(id)->data;
	}
#pragma endregion

	T & operator [] (size_t index) {
		return getItem(index);
	}

	Node<T> * getFirst()
	{
		return front;
	}

	//	AÑADIR VARIOS NODOS EN DIFERENTES POSICIONES

	//	ELIMINAR VARIOS NODOS EN DIFERENTES POSICIONES
};