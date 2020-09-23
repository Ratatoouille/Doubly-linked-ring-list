#include "RingList.cpp"
#include <iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "ru");

	RingList<int> lst;

	lst.push_front(2);
	lst.push_front(10);

	for (int i = 0; i < lst.GetSize(); i++)
	{
		cout << lst[i] << endl;
	}

	cout << "Вставка" << endl;

	lst.insert(100, 1);

	for (int i = 0; i < lst.GetSize(); i++)
	{
		cout << lst[i] << endl;
	}

	cout << "Удаление" << endl;

	lst.pop_back();

	for (int i = 0; i < lst.GetSize(); i++)
	{
		cout << lst[i] << endl;
	}

	return 0;
}