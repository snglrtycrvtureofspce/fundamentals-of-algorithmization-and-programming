#include <iostream>
#include <Windows.h>
#include "SortMethods.h"

using namespace std;

struct Worker
{
	int age;
    double salary;
	double weight;
	char name[100];
	bool sex;
};

int main()
{
    setlocale(LC_ALL, "");

    int count = 0;
    do
    {
        cout << "How many employees do you have? - ";
        cin >> count;
        if (count < 1)
        {
            cout << "The number of employees must be greater than zero" << endl;
        }
    } while (count < 1);
    Worker* Firm = new Worker[count];
    if (Firm == nullptr)
    {
        cout << "Memory friend, memory .." << endl;
        return 0;
    }
    else
    {
        cout << endl;
    }

    for (int i = 0, workerInfo = 1; i < count; i++)
    {
        cout << "______________________________________________________" << endl;
        cout << "Enter the employee's age: ";
        cin >> Firm[i].age;
        cout << "\nEnter the worker's weight: ";
        cin >> Firm[i].weight;
        cout << "\nEnter the name of the worker: ";
        cin >> Firm[i].name;
        cout << "\nEnter the gender of the employee: (0 - Female 1 - Male): ";
        cin >> Firm[i].sex;
        cout << "\nEnter the employee's salary: ";
        cin >> Firm[i].salary;
        if (count > 1)
        {
            cout << "______________________________________________________" << endl;
            workerInfo++;
            cout << "Description " << workerInfo << " employee:" << endl;
            cout << "______________________________________________________" << endl;
        }
        else
        {
            cout << endl;
        }
    }
    cout << "______________________________________________________" << endl;
    cout << "In your firm " << count << " employees" << "\nTheir description: " << endl;
    cout << "______________________________________________________" << endl;
    for (int i = 0, workerInfo = 1; i < count; i++)
    {
        cout << "Age: " << Firm[i].age << endl;
        cout << "Weight: " << Firm[i].weight << endl;
        cout << "Name: " << Firm[i].name << endl;
        if (Firm[i].sex == false)
        {
            cout << "Gender: Female" << endl;
        }
        else
        {
            cout << "Gender: Male" << endl;
        }
        cout << "Salary: " << Firm[i].salary << endl;
        if (count > 1)
        {
            cout << "______________________________________________________" << endl;
            workerInfo++;
            cout << "Description " << workerInfo << " employee:" << endl;
            cout << "______________________________________________________" << endl;
        }
        else
        {
            cout << endl;
        }
    }

    cout << "Sorting ... " << endl;
    char p = '0';
    cout << "0 - Close program\n1 - Sort for name\n2 - Sort for salary" << endl;
    cin >> p;
    switch (p) {
    case '0':
    {
        cout << "End of the program .." << endl;
        break;
    }
    case '1':
    {
        cout << "Sort for name: " << endl;
        for (int i = 0; i < count; i++)
        {
            Worker nw = Firm[i];
            int q = i;
            for (int j = i - 1; j > -1 && strcmp(nw.name, Firm[j].name) < 0; j--)
            {
                Firm[j + 1] = Firm[j];
                Firm[j] = nw;
            }
        }
        break;
    }
    case '2':
    {
        cout << "Sort for salary:" << endl;
        for (int i = count / 2; i > 0; i = i / 2)
        {
            for (int j = 0; j < count - i; j++)
            {
                for (int k = j; k > -1; k = k - i)
                {
                    if (Firm[k].salary > Firm[i + k].salary)
                    {
                        Worker nw = Firm[k];
                        Firm[k] = Firm[i + k];
                        Firm[i + k] = nw;
                    }
                    else
                    {
                        k = 0;
                    }
                }
            }
        }
        break;
    }
    default: {
        cout << "Wrong number!" << endl;
        break;
    }
    }

    cout << "SOOOOOOOOOOOOOOOOOORTED" << endl;
    cout << "In your firm " << count << " employees" << "\nTheir sorted description: " << endl;
    for (int i = 0; i < count; i++)
    {
        int workerInfo = 1;
        cout << "Age: " << Firm[i].age << endl;
        cout << "Weight: " << Firm[i].weight << endl;
        cout << "Name: " << Firm[i].name << endl;
        if (Firm[i].sex == false)
        {
            cout << "Gender: Female" << endl;
        }
        else
        {
            cout << "Gender: Male" << endl;
        }
        cout << "Salary: " << Firm[i].salary << endl;
        if (count > 1)
        {
            cout << "______________________________________________________" << endl;
            cout << "Description " << workerInfo + 1 << " employee:" << endl;
            cout << "______________________________________________________" << endl;
        }
        else
        {
            cout << endl;
        }
    }

    delete[] Firm;
    Firm = nullptr;

    system("pause");
    return 0;
}