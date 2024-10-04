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
		double a, r, x, y;
		int p;
		cout << "Введите x: ";
		cin >> x;
		cout << "Введите y: ";
		cin >> y;
		cout << "Меню: \n1-рассчитать sh(x)\n2-рассчитать x^2\n3-рассчитать экспоненту exp(x)\nВыберите пункт меню: ";
		cin >> p;
		switch (p)
		{
		case 1:
		{
			x = sinh(x);
			cout << p << endl;
			break;
		}
		case 2:
		{
			x = pow(x, 2);
			break;
		}
		case 3:
		{
			x = exp(x);
			break;
		}
		default:
		{
			cout << "Такого варианта нет.\n";
			system("pause");
			return 0;
			break;
		}
		}
		cout << "f(x) = " << x << endl;
		if (x > y)
		{
			r = pow((fabs(x - y)), 1.0 / 3) + tan(x);
			cout << "Ответ идёт по первой ветке\n";
		}
		else
		{
			if (x < y)
			{
				r = (pow(y - x, 3) + cos(x));
				cout << "Ответ идёт по второй ветке\n";
			}
			else
			{
				if (x == y)
				{
					r = pow(x + y, 2) + pow(x, 3);
					cout << "Ответ идёт по третьей ветке\n";
				}
				else
				{
					cout << "Ответ невозможно определить, введите новые значения";
					system("pause");
					return 0;
				}
			}
		}
		cout << "Результат вычислений: " << r << endl;
		break;
	}
	case '2': {
		float x, y, R, hyph;
		cout << "Введите координаты точки и радиус круга" << endl;
		cout << "x= ";
		cin >> x;
		cout << "y= ";
		cin >> y;
		cout << "r= ";
		cin >> R;
		hyph = sqrt(pow(x, 2) + pow(y, 2));

		if (hyph <= R) {
			cout << "Точка принадлежит кругу" << endl;
		}
		else
			cout << "Точка не принадлежит кругу" << endl;
		break;
	}
	case '3': {
		double c, d, k, y, z, x;
		cout << "Введите c: ";
		cin >> c;
		cout << "Введите z, если z > 0, получим x = z^2 - z, а если z >= 0, получим x = z^3: ";
		cin >> z;
		cout << "Введите d: ";
		cin >> d;
		cout << "Введите k: ";
		cin >> k;

		if (z < 0)
		{
			x = pow(z, 2) - z;
			cout << "Решение проводилось по первой ветке" << endl;
		}
		else
		{
			if (z >= 0)
			{
				x = pow(z, 3);
				cout << "Решение проводилось по второй ветке" << endl;
			}
		}
		y = pow(sin(c * x + pow(d, 2) + k * pow(x, 2)), 3);
		cout << "y = " << y << endl;
		break;
	}
	case '4': {
		int x, y, ma, mi, t;
		cout << "Введите x: ";
		cin >> x;
		cout << "Введите y: ";
		cin >> y;
		ma = max(y, 0);
		mi = min(x, 5);
		t = ma * (mi, ma) / 5;
		if (t > 0)
		{
			cout << "Ваш ответ: " << t << endl;
		}
		else
		{
			if (t == 0)
			{
				cout << "Ваше ответ будет равен нулю, введите повторные значения" << endl;
				cout << "Введите x: ";
				cin >> x;
				cout << "Введите y: ";
				cin >> y;
				ma = max(y, 0);
				mi = min(x, 5);
				t = ma * (mi, ma) / 5;
				cout << "Ваш ответ: " << t << endl;
			}
		}
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