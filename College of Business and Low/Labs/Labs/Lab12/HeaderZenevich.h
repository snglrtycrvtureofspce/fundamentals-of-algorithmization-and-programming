#include <iostream>
#include <Windows.h>
#include <ctime>
using namespace std;

float** CreateArray(int m, int n) {
    float** Array;
    Array = new float* [m];
    for (int i = 0; i < m; i++) {
        Array[i] = new float[n];
        if (Array[i] == NULL) {
            cout << "������ �� ���������������" << "��� ������" << i << '\n';
            system("pause");
            return 0;
        }
    }
    if (Array == NULL) {
        cout << "������ �� ���������������" << '\n';
        system("pause");
        return 0;
    }
    return Array;
}

float ZapolnenieVivodArray(float** Array, int m, int n) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            Array[i][j] = 1 + rand() % 10;
        }
    }
    cout << "����� �������:" << '\n';
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << Array[i][j] << ' ' << '|' << '\t';
        }
        cout << '\n';
    }
    return 0;
}

int SummaElementov(float** Array, int m, int n) {
    int summa = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) {
                summa += Array[i][j];
            }
        }
    }
    cout << "����� ��������� ������� ���������: " << summa << '\n';
    return 0;
}

int ProizvedenieElementov(float** Array, int m, int n, int y) {
    cout << "������� �������� x: ";
    cin >> y;
    int proizvedenie = 1;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if ((i != j) && Array[i][j] != y) {
                proizvedenie *= Array[i][j];
            }
        }
    }
    cout << "������������ ���������: " << proizvedenie << '\n';
    return 0;
}

int MaxSrednElementov(float** Array, int m, int n) {

    int count = 0, countBolsheSredn = 0, summa = 0, max = Array[0][0];
    double SrednArifm = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (Array[i][j] > max) {
                max = Array[i][j];
            }
            summa += Array[i][j];
            count++;
        }
    }
    SrednArifm = summa / count;
    cout << "������� ��������������: " << SrednArifm << "\n" << "������������ �������� �������: " << max << '\n';
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if ((Array[i][j] > SrednArifm) && (i != j)) {
                countBolsheSredn++;
            }
        }
    }
    cout << "���������� ��������� ������� ������� ������ ������ ���������������� � �� ����� �� ������� ���������: " << countBolsheSredn << '\n';
    return 0;
}