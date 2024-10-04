#include <iostream>
#include <cmath>
#include <Windows.h>
using namespace std;

int main()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	char p;
	cout << "Выберите задание: ";
	cin >> p;
	switch (p) {
	case '1': {
		int x, y, R;
		cout << "Введите x: ";
		cin >> x;
		cout << "Введите y: ";
		cin >> y;
		R = sqrt(10 * x - 5) / 3 * y;
		cout << "Ваш ответ: " << R << endl;
		break;
	}
	case '2': {
		int b, x, g;
		const int A = 1;
		const int C = 2;
		cout << "Введите b: ";
		cin >> b;
		cout << "Введите x: ";
		cin >> x;
		g = pow(x, 2) - A * x + b - C;
		cout << "Ваш ответ: " << g << endl;
		break;
	}
	default: {
		cout << "Неверный номер" << endl;
		break;
	}
	}
	system("pause");
	return 0;
}