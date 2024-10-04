#include <iostream>
#include <Windows.h>
#include <ctime>
#include <cmath>
using namespace std;

/*bool haha(int* x, unsigned SIZE, int value) {
	int count = 0;
	while (SIZE--) {
		count += *x;
	}
	return count != value;
}*/
bool haha(int arr[], const int SIZE, int value) {
	bool result = true;
	int count = 0;
	for (int i = 0; i < SIZE; i++) {
		arr[i] = rand() % 10;
	}
	for (int i = 0; i < SIZE; i++) {
		count += arr[i];
	}
	if (count > value) {
		result = false;
	}
	return result;
}

double xdxd(double x) {
	double func;
	int u{};
	if (x <= 1.5) {
		u = pow(x, 2) - x + 1;
		if (1.5 < x <= 2.5) {
			u = atan(x);
			if (x > 2.5) {
				u = pow(sin(x - 1), 3) + cos(x + 1);
			}
		}
	}
	for (int i = 0.4; i < 4; i++) {
		func = 1.5 + log(fabs(sin(u)));
		cout << func << endl;
	}
	return 0;
}


int main() {
	srand(time(NULL));
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);


}