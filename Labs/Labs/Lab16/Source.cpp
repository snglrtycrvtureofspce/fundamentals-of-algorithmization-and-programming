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
        cout << "������� �� ����� ���������� ����������? - ";
        cin >> count;
        if (count < 1) {
            cout << "���������� ���������� ������ ���� ������ ����" << endl;
        }
    } while (1 > count);
    state* continent = new state[count];
    if (continent == NULL) {
        cout << "������ ����, ������.." << endl;
        return 0;
    }
    else {
        cout << endl;
    }
    for (int i = 0; i < count; i++) {
        cout << "������� ��� �����������: ";
        cin >> continent[i].code;
        cout << "\n������� �������� �����������: ";
        cin >> continent[i].name;
        cout << "\n������� ������� �����������: ";
        cin >> continent[i].square;
        cout << "\n������� ��� ����������: ";
        cin >> continent[i].president;
        int opisanie = 1;
        if (count > 1) {
            cout << "�������� " << opisanie + 1 << " �����������: " << endl;
        }
    }
    cout << "�� ����� ���������� " << count << " �������" << "\n�� ��������: " << endl;
    for (int i = 0; i < count; i++) {
        cout << "���: " << continent[i].code << endl;
        cout << "��������: " << continent[i].name << endl;
        cout << "�������: " << continent[i].square << endl;
        cout << "��� ����������: " << continent[i].president << endl;
        cout << "_________________________________________________\n";
    }
    char findname[100];
    int countSOVPADENII = 0;
    cout << "����� ����� �� �����? - ";
    cin >> findname;
    for (int i = 0; i < count; i++) {
        int a = strcmp(continent[i].name, findname);
        if (a == 0) {
            countSOVPADENII++;
        }
    }
    if (countSOVPADENII == 0) {
        cout << "���������� � ����� ��������� ����..." << endl;
    }
    else {
        cout << "� ����� ��������� ���� - " << countSOVPADENII << " �������" << endl;
    }
    delete[] continent;
    continent = nullptr;

    int countSTRUCT;
    cout << "������� � ��� �������� � �������? - ";
    cin >> countSTRUCT;
    train mas[countSTRUCT];
    for (int i = 0; i < countSTRUCT; i++) {
        cout << "����� ����������: ";
        cin >> mas[i].nameofpunkt;
        cout << "\n����� ������: ";
        cin >> mas[i].nubmeroftrain;
        cout << "\n����� �����������: ";
        cin >> mas[i].timeGO;
        int opisanie = 1;
        if (count > 1) {
            cout << "�������� " << opisanie + 1 << " ���������: " << endl;
        }
    }
    cout << "� ����� �������" << countSTRUCT << " ��������" << "\n�� ��������: " << endl;
    for (int i = 0; i < count; i++) {
        cout << "�����: " << mas[i].nameofpunkt << endl;
        cout << "�����: " << mas[i].nubmeroftrain << endl;
        cout << "�����**: " << mas[i].timeGO << endl;
        cout << "_________________________________________________\n";
    }
    system("pause");
    return 0;
}