#include <iostream>
#include <cmath>
using namespace std;

struct state {
	int title;
	char name[100];
	double square;
	char president[100];
	bool sex;
};


int main() {
	setlocale(LC_ALL, "");
	state a{};
	cout << "Ââåäèòå êîä ãîñóäàðñòâà: ";
	cin >> a.title;
	cout << "\nÂâåäèòå íàçâàíèå ãîñóäàðñòâà: ";
	cin >> a.name;
	cout << "\nÂâåäèòå ïëîùàäü ãîñóäàðñòâà: ";
	cin >> a.square;
	cout << "\nÂâåäèòå èìÿ ïðåçèäåíòà â ãîñóäàðñòâå: ";
	cin >> a.president;
	cout << "\nÂâåäèòå ïîë ïðåçèäåíòà: ";
	cin >> a.sex;
	cout << "____________________________________________________________" << endl;
	cout << a.title << "\t|\t";
	cout << a.name << "\t|\t";
	cout << a.square << "\t|\t";
	cout << a.president << "\t|\t";
	if (a.sex == true) {
		cout << "ìóæñêîé" << "\t|\n";
	}
	else {
		cout << "æåíñêèé" << "\t|\n";
	}

	state* pA = &a;
	state& rA = a;
	cout << pA->title << "\t|\t" << a.name << "\t|\t" << rA.square << "\t|\t" << (&a)->president << "\t|\t" << a.sex << endl;
	system("pause");
	return 0;
}