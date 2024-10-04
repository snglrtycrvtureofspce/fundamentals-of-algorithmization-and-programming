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
		double pi, z1, z2, a, x;
		pi = 3.141592653589793;
		cout << "Введите a: ";
		cin >> a;
		cout << "Введите x: ";
		cin >> x;
		z1 = pow(cos(x), 2) * (3 / 8 * pi - a / 4) - pow(cos(x), 2) * (11 / 8 * pi + a / 4);
		z2 = sqrt(2) / 2 * sin(a / 2);
		cout << "Ответ Z1:" << z1 << endl;
		cout << "Ответ Z2:" << z2 << endl;
		break;
	}
	case '2': {
		double w, x, y, z;
		x = 0.4 * pow(10, 4);
		y = 0.875;
		z = 0.475 * pow(10, -3);
		w = pow((fabs(cos(x) - cos(y))), (1 + 2 * pow(sin(y), 2)) * (1 + z + (pow(z, 2)) / 2) + (pow(z, 3) / 3) + (pow(z, 4) / 4));
		cout << "Ваш ответ: " << w << endl;
		break;
	}
	case '3': {
		const double PI = acos(-1.0);
		double T, m, k;
		cout << "Введите массу m: ";
		cin >> m;
		cout << "Введите коэффициент упругости k: ";
		cin >> k;
		T = 2 * PI * sqrt(m / k);
		cout << "Ваш ответ: " << T << endl;
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