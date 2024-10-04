#include <iostream>
#include <Windows.h>

using namespace std;

class Firm {
private:
	int codeofFirm; // ��� �����
	double sizeofFirm; // ������ �����
	char categoryoffirm; // ��������� �����
	char nameofFirm[100]; // ��� �����

	double RevenueVolume; // ����� �������
	double PayrollCosts; // ������� �� ��������
	double EnergyCosts; // ������� �� �������
	double RawCosts; // ������� �� �����
	double RentCosts; // ������� �� ������
	double FSZNTax; // ����� �� ���� %
	double ProfitTax; // ����� �� ������� %
	double VAT; // ��� %

public:
	Firm() {
		cout << "���������� ����������� �� ���������" << endl;
	}

	void SetcodeofFirm() {
		int valuecodeofFirm = 0;
		do {
			cout << "������� ��� ����� �����: ";
			cin >> valuecodeofFirm;
			if (valuecodeofFirm < 0) {
				cout << "�������� �� ������ ���� ������ ����, ���������� ��� ���!" << endl;
			}
		} while (valuecodeofFirm < 0);
		codeofFirm = valuecodeofFirm;
	}
	int GetcodeofFirm() {
		return codeofFirm;
	}

	void SetsizeofFirm() {
		double valuesizeofFirm = 0;
		do {
			cout << "������� ������ ����� �����: ";
			cin >> valuesizeofFirm;
			if (valuesizeofFirm < 0) {
				cout << "�������� �� ������ ���� ������ ����, ���������� ��� ���!" << endl;
			}
		} while (valuesizeofFirm < 0);
		sizeofFirm = valuesizeofFirm;
	}
	double GetsizeofFirm() {
		return sizeofFirm;
	}

	void SetcategoryofFirm() {
		char valuecategoryofFirm;
		cout << "������� ��������� ����� �����: ";
		cin >> valuecategoryofFirm;
		categoryoffirm = valuecategoryofFirm;
	}

	char GetcategoryofFirm() {
		return categoryoffirm;
	}

	char* SetnameofFirm(char valuenameofFirm[]) {
		if (strlen(valuenameofFirm) > 0) {
			strcpy_s(nameofFirm, strlen(valuenameofFirm) + 1, valuenameofFirm);
			return nameofFirm;
		}
		else {
			return nullptr;
		}
	}
	char* GetnameofFirm() {
		return nameofFirm;
	}

	void GetInfoAboutTAX() {
		double ValueRevenueVolume = 0.0; // ����� �������
		double ValuePayrollCosts = 0.0; // ������� �� ��������
		double ValueEnergyCosts = 0.0; // ������� �� �������
		double ValueRawCosts = 0.0; // ������� �� �����
		double ValueRentCosts = 0.0; // ������� �� ������
		double ValueFSZNTax = 0.0; // ����� �� ���� %
		double ValueProfitTax = 0.0; // ����� �� ������� %
		double ValueVAT = 0.0; // ��� %

		cout << "������� ����� �������: ";
		cin >> ValueRevenueVolume;
		RevenueVolume = ValueRevenueVolume;

		cout << "������� ������� �� ��������: ";
		cin >> ValuePayrollCosts;
		PayrollCosts = ValuePayrollCosts;

		cout << "������� ������� �� �������: ";
		cin >> ValueEnergyCosts;
		EnergyCosts = ValueEnergyCosts;

		cout << "������� ������� �� �����: ";
		cin >> ValueRawCosts;
		RawCosts = ValueRawCosts;

		cout << "������� ������� �� ������: ";
		cin >> ValueRentCosts;
		RentCosts = ValueRentCosts;

		cout << "������� ����� �� ���� (� %): ";
		cin >> ValueFSZNTax;
		FSZNTax = ValueFSZNTax;

		cout << "������� ����� �� ������� (� %): ";
		cin >> ValueProfitTax;
		ProfitTax = ValueProfitTax;

		cout << "������� ��� (� %): ";
		cin >> ValueVAT;
		VAT = ValueVAT;
	}

	double AmountOfTax() {
		double TaxSum = 0.0;
		double X = ((RevenueVolume - PayrollCosts) * ((FSZNTax + VAT) / 100));
		double A = (RevenueVolume - PayrollCosts);
		if ((A - X) > 0) {
			TaxSum = X + A * (ProfitTax / 100);
		}
		else {
			TaxSum = X;
		}
		return TaxSum;
	}

	void show() {
		cout << "____________________________________" << endl;
		cout << "��� ����� �����: " << codeofFirm << "\n������ �����: " << sizeofFirm << "\n���� �����: " << categoryoffirm << "\n��� �����: " << nameofFirm << endl;
		cout << "____________________________________" << endl;
		cout << "����� �������: " << RevenueVolume << "\n������� �� ��������: " << PayrollCosts << "\n������� �� �������: " << EnergyCosts << "\n������� �� �����: " << RawCosts << "\n������� �� ������: " << RentCosts << "\n����� �� ���� (� %): " << FSZNTax << "\n����� �� ������� (� %): " << ProfitTax << "\n��� (� %): " << VAT << endl;
		cout << "____________________________________" << endl;
		cout << "����� �������: " << AmountOfTax() << endl;
	}

	~Firm() { GetcodeofFirm(); GetsizeofFirm(); GetcategoryofFirm(); GetnameofFirm(); AmountOfTax(); };
};

int main() {
	setlocale(LC_ALL, "");

	Firm a{};
	const int SIZE = 100;
	a.SetcodeofFirm();
	a.SetsizeofFirm();
	a.SetcategoryofFirm();
	char c[SIZE];
	cout << "������� ��� �����: ";
	cin.ignore();
	cin.getline(c, SIZE);
	a.SetnameofFirm(c);
	a.GetInfoAboutTAX();
	a.show();
	a.~Firm();

	Firm* a0 = new Firm();
	if (a0 == NULL) {
		cout << "������ �������� ���������� ������ Firm" << endl;
		system("pause");
		return 0;
	}
	a0->show();

	system("pause");
	return 0;
} 