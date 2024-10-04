#include <iostream>
#include <Windows.h>
#include <ctime>
#include "HeaderZenevich.h"
using namespace std;

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    srand(time(NULL));
    int m, n;
    do {
        cout << "Размер строки массива: ";
        cin >> m;
        if (m < 1) {
            cout << "Введите значения больше нуля." << '\n';
        }
    } while (m < 1);

    do {
        cout << "Размер столбца массива: ";
        cin >> n;
        if (n < 1) {
            cout << "Введите значения больше нуля." << '\n';
        }
    } while (n < 1);

    float** arr;
    arr = CreateArray(m, n);
    ZapolnenieVivodArray(arr, m, n);
    SummaElementov(arr, m, n);
    int x = 0;
    ProizvedenieElementov(arr, m, n, x);
    MaxSrednElementov(arr, m, n);
    system("pause");
    return 0;
}