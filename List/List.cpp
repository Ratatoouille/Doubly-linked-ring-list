#include "RingList.cpp"
#include <iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "ru");

	RingList<int> lst;

	lst.pop_front();

	lst.push_back(2);
	lst.push_back(10);
	lst.push_back(100);
	lst.push_back(1000);
	
	cout << "push back" << endl;

	for (int i = 0; i < lst.GetSize(); i++)
	{
		cout << lst[i] << endl;
	}

	cout << "insert" << endl;
	lst.insert(99, 2);

	for (int i = 0; i < lst.GetSize(); i++)
	{
		cout << lst[i] << endl;
	}

	cout << "remove" << endl;
	lst.removeAt(2);

	for (int i = 0; i < lst.GetSize(); i++)
	{
		cout << lst[i] << endl;
	}

	lst.insert(99, 10);
	lst.removeAt(15);

	lst.pop_front();
	lst.pop_front();
	lst.pop_front();
	lst.pop_front();
	lst.pop_front();

	cout << "clear list" << endl;
	lst.clear();

	return 0;
}