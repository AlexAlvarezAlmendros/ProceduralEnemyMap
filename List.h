#pragma once

#include "Structures.h"

template <class T>
struct Node
{ 
	T data;
	Node<T> * next = nullptr;
	Node<T> * back = nullptr;
};

//std::ostream & operator << (std::ostream & out, Player p)
//{
//	out << p.name;
//	return out;
//};

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
		if (id < 0 || id >= length) return nullptr;
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
	const int & getLength()
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
			//newNode->back = newNode;
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

		//	FORMA 1: ID
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

		//	FORMA 2: ID - 1
		/*Node * countNode = getNode(id - 1);
		if (countNode != nullptr)
		{
			Node * newNode = new Node;
			newNode->data = item;
			newNode->next = countNode->next;
			countNode->next->back = newNode;
			countNode->back, countNode->next = newNode;

			length++;
		}*/

		//	FORMA 3: ID - 1 Y SIN GETNODE
		//Node * countNode = front;
		//int count = 0;
		//for (Node * countNode = front; countNode != nullptr; countNode = countNode->next)
		//{
		//	if (count == id - 1)
		//	{
		//		Node * newNode = new Node;
		//		newNode->data = item;
		//		newNode->next = countNode->next;
		//		countNode->next = newNode;
		//	}
		//	count++;
		//}
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
		countNode->back = nullptr;
		delete front;
		front = countNode;
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
		/*tail->next = newNode;*/
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

		//Node * countNode = getNode(length - 2);
		////countNode = front;
		///*for (int i = 0; i < length - 2; i++)
		//{
		//	countNode = countNode->next;
		//}*/
		//delete tail;
		//tail = countNode;
		//tail->next = nullptr;
		//tail->back = countNode->back;
		//if (length == 1)
		//{
		//	front = nullptr;
		//	tail = nullptr;
		//}
		//length--;
	}
#pragma endregion

#pragma region BORRA EL NODO QUE QUERAMOS
	void removeItem(const size_t id)
	{
		if (id < 0 || id >= length) return;
		if (id == 0) { popFront(); return; }
		if (id == length - 1) { popBack(); return; }

		Node<T> * deleteNode = getNode(id);
		deleteNode->next->back = deleteNode->back;
		deleteNode->back->next = deleteNode->next;

		delete deleteNode;
		length--;
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