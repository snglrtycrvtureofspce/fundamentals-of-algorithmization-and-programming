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
		double m, r, e, t2;
		cout << "������� m: ";
		cin >> m;
		cout << "������� r: ";
		cin >> r;
		cout << "������� e: ";
		cin >> e;
		if (r <= m < 2 * r)
		{
			t2 = sqrt(fabs(3 * m - 5 * r) * pow(e, m / r));
			cout << "����� ��� �� ����� 1, �����: " << t2 << endl;
		}
		else
		{
			if (m > 2 * r)
			{
				t2 = sqrt(fabs(3 * m - 5 * r) * pow(e, r / m));
				cout << "����� ��� �� ����� 2, �����: " << t2 << endl;
			}
			else
			{
				cout << "��� ����� �������� ������� �� �������������." << endl;
				system("pause");
				return 0;
			}
		}
		break;
	}
	case '2': {
		double x, b, f, s;
		int p;
		cout << "������� x: ";
		cin >> x;
		cout << "������� b: ";
		cin >> b;
		cout << "������� �������� ��� ���������� f(x):\n1-���������� ���������� exp(x)\n2-���������� x^2" << endl;
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
			cout << "������ �������� ���.\n";
			system("pause");
			return 0;
			break;
		}
		}
		if (1 < x * b < 10)
		{
			s = exp(x);
			cout << "����� ��� �� ����� 1" << endl;
		}
		else
		{
			if (10 <= x * b < 40)
			{
				s = sqrt(fabs(x + 4 * b));
				cout << "����� ��� �� ����� 2" << endl;
			}
			else
			{
				s = b * pow(x, 2);
				cout << "����� ��� �� ����� 3" << endl;
			}
		}
		cout << "s = " << s << endl;
		break;
	}
	case '3': {
		int x;
		cout << "������� ����� �����: ";
		cin >> x;
		if (x > -120 && x < -100)
		{
			cout << "������ A" << endl;
		}
		else
		{
			if (x > 100 && x % 5 == 0)
			{
				cout << "������ B" << endl;
			}
			else
			{
				if (x < 0 && x % 2 == 0)
				{
					cout << "������ C" << endl;
				}
				else
				{
					cout << "������ D" << endl;
				}
			}
		}
		break;
	}
	case '4': {
		double a;
		int p;
		cout << "������� ��������� ��������� (�/ ���.��): ";
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
				cout << "������� ���������� �������� �� 1000 �� 11400" << endl;
				system("pause");
				return 0;
			}
		}
		switch (p)
		{
		case 1:
		{
			cout << "��������� �� ����� 7130 �/���.�� ����� ��������� ���������:\n������ - 11400\n���� - 8900\n����� - 7850\n���� - 7200\n����� - 7130" << endl;
			break;
		}
		case 2:
		{
			cout << "��������� ����� 7130 �/���.�� ����� ��������� ���������:\n������ - 2600\n�������� - 2500\n����� - 2400\n���� - 1000" << endl;
			break;
		}
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