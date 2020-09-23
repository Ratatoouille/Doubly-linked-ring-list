#pragma once

//класс контейнера принимающий любые типы
template<typename T>
class RingList
{
	// методы класса контейнера
public:
	RingList();
	~RingList();

	//добавление в конец контейнера
	void push_back(T data);
	//удаление первого элемента
	void pop_front();
	//добавление в начало контейнера
	void push_front(T data);
	//вставка элемента по указанному индексу
	void insert(T data, int index);
	//удаление элемента на позиции
	void removeAt(int index);
	//поиск элемента в контейнере по указанному индексу
	auto searchElement(int index);
	//удаление последнего элемента
	void pop_back();
	//очистка контенера
	void clear();
	//получение размера контейнера
	int GetSize() { return size; }
	//перегрузка оператора [] для обращения к элементам контейнера
	T& operator[](const int index);

private:

	//класс узла контейнера принимающий любые типы
	template<typename T>
	class Node
	{
	public:
		Node* pNext;
		T data;

		Node(T data = T(), Node* pNext = nullptr)
		{
			this->data = data;
			this->pNext = pNext;
			
		}

	};

	//поля разммера и начала контейнера
	int size;
	Node<T>* head;
};