#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <Windows.h>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <iterator>
#include <cctype>


int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	/*for (unsigned short int i = 0; i < 256; i++) {
		cout << i << '\t' << char(i) << '\n';
	}*/
	int mission;
	std::cout << "Введите задание: ";
	std::cin >> mission;
	switch (mission) {
	case(1): {
		const int SIZE = 100;
		char findsymbol = 0, str[SIZE]{};
		std::cin.ignore();
		std::cin.getline(str, SIZE);
		std::cout << "Введите символ который хотите найти: ";
		std::cin >> findsymbol;
		for (int i = 0; i < strlen(str); i++) {
			if ((str[i]) == findsymbol) {
				std::cout << "Найден символ " << findsymbol << "\tв строке: " << i << '\n';
			}
		}
		break;
	}
	case(2): {
		const int SIZE = 100;
		char symbol = 0, str[SIZE]{};
		std::cin.ignore();
		std::cin.getline(str, SIZE);
		std::cout << "Введите символ: ";
		std::cin >> symbol;
		for (int i = 0; i < strlen(str); i++) {
			std::cout << str[i] << symbol;
		}
		break;
	}
	case(3): {
		const int SIZE = 100;
		char str[SIZE]{};
		std::cin.ignore();
		std::cin.getline(str, SIZE);
		std::cout << strlen(str) << '\n';
		break;
	}
	case(4): {
		const int SIZE = 100;
		int count = 0;
		char consonants[]{ 'a', 'e', 'i', 'o', 'u', 'y', '\0' }, str[SIZE]{};
		std::cin.ignore();
		std::cin.getline(str, SIZE);
		for (int i = 0; i < strlen(str); i++) {
			for (int j = 0; j < sizeof(consonants); j++) {
				if (str[i] == consonants[j]) {
					count++;
					break;
				}
			}
		}
		std::cout << "Количество: " << count << std::endl;
		break;
	}
	case(5): {
		const int SIZE = 100;
		int count = 0;
		char str[SIZE]{};
		std::cin.ignore();
		std::cin.getline(str, SIZE);
		for (int i = 0; i < strlen(str); i++) {
			if (str[i] == str[i - 1]) {
				count++;
			}
		}
		std::cout << "Количество: " << count << std::endl;
		break;
	}
	default: {
		std::cout << "Вы ввели неправильный номер" << std::endl;
		break;
	}
	}
	system("pause");
	return 0;
}