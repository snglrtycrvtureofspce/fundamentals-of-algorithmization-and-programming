#include <iostream>
#include <cmath>
#include <Windows.h>
using namespace std;

int main()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	char p;
	cout << "�������� �������: ";
	cin >> p;
	switch (p) {
	case '1': {
		int x, y, R;
		cout << "������� x: ";
		cin >> x;
		cout << "������� y: ";
		cin >> y;
		R = sqrt(10 * x - 5) / 3 * y;
		cout << "��� �����: " << R << endl;
		break;
	}
	case '2': {
		int b, x, g;
		const int A = 1;
		const int C = 2;
		cout << "������� b: ";
		cin >> b;
		cout << "������� x: ";
		cin >> x;
		g = pow(x, 2) - A * x + b - C;
		cout << "��� �����: " << g << endl;
		break;
	}
	default: {
		cout << "�������� �����" << endl;
		break;
	}
	}
	system("pause");
	return 0;
}