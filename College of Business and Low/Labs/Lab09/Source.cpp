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
        int rows, cols;

        do {
            cout << "Размер строки массива: ";
            cin >> rows;
            if (rows < 1) {
                cout << "Введите значения больше нуля." << '\n';
            }
        } while (rows < 1);

        do {
            cout << "Размер столбца массива: ";
            cin >> cols;
            if (cols < 1) {
                cout << "Введите значения больше нуля." << '\n';
            }
        } while (cols < 1);

        char** arr = new char* [rows];

        if (arr == NULL) {
            cout << "Память не зарезервирована" << '\n';
            system("pause");
            return 0;
        }

        for (int i = 0; i < rows; i++) {
            arr[i] = new char[cols];
            if (arr[i] == NULL) {
                cout << "Память не зарезервирована" << "для строки" << i << '\n';
                system("pause");
                return 0;
            }
        }

        cout << "Введите значения массива: " << '\n';
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cin >> arr[i][j];
            }
        }

        cout << "_______________________________________________________________" << '\n';
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cout << arr[i][j] << '\t';
            }
            cout << '\n';
        }

        for (int i = 0; i < rows; i++) {
            delete[] arr[i];
            arr[i] == NULL;
        }

        delete[] arr;
        arr = NULL;
		break;
	}
	case '2': {
        int rows, cols;

        do {
            cout << "Размер строки массива: ";
            cin >> rows;
            if (rows < 1) {
                cout << "Введите значения больше нуля." << '\n';
            }
        } while (rows < 1);

        do {
            cout << "Размер столбца массива: ";
            cin >> cols;
            if (cols < 1) {
                cout << "Введите значения больше нуля." << '\n';
            }
        } while (cols < 1);

        double** arr = new double* [rows];

        if (arr == NULL) {
            cout << "Память не зарезервирована" << '\n';
            system("pause");
            return 0;
        }

        for (int i = 0; i < rows; i++) {
            arr[i] = new double[cols];
            if (arr[i] == NULL) {
                cout << "Память не зарезервирована" << "для строки" << i << '\n';
                system("pause");
                return 0;
            }
        }

        cout << "Введите значения массива: " << '\n';
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cin >> arr[i][j];
            }
        }

        cout << "Print array:" << '\n';
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cout << arr[i][j] << ' ' << ';' << '\t';
            }
            cout << '\n';
        }

        for (int i = 0; i < rows; i++) {
            delete[] arr[i];
            arr[i] == NULL;
        }

        delete[] arr;
        arr = NULL;
		break;
	}
	case '3': {
        srand(time(NULL));
        int rows, cols;

        do {
            cout << "Размер строки массива: ";
            cin >> rows;
            if (rows < 1) {
                cout << "Введите значения больше нуля." << '\n';
            }
        } while (rows < 1);

        do {
            cout << "Размер столбца массива: ";
            cin >> cols;
            if (cols < 1) {
                cout << "Введите значения больше нуля." << '\n';
            }
        } while (cols < 1);

        int** arr = new int* [rows];

        if (arr == NULL) {
            cout << "Память не зарезервирована" << '\n';
            system("pause");
            return 0;
        }

        for (int i = 0; i < rows; i++) {
            arr[i] = new int[cols];
            if (arr[i] == NULL) {
                cout << "Память не зарезервирована" << "для строки" << i << '\n';
                system("pause");
                return 0;
            }
        }

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                arr[i][j] = 39 + rand() % ((51 - 39) + 1);
            }
        }


        cout << "Show massiv:" << '\n';
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cout << arr[i][j] << ' ' << '|' << '\t';
            }
            cout << '\n';
        }
        cout << "Show reverse massiv:" << '\n';
        for (int i = rows - 1; i > -1; i--) {
            for (int j = cols - 1; j > -1; j--) {
                cout << arr[i][j] << ' ' << '|' << '\t';
            }
            cout << '\n';
        }


        for (int i = 0; i < rows; i++) {
            delete[] arr[i];
            arr[i] == NULL;
        }

        delete[] arr;
        arr = NULL;
		break;
	}
    case '4': {
        srand(time(NULL));
        int rows, cols;

        do {
            cout << "Размер строки массива: ";
            cin >> rows;
            if (rows < 1) {
                cout << "Введите значения больше нуля." << '\n';
            }
        } while (rows < 1);

        do {
            cout << "Размер столбца массива: ";
            cin >> cols;
            if (cols < 1) {
                cout << "Введите значения больше нуля." << '\n';
            }
        } while (cols < 1);

        int** arr = new int* [rows];

        if (arr == NULL) {
            cout << "Память не зарезервирована" << '\n';
            system("pause");
            return 0;
        }

        for (int i = 0; i < rows; i++) {
            arr[i] = new int[cols];
            if (arr[i] == NULL) {
                cout << "Память не зарезервирована" << "для строки" << i << '\n';
                system("pause");
                return 0;
            }
        }
        int m = 99;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                arr[i][j] = m; //от 99 до n1 с шагом –2
                m -= 2;
            }
        }


        cout << "Print massiv:" << '\n';
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cout << arr[i][j] << ' ' << '|' << '\t';
            }
            cout << '\n';
        }

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                arr[i][j] += 11;
            }
        }

        cout << "Print new massiv:" << '\n';
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cout << arr[i][j] << ' ' << '|' << '\t';
            }
            cout << '\n';
        }


        for (int i = 0; i < rows; i++) {
            delete[] arr[i];
            arr[i] == NULL;
        }

        delete[] arr;
        arr = NULL;
        break;
    }
    case '5': {
        srand(time(NULL));
        int rows, cols;

        do {
            cout << "Размер строки массива: ";
            cin >> rows;
            if (rows < 1) {
                cout << "Введите значения больше нуля." << '\n';
            }
        } while (rows < 1);

        do {
            cout << "Размер столбца массива: ";
            cin >> cols;
            if (cols < 1) {
                cout << "Введите значения больше нуля." << '\n';
            }
        } while (cols < 1);

        double** arr = new double* [rows];

        if (arr == NULL) {
            cout << "Память не зарезервирована" << '\n';
            system("pause");
            return 0;
        }

        for (int i = 0; i < rows; i++) {
            arr[i] = new double[cols];
            if (arr[i] == NULL) {
                cout << "Память не зарезервирована" << "для строки" << i << '\n';
                system("pause");
                return 0;
            }
        }

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                arr[i][j] = rand();
            }
        }


        cout << "Print massiv:" << '\n';
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cout << arr[i][j] << ' ' << '|' << '\t';
            }
            cout << '\n';
        }

        cout << "New vision of array:" << '\n';
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (j % 2 != 0) {
                    cout << arr[i][j] << ' ' << '|' << '\t';
                }
            }
            cout << '\n';
        }


        for (int i = 0; i < rows; i++) {
            delete[] arr[i];
            arr[i] == NULL;
        }

        delete[] arr;
        arr = NULL;
        break;
    }
    case '6': {
        setlocale(LC_ALL, "");
        const int rows = 10, cols = 10;
        int m[rows][cols] = { { 16, 78, 0, 30, -29, 19, -52, -54, -88, 51},
    { -79, -22, 32, 49, -62, -69, -2, 99, -75, 89},
    { -87, 95, -22, -28, -49, -75, 76, 73, -59, -52},
    { 30, 49, -28, -48, 0, 57, -6, -85, 0, -18},
    { -99, -21, -95, 0, 22, -2, 69, -67, -1, -71},
    { -25, 47, 72, 57, 15, -44, 44, -87, 4, 74},
    { 88, -61, 0, -6, -83, 97, 0, 85, 15, 8},
    { -54, 99, 73, -85, -67, -87, 85, -93, -70, 10},
    { 98, 58, -10, 0, 95, 62, 77, -70, 36, -32},
    { 78, 60, -79, -18, 30, -13, -34, 10, 1, -38} };
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (i == j) {
                    cout << m[i][j] << '\t';
                }
            }
            cout << '\n';
        }
        cout << "_____________________________________________" << '\n';
        int max = 0;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (m[i][j] < 0) {
                    max += m[i][j];
                }
            }
        }
        cout << "Сумма: " << max << '\n';
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