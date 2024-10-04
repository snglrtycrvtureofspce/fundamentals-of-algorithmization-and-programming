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
		int n, m;
		do {
			cout << "������� ������ ������� �������: ";
			cin >> n;
			cout << '\n';
		} while (n <= 0);
		do {
			cout << "������� ������ ������� �������: ";
			cin >> m;
			cout << '\n';
		} while (m <= 0);
		int* A = new int[n];
		int* B = new int[m];
		if (A == NULL) {
			cout << "�� ������� �������� ������ ��� ������ ������.\n";
			system("pause");
			return 0;
		}
		if (B == NULL) {
			cout << "�� ������� �������� ������ ��� ������ ������.\n";
			system("pause");
			return 0;
		}
		cout << "������� �������� ������� �������: " << endl;
		for (int i = 0; i < n; i++) {
			cout << "A[" << i << "] = ";
			cin >> A[i];
		}
		cout << "������� �������� ������� �������: " << endl;
		for (int i = 0; i < m; i++) {
			cout << "B[" << i << "] = ";
			cin >> B[i];
		}
		cout << "_______________________________________________________\n";
		int max = A[0], max2 = B[0], iMax = 0, iMax2 = 0;
		for (int i = 0; i < n; i++) {
			if (A[i] > max) {
				max = A[i];
				iMax = i;
			}
		}
		for (int i = 0; i < n; i++) {
			if (B[i] > max) {
				max2 = B[i];
				iMax2 = i;
			}
		}
		if (max > max2) {
			cout << "������� ������ ������: " << '\n';
			for (int i = 0; i < n; i++) {
				cout << "A[" << i << "] = " << A[i] << '\n';
			}
			cout << "���������� �������� �������� ������� �������: " << max << " � �������� � �������� � " << iMax << endl;
		}
		else {
			cout << "������� ������ ������: " << '\n';
			for (int i = 0; i < m; i++) {
				cout << "B[" << i << "] = " << B[i] << '\n';
			}
			cout << "���������� �������� �������� ������� �������: " << max2 << " � �������� � �������� � " << iMax2 << endl;
		}
		delete[] A;
		delete[] B;
		A = NULL;
		B = NULL;
		break;
	}
	case '2': {
		int n;
		do {
			cout << "������� ������ �������: ";
			cin >> n;
			cout << '\n';
		} while (n <= 0);
		int* A = new int[n];
		if (A == NULL) {
			cout << "�� ������� �������� ������ ��� ������ ������.\n";
			system("pause");
			return 0;
		}
		cout << "������� �������� ������� �������: " << endl;
		for (int i = 0; i < n; i++) {
			cout << "A[" << i << "] = ";
			cin >> A[i];
		}
		cout << "_______________________________________________________\n";
		int min = A[0], iMin = 0, sum = 0, xd = 0;
		for (int i = 0; i < n; i++) {
			if (A[i] < min) {
				min = A[i];
				xd += 1;
			}
		}
		for (int i = 0; i < xd; i++) {
			sum += A[i];
		}
		cout << "����� ��������� �� ������������ �������� �������: " << sum << '\n';
		delete[] A;
		A = NULL;
		break;
	}
	case '3': {
		const int n = 10;
		int* A = new int[n];
		if (A == NULL) {
			cout << "�� ������� �������� ������ ��� ������ ������.\n";
			system("pause");
			return 0;
		}
		cout << "������� �������� �������: " << endl;
		for (int i = 0; i < n; i++) {
			cout << "A[" << i << "] = ";
			cin >> A[i];
		}
		cout << "_______________________________________________________\n";
		int min = A[0], iMin = 0, xd = 0;
		for (int i = 0; i < n; i++) {
			if (A[i] < min) {
				min = A[i];
				xd += 1;
			}
		}
		for (int i = 0; i < n; i++) {
			if (A[i] > 0) {
				A[i] = min;
			}
		}
		for (int i = 0; i < n; i++) {
			cout << A[i] << '\n';
		}
		delete[] A;
		A = NULL;
		break;
	}
	case '4': {
		int* A = new int[] {33, 0, 28, -16, -32, 74, 0, -30, 99, 0};
		int max = A[0], iMax = 0;
		for (int i = 0; i < (_msize(A) / sizeof(A[0])); i++) {
			if (A[i] > max) {
				max = A[i];
				iMax = i;
			}
		}
		cout << "����� ������������� �������� �������: " << max << '\n';
		cout << "_______________________________________________________\n";
		int mul = 1;
		for (int i = 0; i < (_msize(A) / sizeof(A[0])); i++) {
			if (A[i] == 0) {
				break;
			}
			mul *= A[i];
		}
		cout << "������������ ��������� �������, ������������� ����� ������ � ������ �������� ����������: " << mul << '\n';
		cout << "_______________________________________________________\n";
		/*
		int p, S[10], j = 0, k = 0;
		for (int i = 0; i < 10; i++)  //������������ �������� �����
		{
			p = i % 2;
			if (p == 0)
			{
				A[j] = S[i];
				j++;
				k++;
				S[i] = 0;
			}
		}
		for (int i = 0; i < 10; i++)  //������������ ������ �����
		{
			if (S[i] != 0)
			{
				A[k] = S[i];
				k++;
			}
		}
		for (int i = 0; i < (_msize(A) / sizeof(A[0])); i++) {
			cout << "A[" << i << "] = " << A[i] << '\n';
		}
		*/
		delete[] A;
		A = NULL;
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