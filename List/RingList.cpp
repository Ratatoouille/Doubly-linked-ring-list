#include "RingList.h"
#include <iostream>
using namespace std;

template<typename T>
RingList<T>::RingList()
{
	size = 0;
	head = nullptr;
	tail = nullptr;
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
		tail = head;
	}
	//если 1 элемент в списке
	else if (this->GetSize() == 1)
	{
		head->pNext = new Node<T>(data, head, head);
		tail = head->pNext;
	}
	else
	{
		tail->pNext = new Node<T>(data, head, tail);
		head->pPrev = tail->pNext;
		tail = tail->pNext;
	}

	size++;
}

template<typename T>
void RingList<T>::pop_front()
{

	if (head == nullptr)
	{
		cerr << "The list is empty" << endl;
		return;
	}
	//без head = nullptr при лишнем вызове pop_front возникает ошибка т.к. в head пов€л€етс€ какое-то значение. это из-за того что по этому адресу осталось какое-то значение?
	else if (this->GetSize() == 1)
	{
		delete head;
		head = nullptr;
		tail = nullptr;
		size--;
	}
	else
	{
		Node<T>* temp = head;
		head = head->pNext;
		head->pPrev = tail;
		tail->pNext = head;

		delete temp;

		size--;
	}
}

template<typename T>
void RingList<T>::push_front(T data)
{
	head = new Node<T>(data, head, tail);
	size++;
}

template<typename T>
void RingList<T>::insert(T data, int index)
{

	bool _is_correct_index = is_correct_index(index);

	if (_is_correct_index)
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
	return;
}

template<typename T>
void RingList<T>::removeAt(int index)
{

	bool _is_correct_index = is_correct_index(index);

	if (_is_correct_index)
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
	return;
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

		cout << this->size << "\t";
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
bool RingList<T>::is_correct_index(int index)
{
	if (index > this->GetSize())
	{
		cerr << "Invalid index" << endl;
		return false;
	}
	return true;
}