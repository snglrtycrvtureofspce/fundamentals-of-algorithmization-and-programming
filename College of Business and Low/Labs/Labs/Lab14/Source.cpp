#include <iostream>
#include <Windows.h>
#include <cmath>
#include "Header.h"
#include <ctime>
using namespace std;

int main() {
	setlocale(LC_ALL, "");
	int p;
	cout << "Выберите задание: ";
	cin >> p;
	switch (p) {
	case 1: {
		int N = 0, i = 0;
		cout << "Введите N: " << endl;
		cin >> N;
		cout << "Введите i: " << endl;
		cin >> i;
		cout << Rec(i, N) << '\n';
		break;
	}
	case 2: {
		srand(time(NULL));
		cout << "Первый способ: " << endl;
		double srZnach = 0, znach = 0;
		const int SIZE = 10;
		int arr[SIZE]{};
		for (int i = 0; i < SIZE; i++) {
			arr[i] = rand() % 10;
			znach += arr[i];
		}
		srZnach = znach / SIZE;
		cout << "Среднее значение: " << srZnach << endl;
		cout << "_______________________________________________" << endl;
		cout << "Второй способ: " << endl;
		cout << srZnachMas(arr, SIZE) << endl;
		break;
	}
	case 3: {
		srand(time(NULL));
		cout << "Первый способ: " << endl;
		double znach = 1;
		const int SIZE = 10;
		int arr[SIZE]{};
		for (int i = 0; i < SIZE; i++) {
			arr[i] = 1 + rand() % 5;
			cout << arr[i] << endl;
		}
		for (int i = 0; i < SIZE; i++) {
			if (arr[i] != 0) {
				znach *= arr[i];
			}
		}
		cout << "Произведение элементов массива: " << znach << endl;
		cout << "_______________________________________________" << endl;
		cout << "Второй способ: " << endl;
		cout << proizvMas(arr, SIZE - 1) << endl;
		break;
	}
	case 4: {
		int number, count = 1;
		cout << "Введите число: ";
		cin >> number;
		while ((number /= 10) > 0) {
			count++;
		}
		cout << "Количество цифр в числе: " << count << endl;
		cout << "_______________________________________________" << endl;
		cout << "Второй способ: " << endl;
		int number2;
		cout << "Введите второе число: ";
		cin >> number2;
		cout << countNubmers(number2) << endl;
		break;
	}
	default: {
		cout << "Не верный номер" << endl;
	}
	}

	system("pause");
	return 0;
}