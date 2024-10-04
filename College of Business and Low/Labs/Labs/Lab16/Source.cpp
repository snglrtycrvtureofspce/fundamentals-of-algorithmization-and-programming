#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;

struct state {
    int code;
    char name[100];
    double square;
    char president[100];
};

struct train {
    char nameofpunkt[100];
    int nubmeroftrain;
    char timeGO[100];
};

int main() {
    setlocale(LC_ALL, "");
    int count = 0;
    do {
        cout << "Сколько на вашем континенте государств? - ";
        cin >> count;
        if (count < 1) {
            cout << "Количество государств должно быть больше нуля" << endl;
        }
    } while (1 > count);
    state* continent = new state[count];
    if (continent == NULL) {
        cout << "Память друг, память.." << endl;
        return 0;
    }
    else {
        cout << endl;
    }
    for (int i = 0; i < count; i++) {
        cout << "Введите код государства: ";
        cin >> continent[i].code;
        cout << "\nВведите название государства: ";
        cin >> continent[i].name;
        cout << "\nВведите площадь государства: ";
        cin >> continent[i].square;
        cout << "\nВведите имя президента: ";
        cin >> continent[i].president;
        int opisanie = 1;
        if (count > 1) {
            cout << "Описание " << opisanie + 1 << " государства: " << endl;
        }
    }
    cout << "На вашем континенте " << count << " городов" << "\nИх описание: " << endl;
    for (int i = 0; i < count; i++) {
        cout << "Код: " << continent[i].code << endl;
        cout << "Название: " << continent[i].name << endl;
        cout << "Площадь: " << continent[i].square << endl;
        cout << "Имя президента: " << continent[i].president << endl;
        cout << "_________________________________________________\n";
    }
    char findname[100];
    int countSOVPADENII = 0;
    cout << "Какой город вы ищете? - ";
    cin >> findname;
    for (int i = 0; i < count; i++) {
        int a = strcmp(continent[i].name, findname);
        if (a == 0) {
            countSOVPADENII++;
        }
    }
    if (countSOVPADENII == 0) {
        cout << "Государств с таким названием нету..." << endl;
    }
    else {
        cout << "С таким названием есть - " << countSOVPADENII << " городов" << endl;
    }
    delete[] continent;
    continent = nullptr;

    int countSTRUCT;
    cout << "Сколько у вас структур в массиве? - ";
    cin >> countSTRUCT;
    train mas[countSTRUCT];
    for (int i = 0; i < countSTRUCT; i++) {
        cout << "Пункт назначения: ";
        cin >> mas[i].nameofpunkt;
        cout << "\nНомер поезда: ";
        cin >> mas[i].nubmeroftrain;
        cout << "\nВремя отправления: ";
        cin >> mas[i].timeGO;
        int opisanie = 1;
        if (count > 1) {
            cout << "Описание " << opisanie + 1 << " структуры: " << endl;
        }
    }
    cout << "В вашем массиве" << countSTRUCT << " структур" << "\nИх описание: " << endl;
    for (int i = 0; i < count; i++) {
        cout << "Пункт: " << mas[i].nameofpunkt << endl;
        cout << "Номер: " << mas[i].nubmeroftrain << endl;
        cout << "Время**: " << mas[i].timeGO << endl;
        cout << "_________________________________________________\n";
    }
    system("pause");
    return 0;
}