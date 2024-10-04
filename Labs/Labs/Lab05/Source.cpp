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
		double x, a, b, n, i, Y, S;
		for (i = 0, a = 0.1, b = 1, n = 100; i < 10; i++, a++, b++, n++)
		{
			x = (b - a) / n;
			Y = exp(2 * x);
			S = 1 + 2 * x / i;
			cout << "Y(x) = " << Y << "\tS(x) = " << S << endl;
		}
		break;
	}
	case '2': {

		break;
	}
	case '3': {

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