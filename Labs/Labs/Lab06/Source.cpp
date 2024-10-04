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
		int a = 0;
		const int SIZE = 15;
		double arr[SIZE];
		srand(time(NULL));
		for (int i = 0; i < SIZE; i++)
		{
			arr[i] = rand();
		}
		cout << "Количество элементов значения которых больше первого элемента: " << endl;
		for (int i = 0; i < SIZE; i++)
		{
			if (arr[0] < arr[i])
			{
				cout << arr[i] << endl;
				a += 1;
			}
		}
		cout << "Всего элементов: " << a << endl;
		break;
	}
	case '2': {
		const int SIZE = 12;
		char* arr[SIZE] = { "А","Б","В","Г","Д","Е","Ё","Ж","З","И","Л","С" };
		for (int i = 0; i < SIZE; i++)
		{
			cout << arr[i];
		}
		cout << "\n";
		for (int i = 0; i < SIZE; i++)
		{
			cout << arr[i] << endl;
		}
		break;
	}
	case '3': {
		const int SIZE = 10;
		int arr[SIZE];

		cout << "������� �������� �������: " << endl;
		for (int i = 0; i < SIZE; i++)
		{
			cin >> arr[i];
		}
		cout << "_____________________________________________________________________________________________________________" << endl;
		for (int i = 0; i < SIZE; i++)
		{
			cout << arr[i] << "\t";
		}
		cout << endl;
		for (int i = 0; i < SIZE; i++)
		{
			if (arr[i] != 0)
			{
				cout << arr[i];
			}
		}
		cout << endl;
		break;
	}
	case '4': {
		const int SIZE = 10;
		double massiv[SIZE]{};
		cout << "Введите данные массива: " << endl;
		for (int i = 0; i < SIZE; i++)
		{
			cin >> massiv[i];
		}
		for (int i = 0; i < SIZE; i++)
		{
			cout << "massiv" << "[" << i << "] = " << massiv[i] << endl;
		}
		cout << "\n";
		for (int i = 0; i < SIZE; i++)
		{
			if (i % 4 != 0) {
				continue;
			}
			cout << "massiv" << "[" << i << "] = " << massiv[i] << endl;
		}
		break;
	}
	case '5': {
		srand(time(NULL));

		const int SIZE = 1220;
		int arr[SIZE]{};

		for (int i = 0; i < SIZE; i++) {
			arr[i] = 10 + rand() % 10; // a + rand() % (b - a + 1)
			cout << arr[i] << "\t";
		}
		cout << "\n";

		for (int i = 765; i < 949; i++) {
			cout << arr[i];
		}
		cout << "\n\n";

		for (int i = 999; i <= 1099; i++) {
			cout << arr[i];
		}
		cout << endl;
		break;
	}
	case '6': {
		const int SIZE = 14;
		int arr[SIZE]{};

		cout << "Введите элементы массива: " << endl;
		for (int i = 0; i < SIZE; i++) {
			cin >> arr[i];
		}
		for (int i = 0; i < SIZE; i++) {
			if (i % 7 == 0)
			{
				cout << "Кратен 7: " << arr[i] / 11000 << endl;
			}
			else {
				cout << "vector[" << i << "] = " << arr[i] << endl;
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