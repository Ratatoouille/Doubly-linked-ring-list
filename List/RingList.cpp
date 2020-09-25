#include "RingList.h"
#include <iostream>
using namespace std;

template<typename T>
RingList<T>::RingList()
{
	size = 0;
	head = nullptr;
	//tail = nullptr;
}

template<typename T>
RingList<T>::~RingList()
{
	clear();
}

template<typename T>
void RingList<T>::push_back(T data)
{

	if (head == nullptr)
	{
		head = new Node<T>(data);
	}
	else
	{
		Node<T>* current = this->head;
		while (current->pNext != nullptr)
		{
			current = current->pNext;
		}
		current->pNext = new Node<T>(data, nullptr, current);
	}

	size++;
}

template<typename T>
void RingList<T>::pop_front()
{
	Node<T>* temp = head;

	if (head->pNext != nullptr)
	{
		head = head->pNext;
		head->pPrev = nullptr;
	}
	else
	{
		head = head->pNext;
	}

	delete temp;

	size--;
}

template<typename T>
void RingList<T>::push_front(T data)
{
	head = new Node<T>(data, head);
	size++;
}

template<typename T>
void RingList<T>::insert(T data, int index)
{
	if (index == 0)
	{
		push_front(data);
	}
	else
	{
		auto previous = searchElement(index);

		Node<T>* next = previous->pNext;
		
		Node<T>* new_node = new Node<T>(data, previous->pNext, previous);

		previous->pNext = new_node;;

		new_node->pNext->pPrev = new_node;

		size++;
	}
}

template<typename T>
void RingList<T>::removeAt(int index)
{
	if (index == 0)
	{
		pop_front();
	}
	else
	{
		auto previous = searchElement(index);

		Node<T>* toDelete = previous->pNext;

		previous->pNext = toDelete->pNext;

		toDelete->pNext->pPrev = previous;

		delete toDelete;

		size--;
	}
}

template<typename T>
auto RingList<T>::searchElement(int index)
{
	Node<T>* previous = this->head;

	for (int i = 0; i < index - 1; i++)
	{
		previous = previous->pNext;
	}

	return previous;
}

template<typename T>
void RingList<T>::pop_back()
{
	removeAt(size - 1);
}

template<typename T>
void RingList<T>::clear()
{
	while (size)
	{
		pop_front();
	}
}

template<typename T>
T& RingList<T>::operator[](const int index)
{
	int counter = 0;
	Node<T>* current = this->head;

	while (current != nullptr)
	{
		if (counter == index)
		{
			return current->data;
		}
		current = current->pNext;
		counter++;
	}
}

template<typename T>
void RingList<T>::output_debug()
{
	Node<T>* current = this->head;
	cout << "Data: " << current->data << "\tPrev: " << current->pPrev << "\tCurrent: " << current << "\tNext: " << current->pNext << endl;
	while (current->pNext != nullptr)
	{
		current = current->pNext;
		cout << "Data: " << current->data << "\tPrev: " << current->pPrev << "\tCurrent: " << current << "\tNext: " << current->pNext << endl;
	}
}
