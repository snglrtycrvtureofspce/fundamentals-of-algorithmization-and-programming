#include <iostream>
#include <Windows.h>
#include <set>
#include <iterator>
#include <cstdlib>

using namespace std;
int main()
{
	srand(time(NULL));
	char p;
	cin >> p;
	switch (p)
	{
	case '1':
		{
		set<int> mySet;
		for (int i = 0; i < 10; i++) {
			mySet.insert(rand() % 100);
		}
		cout << "Set elements: ";
		copy(mySet.begin(), mySet.end(), ostream_iterator<int>(cout, " "));
		int del = 0;
		cout << "\nWhich element to remove? ";
		cin >> del;
		cout << "Element " << *mySet.find(del) << " - removed!" << endl;
		mySet.erase(del);
		int add = 0;
		cout << "What element to add? ";
		cin >> add;
		cout << "New item added in place of the old one - " << *mySet.lower_bound(add) << endl;
		mySet.insert(add);
		cout << "We removed the element " << del << " and added " << add << ".\nHere's what happened: " << endl;
		copy(mySet.begin(), mySet.end(), ostream_iterator<int>(cout, " "));
		break;
		}
	case '2':
		{
			set<char> mySet;
			mySet.insert('I');
			mySet.insert('n');
			mySet.insert('f');
			mySet.insert('i');
			mySet.insert('n');
			mySet.insert('i');
			mySet.insert('t');
			mySet.insert('y');
			copy(mySet.begin(), mySet.end(), ostream_iterator<char>(cout, " "));
			break;
		}
	}
	return 0;
}
