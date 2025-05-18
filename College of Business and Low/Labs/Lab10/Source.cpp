#include <iostream>
#include <cmath>
#include <Windows.h>
using namespace std;

int main()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	srand(time(NULL));
	char p;
	cout << "Выберите задание: ";
	cin >> p;
	switch (p) {
	case '1': {
		char s = 'S';
		char* ps = &s;
		char pz = *ps;
		cout << s << '\n' << *ps << '\n' << pz << '\n';
		s += 1;
		*ps += 1;
		pz += 1;
		cout << s << '\n' << *ps << '\n' << pz << '\n';
		break;
	}
	case '2': {
		const int SIZE = 100;
		int m[SIZE] = { 16,  78,  99,  26, -29,  19, -52,  65, -88,  51,
			  -79, -22,  32, -25, -62, -69, -42, -59, -75,  89,
			  -87,  95, -22,  85, -49, -75,  76,  73, -59, -52,
			   30,  49, -28, -48,   0,  57,  46, -85,   0, -18,
			  -97, -21, -95,  64,  22, -12,  69, -84, -11, -71,
			  -25,  47,  72,  43,  15, -44,  44,  61,  54,  74,
			   88, -61,   0, -64, -83,  97,   0,  90,  15,  28,
			  -54,  19,  73,  35, -67, -87,  85, -99, -70,  10,
			   98,  58, -10, -29,  95,  62,  77,  89,  36, -32,
			   78,  60, -79, -18,  30, -13, -34, -92,  61, -38 };
		int iMax = 0, iMin = 0;
		for (int i = 0; i < SIZE; i++) {
			if (m[i] < iMin) {
				iMin = i;
			}
			if (m[i] > iMax) {
				iMax = i;
			}
		}
		int znach = iMax - iMin;
		cout << znach << '\n';
		break;
	}
	case '3': {
		const int rows = 10, cols = 10;
		int arr[rows][cols] = { {16,  78,  99,  26, -29,  19, -52,  65, -88,  51 },
			{-79, -22,  32, -25, -62, -69, -42, -59, -75,  89 },
			{-87,  95, -22,  85, -49, -75,  76,  73, -59, -52},
			{30,  49, -28, -48,   0,  57,  46, -85,   0, -18},
			{-97, -21, -95,  64,  22, -12,  69, -84, -11, -71},
			{-25,  47,  72,  43,  15, -44,  44,  61,  54,  74},
			{88, -61,   0, -64, -83,  97,   0,  90,  15,  28},
			{-54,  19,  73,  35, -67, -87,  85, -99, -70,  10},
			{98,  58, -10, -29,  95,  62,  77,  89,  36, -32},
			{78,  60, -79, -18,  30, -13, -34, -92,  61, -38 } };
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++) {
				if (i == j) {
					cout << &arr[i][j] << '\t';
				}
			}
		}
		break;
	}
	case '4': {
		const int z = 12, m = 5, n = 3;
		int count = 0;
		char arr[z][m][n];
		for (int i = 0; i < z; i++) {
			for (int j = 0; j < m; j++) {
				for (int k = 0; k < n; k++) {
					arr[i][j][k] = 'A' + rand() % ('Z' - 'A' + 1);
				}
			}
		}
		for (int i = 0; i < z; i++) {
			for (int j = 0; j < m; j++) {
				for (int k = 0; k < n; k++) {
					cout << arr[i][j][k] << '\t';
				}
			}
		}
		for (int i = 0; i < z; i++) {
			for (int j = 0; j < m; j++) {
				for (int k = 0; k < n; k++) {
					if (*(*(*(arr + i) + j) + k) == *(*(*(arr + i) + j) + k - 1)) {
						count++;
					}
				}
			}
		}
		cout << "Повторяющиеся символы: " << count << '\n';
		break;
	}
	case '5': {
		int* a;
		int b[2];
		a = b;
		b[0] = 7;
		b[1] = 10;
		(*(b + 1))++;
		cout << *(a + 1) << '\n';
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