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
		double a, r, x, y;
		int p;
		cout << "������� x: ";
		cin >> x;
		cout << "������� y: ";
		cin >> y;
		cout << "����: \n1-���������� sh(x)\n2-���������� x^2\n3-���������� ���������� exp(x)\n�������� ����� ����: ";
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
			cout << "������ �������� ���.\n";
			system("pause");
			return 0;
			break;
		}
		}
		cout << "f(x) = " << x << endl;
		if (x > y)
		{
			r = pow((fabs(x - y)), 1.0 / 3) + tan(x);
			cout << "����� ��� �� ������ �����\n";
		}
		else
		{
			if (x < y)
			{
				r = (pow(y - x, 3) + cos(x));
				cout << "����� ��� �� ������ �����\n";
			}
			else
			{
				if (x == y)
				{
					r = pow(x + y, 2) + pow(x, 3);
					cout << "����� ��� �� ������� �����\n";
				}
				else
				{
					cout << "����� ���������� ����������, ������� ����� ��������";
					system("pause");
					return 0;
				}
			}
		}
		cout << "��������� ����������: " << r << endl;
		break;
	}
	case '2': {
		float x, y, R, hyph;
		cout << "������� ���������� ����� � ������ �����" << endl;
		cout << "x= ";
		cin >> x;
		cout << "y= ";
		cin >> y;
		cout << "r= ";
		cin >> R;
		hyph = sqrt(pow(x, 2) + pow(y, 2));

		if (hyph <= R) {
			cout << "����� ����������� �����" << endl;
		}
		else
			cout << "����� �� ����������� �����" << endl;
		break;
	}
	case '3': {
		double c, d, k, y, z, x;
		cout << "������� c: ";
		cin >> c;
		cout << "������� z, ���� z > 0, ������� x = z^2 - z, � ���� z >= 0, ������� x = z^3: ";
		cin >> z;
		cout << "������� d: ";
		cin >> d;
		cout << "������� k: ";
		cin >> k;

		if (z < 0)
		{
			x = pow(z, 2) - z;
			cout << "������� ����������� �� ������ �����" << endl;
		}
		else
		{
			if (z >= 0)
			{
				x = pow(z, 3);
				cout << "������� ����������� �� ������ �����" << endl;
			}
		}
		y = pow(sin(c * x + pow(d, 2) + k * pow(x, 2)), 3);
		cout << "y = " << y << endl;
		break;
	}
	case '4': {
		int x, y, ma, mi, t;
		cout << "������� x: ";
		cin >> x;
		cout << "������� y: ";
		cin >> y;
		ma = max(y, 0);
		mi = min(x, 5);
		t = ma * (mi, ma) / 5;
		if (t > 0)
		{
			cout << "��� �����: " << t << endl;
		}
		else
		{
			if (t == 0)
			{
				cout << "���� ����� ����� ����� ����, ������� ��������� ��������" << endl;
				cout << "������� x: ";
				cin >> x;
				cout << "������� y: ";
				cin >> y;
				ma = max(y, 0);
				mi = min(x, 5);
				t = ma * (mi, ma) / 5;
				cout << "��� �����: " << t << endl;
			}
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