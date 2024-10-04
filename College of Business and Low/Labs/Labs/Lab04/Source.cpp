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
		double m, r, e, t2;
		cout << "Введите m: ";
		cin >> m;
		cout << "Введите r: ";
		cin >> r;
		cout << "Введите e: ";
		cin >> e;
		if (r <= m < 2 * r)
		{
			t2 = sqrt(fabs(3 * m - 5 * r) * pow(e, m / r));
			cout << "Ответ идёт по ветке 1, ответ: " << t2 << endl;
		}
		else
		{
			if (m > 2 * r)
			{
				t2 = sqrt(fabs(3 * m - 5 * r) * pow(e, r / m));
				cout << "Ответ идёт по ветке 2, ответ: " << t2 << endl;
			}
			else
			{
				cout << "Для таких значений решения не предусмотрено." << endl;
				system("pause");
				return 0;
			}
		}
		break;
	}
	case '2': {
		double x, b, f, s;
		int p;
		cout << "Введите x: ";
		cin >> x;
		cout << "Введите b: ";
		cin >> b;
		cout << "Введите действия над переменной f(x):\n1-рассчитать экспоненту exp(x)\n2-рассчитать x^2" << endl;
		cin >> p;
		switch (p)
		{
		case 1:
		{
			x = exp(x);
			cout << "f(x)=exp(x): " << x << endl;
			break;
		}
		case 2:
		{
			x = pow(x, 2);
			cout << "f(x)=x^2: " << x << endl;
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
		if (1 < x * b < 10)
		{
			s = exp(x);
			cout << "Ответ идёт по ветке 1" << endl;
		}
		else
		{
			if (10 <= x * b < 40)
			{
				s = sqrt(fabs(x + 4 * b));
				cout << "Ответ идёт по ветке 2" << endl;
			}
			else
			{
				s = b * pow(x, 2);
				cout << "Ответ идёт по ветке 3" << endl;
			}
		}
		cout << "s = " << s << endl;
		break;
	}
	case '3': {
		int x;
		cout << "Введите целое число: ";
		cin >> x;
		if (x > -120 && x < -100)
		{
			cout << "Группа A" << endl;
		}
		else
		{
			if (x > 100 && x % 5 == 0)
			{
				cout << "Группа B" << endl;
			}
			else
			{
				if (x < 0 && x % 2 == 0)
				{
					cout << "Группа C" << endl;
				}
				else
				{
					cout << "Группа D" << endl;
				}
			}
		}
		break;
	}
	case '4': {
		double a;
		int p;
		cout << "Введите плотность материала (г/ куб.дм): ";
		cin >> a;
		if (a >= 7130 && a <= 11400)
		{
			p = 1;
		}
		else
		{
			if (a >= 1000 && a < 7130)
			{
				p = 2;
			}
			else
			{
				cout << "Введите корректное значения от 1000 до 11400" << endl;
				system("pause");
				return 0;
			}
		}
		switch (p)
		{
		case 1:
		{
			cout << "Плотность не менее 7130 г/куб.дм имеют следующие материалы:\nСвинец - 11400\nМедь - 8900\nСталь - 7850\nЦинк - 7200\nЧугун - 7130" << endl;
			break;
		}
		case 2:
		{
			cout << "Плотность менее 7130 г/куб.дм имеют следующие материалы:\nСтекло - 2600\nАлюминий - 2500\nБетон - 2400\nВода - 1000" << endl;
			break;
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