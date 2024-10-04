#include <iostream>
#include <Windows.h>

using namespace std;

void swap(int& first, int& second) {
	int t = first;
	first = second;
	second = t;
}

int minimumFrom(int* m, int position, int length) {
	int minIndex = position;
	for (int i = position + 1; i < length; i++){
		if (m[i] < m[minIndex]) {
			minIndex = i;
		}
	}
	return minIndex;
}

void selectionSort(int* m, int length) {
	for (int i = 0; i < length - 1; i++){
		swap(m[i], m[minimumFrom(m, i, length)]);
	}
}

void BubbleSort(int* m, int n) { // метод пузырька
	for (int i = 0; i < n - 1; i++){
		for (int j = 0; i < n - i; i++){
			if (m[j] > m[j + 1]){ // по возрастанию
				int t = m[j];
				m[j] = m[j + 1];
				m[j + 1] = t;
			}
		}
	}
}

void insertSort(char* m, int n) { // метод вставок (имеет свойство устойчивости, при совпадении значений, они НЕ меняются местами)
	for (int i = 1; i < n; i++){ // по возрастанию
		char t = m[i];
		for (int j = i - 1; j > - 1 & t < m[j]; j--) {
			m[j + 1] = m[j];
			m[j] = t;
		}
	}
}

void quickSort(int* m, int left, int right) { // метод рекурсивной (Хоара)
	int leftArrow = left, rightArrow = right, pivot = m[(left + right) / 2];
	do {
		while (m[rightArrow] > pivot) {
			rightArrow--;
		}
		while (m[leftArrow] > pivot) {
			leftArrow++;
		}
		if (leftArrow <= rightArrow) {
			swap(m[leftArrow], m[rightArrow]);
			leftArrow++;
			rightArrow--;
		}
	} while (rightArrow >= leftArrow);
	if (left < leftArrow) {
		quickSort(m, left, rightArrow);
	}
	if (leftArrow < right) {
		quickSort(m, leftArrow, right);
	}
}

void shellSort(int* m, int n) { // метод Шелла (неустойчивая)
	for (int i = n / 2; i > 0; i = i / 2){
		for (int j = 0; j < n - i; j++){
			for (int k = j; k > -1; k = k - i){
				if (m[k] > m[k + i]) {
					int t = m[k];
					m[k] = m[k + i];
					m[k + i] = t;
				}
				else {
					k = 0;
				}
			}
		}
	}
}
