#include <iostream>
#include <Windows.h>

using namespace std;


int sch = 0; // count struct in arr
char choice = 0;

struct lombard
{
    char tovar[20];
    int cena;
    int kolichestvo;
    bool empty;

}l_arr[20];

void poisk_po_tovary()
{
    if (!sch)
    {
        cout << "Enter something first!" << endl;
    }
    else {
        cout << "Enter a product" << endl;
        char w[20];
        cin >> w;
        bool flag = 1;
        for (int i = 0; i < sch; i++)
        {
            if (strcmp(w, l_arr[i].tovar) == 0)
            {
                cout << "Product " << l_arr[i].tovar << endl;
                cout << "Price  " << l_arr[i].cena << endl;
                cout << "Pledge  " << l_arr[i].kolichestvo << endl;
                flag = 0;
            }
            if (flag)
                cout << "The search has not given any results" << endl;
        }
    }
}

void poisk_po_chene()
{
    if (!sch)
    {
        cout << "Enter something first!" << endl;
    }
    else {
        cout << "Enter price" << endl;
        int w;
        cin >> w;
        bool flag = 1;
        for (int i = 0; i < sch; i++)
        {
            if (l_arr[i].cena == w)
            {

                cout << "Product " << l_arr[i].tovar << endl;
                cout << "Price " << l_arr[i].cena << endl;
                cout << "Pledge " << l_arr[i].kolichestvo << endl;
                flag = 0;
            }
            if (flag)
                cout << "The search has not given any results" << endl;
        }
    }
}

void del()
{
    cout << "\nEnter the number of the entry to be deleted" << endl;
    int k;
    cin >> k;
    for (int i = k - 1; i < sch; i++)
    {
        l_arr[i] = l_arr[i + 1];
    }
    sch--;
}

void change()
{
    int c = 0, per = 0;
    cout << "\nEnter entry number" << endl;
    cin >> c;
    do
    {
        cout << "1-to change the item" << endl;
        cout << "2-to change the price" << endl;
        cout << "3-to change the count" << endl;
        cout << "4-to exit edit mode " << endl;
        cout << "Enter: ";
        cin >> per;
        switch (per)
        {
        case 1: cout << "Product " << endl;
            cin >> l_arr[c - 1].tovar;
            break;
        case 2: cout << "Price ";
            cin >> l_arr[c - 1].cena;
            break;
        case 3: cout << "Count ";
            cin >> l_arr[c - 1].kolichestvo;
            break;
            cin >> per;
        }
    } while (per != 4);
}

void dobavl()
{
    if (sch < 20)
    {
        cout << "Record number " << sch + 1 << endl;;
        cout << "Product" << endl;
        cin >> l_arr[sch].tovar;
        cout << "Price" << endl; // добавить проверки
        cin >> l_arr[sch].cena;
        cout << "Count " << endl;
        cin >> l_arr[sch].kolichestvo;
        sch++;
    }
    else {
        cout << "Entered maximum number of records ";
    }
}

void out()
{
    int sw;  // switch
    int o;   // number of structures to be output
    cout << "1-if you want to display any record" << endl;
    cout << "2-if you want to display all records" << endl;
    cout << "Enter: ";
    cin >> sw;
    if (sw == 1)
    {
        cout << "Enter the number of the entry you want to display" << endl;
        cout << "Enter: ";
        cin >> o;
        o--;
        cout << "Product " << l_arr[o].tovar << endl;
        cout << "Price " << l_arr[o].cena << endl;
        cout << "Count " << l_arr[o].kolichestvo << endl;
    }
    if (sw == 2)
    {
        for (int i = 0; i < sch; i++)
        {
            cout << "Product " << l_arr[i].tovar << endl;
            cout << "Price " << l_arr[i].cena << endl;
            cout << "Count " << l_arr[i].kolichestvo << endl;
        }
    }
    cout << endl;
}

int main() {
    setlocale(LC_ALL, "");
    char p;
    cout << "Enter the number: ";
    cin >> p;
    switch (p)
    {
    case '1':
    {
        cout << "No entries yet" << endl;
        do
        {
            cout << "\t\t\t\t\tWarehouse" << endl;
            cout << "_______________________________________________________________________________________" << endl;
            cout << "1 - Entering a new entry " << '\t';
            cout << "2 - Output record(s) " << '\t';
            cout << "3 - Changing an entry " << endl;
            cout << "4 - Deleting an entry " << '\t';
            cout << "5 - Search by product " << '\t';
            cout << "6 - Search by price " << endl;
            cout << "\t\t\t7 - Exiting the program" << endl;
            cout << "Enter: ";
            cin >> choice;
            switch (choice)
            {
            case '1':
            {
                dobavl();
                break;
            }
            case '2':
            {
                out();
                break;
            }
            case '3':
            {
                change();
                break;
            }
            case '4':
            {
                del();
                break;
            }
            case '5':
            {
                poisk_po_tovary();
                break;
            }
            case '6':
            {
                poisk_po_chene();
                break;
            }
            case '7':
            {
                cout << "End of the program..." << endl;
                system("pause");
                return 0;
            }
            default:
            {
                cout << "Wrong number!" << endl;
                cout << "Enter the value again." << endl;
            }
            }
        } while (choice != '7');
        break;
    }
    default:
    {
        cout << "Wrong number" << endl;
        break;
    }
    }
    system("pause");
    return 0;
}