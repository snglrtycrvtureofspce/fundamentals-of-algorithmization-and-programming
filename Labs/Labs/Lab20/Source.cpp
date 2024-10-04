#include <iostream>
#include <Windows.h>

using namespace std;

class Firm {
private:
	int codeofFirm; // код фирмы
	double sizeofFirm; // размер фирмы
	char categoryoffirm; // категория фирмы
	char nameofFirm[100]; // имя фирмы

	double RevenueVolume; // объём выручки
	double PayrollCosts; // затраты на зарплату
	double EnergyCosts; // затраты на энергию
	double RawCosts; // затраты на сырьё
	double RentCosts; // затраты на аренду
	double FSZNTax; // налог на ФСЗН %
	double ProfitTax; // налог на прибыль %
	double VAT; // НДС %

public:
	Firm() {
		cout << "Используем конструктор по умолчанию" << endl;
	}

	void SetcodeofFirm() {
		int valuecodeofFirm = 0;
		do {
			cout << "Введите код вашей фирмы: ";
			cin >> valuecodeofFirm;
			if (valuecodeofFirm < 0) {
				cout << "Значение не должно быть меньше нуля, попробуйте ещё раз!" << endl;
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
			cout << "Введите размер вашей фирмы: ";
			cin >> valuesizeofFirm;
			if (valuesizeofFirm < 0) {
				cout << "Значение не должно быть меньше нуля, попробуйте ещё раз!" << endl;
			}
		} while (valuesizeofFirm < 0);
		sizeofFirm = valuesizeofFirm;
	}
	double GetsizeofFirm() {
		return sizeofFirm;
	}

	void SetcategoryofFirm() {
		char valuecategoryofFirm;
		cout << "Введите категорию вашей фирмы: ";
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
		double ValueRevenueVolume = 0.0; // объём выручки
		double ValuePayrollCosts = 0.0; // затраты на зарплату
		double ValueEnergyCosts = 0.0; // затраты на энергию
		double ValueRawCosts = 0.0; // затраты на сырьё
		double ValueRentCosts = 0.0; // затраты на аренду
		double ValueFSZNTax = 0.0; // налог на ФСЗН %
		double ValueProfitTax = 0.0; // налог на прибыль %
		double ValueVAT = 0.0; // НДС %

		cout << "Введите объём выручки: ";
		cin >> ValueRevenueVolume;
		RevenueVolume = ValueRevenueVolume;

		cout << "Введите затраты на зарплату: ";
		cin >> ValuePayrollCosts;
		PayrollCosts = ValuePayrollCosts;

		cout << "Введите затраты на энергию: ";
		cin >> ValueEnergyCosts;
		EnergyCosts = ValueEnergyCosts;

		cout << "Введите затраты на сырьё: ";
		cin >> ValueRawCosts;
		RawCosts = ValueRawCosts;

		cout << "Введите затраты на аренду: ";
		cin >> ValueRentCosts;
		RentCosts = ValueRentCosts;

		cout << "Введите налог еа ФСЗН (в %): ";
		cin >> ValueFSZNTax;
		FSZNTax = ValueFSZNTax;

		cout << "Введите налог на прибыль (в %): ";
		cin >> ValueProfitTax;
		ProfitTax = ValueProfitTax;

		cout << "Введите НДС (в %): ";
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
		cout << "Код вашей фирмы: " << codeofFirm << "\nРазмер фирмы: " << sizeofFirm << "\nЛого фирмы: " << categoryoffirm << "\nИмя фирмы: " << nameofFirm << endl;
		cout << "____________________________________" << endl;
		cout << "Объём выручки: " << RevenueVolume << "\nЗатраты на зарплату: " << PayrollCosts << "\nЗатраты на энергию: " << EnergyCosts << "\nЗатраты на сырьё: " << RawCosts << "\nЗатраты на аренду: " << RentCosts << "\nНалог на ФСЗН (в %): " << FSZNTax << "\nНалог на прибыль (в %): " << ProfitTax << "\nНДС (в %): " << VAT << endl;
		cout << "____________________________________" << endl;
		cout << "Сумма налогов: " << AmountOfTax() << endl;
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
	cout << "Введите имя фирмы: ";
	cin.ignore();
	cin.getline(c, SIZE);
	a.SetnameofFirm(c);
	a.GetInfoAboutTAX();
	a.show();
	a.~Firm();

	Firm* a0 = new Firm();
	if (a0 == NULL) {
		cout << "Ошибка создания экземпляра класса Firm" << endl;
		system("pause");
		return 0;
	}
	a0->show();

	system("pause");
	return 0;
} 