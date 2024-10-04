#include <iostream>
#include <fstream>

using namespace std;

struct Worker
{
	int age;
	double height;
	char name[15];
	char fam[20];
	bool sex;
}s;
bool f = false;

int main()
{
	setlocale(LC_ALL, "");
	int p = -1;
	while (p != 0)
	{
		cout << "1 - Entering text\n2 - Print text \n3 - Inject array into file \n4 - Output array from file \n5 - Add structure\n6 - Read structure \n7 - Add a binary structure\n8 - Read binary structure \n0 - End the program\n";;
		cin >> p;
		switch (p)
		{
		case 0:
		{
			cout << "End of the program ..." << endl;
			break;
		}
		case 1:
		{
			char s[100];
			cout << "\nEnter text up to 100 characters):\n";
			ofstream f("ZenevichLab18.txt", ios::out | ios::app);
			if (!f)
			{
				cout << "Error file \n";
				break;
			}
			cin.ignore();
			cin.getline(s, 100);
			f << s << endl;
			f.close();
			break;
		}
		case 2:
		{
			char str[100];
			ifstream f1("ZenevichLab18.txt", ios::in);
			if (!f1)
			{
				cout << "Error file \n";
				break;
			}
			f1.getline(str, 100, '\n');
			while (!f1.eof())
			{
				cout << str << endl;
				f1.getline(str, 100, '\n');
			}
			f1.close();
			cout << "ZenevichLab18.txt read and closed" << endl;
			break;
		}
		case 3:
		{
			const int n = 10;
			ofstream Ma("ZenevichLab18.txt", ios::out | ios::trunc);
			if (!Ma)
			{
				cout << "Error file \n";
				break;
			}
			int mas[n];
			for (int i = 0; i < n; i++)
			{
				cout << "Enter element: " << i + 1 << endl;
				cin >> mas[i];
				Ma << mas[i] << " ";
			}
			Ma.close();
			break;
		}
		case 4:
		{
			ifstream Mr("ZenevichLab18.txt", ios::in);
			if (!Mr)
			{
				cout << "Error file \n";
				break;
			}
			int x = 0;
			Mr >> x;
			while (!Mr.eof())
			{
				cout << x << ' ';
				Mr >> x;
			}
			Mr.close();
			cout << "ZenevichLab18.txt read and closed" << endl;
			break;
		}
		case 5:
		{
			cout << "Enter the person's age: ";
			cin >> s.age;
			cout << "Enter the height of the person: ";
			cin >> s.height;
			cout << "Enter the person's last name: ";
			cin.ignore();
			cin.getline(s.fam, 20);
			cout << "Enter the person's name: ";
			cin >> s.name;
			cout << "Sex (1 - the male, 0 - male): ";
			cin >> s.sex;
			cout << "You entered data " << " " << s.age << " " << s.height << " " << s.fam << " " << s.name << endl;
			if (s.sex == 0)
			{
				cout << "Female ";
			}
			else
			{
				cout << "The male ";
			}
			f = true;
			if (f == false)
			{
				cout << "No data to write" << endl;
				break;
			}
			ofstream wtf("ZenevichLab18.txt", ios::out | ios::app);
			if (!wtf)
			{
				cout << "Error" << endl;
				break;
			}
			wtf << s.fam << " " << s.name << " " << s.age << " " << s.height << " " << s.sex << endl;
			wtf.close();
			cout << "The data is written to a text file ZenevichLab18.txt" << endl;
			break;
		}
		case 6:
		{
			ifstream rtf("ZenevichLab18.txt", ios::in);
			if (!rtf)
			{
				cout << "Error" << endl;
				break;
			}
			Worker s1;
			rtf >> s1.fam >> s1.name >> s1.age >> s1.height >> s1.sex;
			while (!rtf.eof())
			{
				cout << s1.fam << "|" << s1.name << "|" << s1.age << "|" << s1.height << "|" << s1.sex << endl;
				rtf >> s1.fam >> s1.name >> s1.age >> s1.height >> s1.sex;
			}
			rtf.close();
			cout << "Data read from text document ZenevichLab18.txt" << endl;
			break;
		}
		case 7:
		{
			cout << "Enter the person's age: ";
			cin >> s.age;
			cout << "Enter the height of the person: ";
			cin >> s.height;
			cout << "Enter the person's last name: ";
			cin.ignore();
			cin.getline(s.fam, 20);
			cout << "Enter the person's name: ";
			cin >> s.name;
			cout << "Sex (1 - the male ): ";
			cin >> s.sex;
			cout << "You entered data " << " " << s.age << " " << s.height << " " << s.fam << " " << s.name << endl;
			if (s.sex == 0)
			{
				cout << "Female ";
			}
			else
			{
				cout << "The male ";
			}
			f = true;
			if (f == false)
			{
				cout << "No data to write" << endl;
				break;
			}
			ofstream wbf("ZenevichStructbin.dat", ios::out | ios::app | ios::binary);
			if (!wbf)
			{
				cout << "Error" << endl;
				break;
			}
			wbf.write((char*)&s, sizeof(s));
			wbf.close();//закрытие потока
			cout << "File in ZenevichStructbin.dat recorded by";
			break;
		}
		case 8:
		{
			Worker s0;
			ifstream rbf("ZenevichStructbin.dat", ios::in | ios::binary);
			if (!rbf)
			{
				cout << "Error";
				break;
			}
			rbf.read((char*)&s0, sizeof(Worker));
			while (!rbf.eof())
			{
				cout << s0.fam << "\t|\t" << s0.name << "\t|\t" << s0.age << "\t|\t" << s0.height << "\t|\t";
				if (s0.sex == 0)
				{
					cout << "Female";
				}
				else
				{
					cout << "The male";
				}
				f = true;
				rbf.close();
				cout << "File ZenevichStructbin.dat read and closed";
				break;
			}
		}
		default:
		{
			cout << "Wrong number!" << endl;
			break;
		}
		}
	}
	system("pause");
	return 0;
}