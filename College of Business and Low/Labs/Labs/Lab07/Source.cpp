#include <iostream>
#include <Windows.h>
#include <ctime>
using namespace std;

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand(time(NULL));
	char p;
tryAgain:
	cout << "Выбери задание: ";
	cin >> p;
	switch (p)
	{
	case '1': {
		char arr[4][2] = { {'s', 'q'},
				{'w','t'},
				{'r','g'},
				{'y','g'} };
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 2; j++) {
				cout << arr[i][j] << '\t';
			}
			cout << '\n';
		}
		break;
	}
	case '2': {
		double arr[2][4]{};
		cout << "Введите значения массива: " << endl;
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 4; j++) {
				cout << "arr[" << i << "," << j << "] = ";
				cin >> arr[i][j];
				cout << '\n';
			}
		}
		cout << "Print array: " << endl;
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 4; j++) {
				cout << arr[i][j] << '\t';
			}
			cout << '\n';
		}
		break;
	}
	case '3': {
		int arr[25][11]{};
		for (int i = 0; i < 25; i++) {
			for (int j = 0; j < 11; j++) {
				arr[i][j] = 11 + rand() % 9;
			}
		}
		cout << "Show massiv: " << endl;
		for (int i = 0; i < 25; i++) {
			for (int j = 0; j < 11; j++) {
				cout << arr[i][j] << ' ' << ';' << ' ';
			}
			cout << '\n';
		}
		cout << "Show reverse massiv: " << endl;
		for (int i = 25 - 1; i > -1; i--) {
			for (int j = 11 - 1; j >= 0; j--) {
				cout << arr[i][j] << ' ' << ';' << ' ';
			}
			cout << '\n';
		}
		break;
	}
	case '4': {
		const int m = 21, n = 8;
		int arr[m][n]{};
		int s = -49;
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				arr[i][j] = s;
				s = s + 7;
			}
		}
		cout << "Print massiv: " << endl;
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				cout << arr[i][j] << " ";
				cout << endl;
			}
		}
		cout << "Print new massiv: ";
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				arr[i][j] = arr[i][j] + 3;
				cout << arr[i][j] << ";";
			}
		}
		break;
	}
	case '5': {
		double arr[3][6]{};
		cout << "Введите значения массива: " << endl;
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				cin >> arr[i][j];
			}
		}
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				cout << arr[i][j] << ' ' << ';' << ' ';
			}
			cout << '\n';
		}
		cout << "New vision of array" << endl;
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				if ((i % 2 != 0 || j % 2 != 0)) {
					cout << arr[i][j] << ' ' << ';' << ' ';
				}
			}
			cout << '\n';
		}
		break;
	}
	default: {
		cout << "Такого варианта нет.\n";
		break;
	}
	}
	int xd = 0;
tryAgain2:
	cout << "Желаете продолжить ?\n1 - Да\n2 - Нет" << endl;
	cin >> xd;
	if (xd == 1) {
		goto tryAgain;
	}
	if (xd == 2) {
		cout << "Прощай" << endl;
		system("pause");
		return 0;
	}
	else {
		cout << "Сделайте выбор ещё раз))" << endl;
		goto tryAgain2;
	}
}