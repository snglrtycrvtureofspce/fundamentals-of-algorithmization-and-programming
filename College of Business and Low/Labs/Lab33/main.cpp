#include <iostream>

using namespace std;


/*
A permutation is a combination of elements from N different elements, taken in a certain order.
In a permutation, the order of the elements is important, and all N elements must be involved in the permutation.
Types of permutations: without repetitions / with repetitions
*/


/*
repeating/non-repeating sorted numbers
*/
void swap_number(int* a, int i, int j) // function to exchange two array values
{
	int s = a[i];
	a[i] = a[j];
	a[j] = s;
}

bool next_set_number(int* a, int n) // function to generate a new data set (new permutation) in lexicographic order
{
	int j = n - 2;
	while (j != -1 &&  a[j] >= a[j + 1])
	{
		j--;
	}
	if(j == -1) // no more changes
	{
		return false;
	}
	int k = n - 1;
	while (a[j] >= a[k])
	{
		k--;
	}
	swap_number(a, j, k); // swap two array elements 
	int l = j + 1, r = n - 1; // sort the rest of the sequence 
	while (l < r)
	{
		swap_number(a, l++, r--); // swap two array elements 
	}
	return true;
}

void print_number(int* a, int n) // function to print an array after the next permutation to the console
{
	/*
	Static is a keyword in C++ used to give an element a special characteristic.
	For static members, memory allocation occurs only once and these members exist until the end of the program.
	All these elements are stored not in heap and not on stack, but in special memory segments called .data and .bss (depending on whether static data is initialized or not).
	The picture below shows a typical program memory layout.
	*/
	static int num = 1;
	cout.width(3); // width of the permutation number input field
	cout << num++ << ": ";
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
}

/*
the number of unique permutations in a word or phrase
*/
void swap_word(char* a, int i, int j)
{
	char s = a[i];
	a[i] = a[j];
	a[j] = s;
}

bool next_set_word(char* a, int n) // function to generate a new data set (new permutation) 
{
	int j = n - 2;
	while (j != -1 && a[j] >= a[j + 1])
	{
		j--;
	}
	if (j == -1) // // no more changes
	{
		return false;
	}
	int k = n - 1;
	while (a[j] >= a[k])
	{
		k--;
	}
	swap_word(a, j, k);
	int l = j + 1, r = n - 1; // sort the rest of the sequence 
	while (l < r)
	{
		swap_word(a, l++, r--);
	}
	return true;
}

void print_word(char* a, int n)
{
	static int num = 1;
	cout.width(3);
	cout << num++ << ": ";
	for (int i = 0; i < n; i++)
	{
		cout << a[i];
	}
	cout << endl;
}

void sort_word(char* a, int n) // character string sort function
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n - 1 - i; j++)
		{
			if (a[j] > a[j + 1])
			{
				swap_word(a, j, j + 1);
			}
		}
	}
}



int main()
{
	int p = 0;
	cout << "Enter nubmer: "; cin >> p;
	switch (p)
	{
	case 1:
	{
		int n = 0, * a = nullptr;
		do
		{
			cout << "Enter N: ";
			cin >> n;
		} while (n < 1);
		a = new int[n];
		if (!a)
		{
			cout << "No memory.\n";
			return 0;
		}
		for (int i = 0; i < n; i++)
		{
			a[i] = i + 1;
		}
		// non-repeating sorted numbers
		// a[1] = 1; // (sorted repeating numbers) a repeating element, that is, two units in a row will be stored in the array 
		print_number(a, n);
		int count = 0; // permutation counter 
		while (next_set_number(a, n))
		{
			print_number(a, n);
			count++;
		}
		cout << "Number of permutations:" << count << endl;
		break;
	}
	case 2:
	{
		int n = 50;
		char* a = new char[n]; // string for [49 symbols + /0]
		if (!a)
		{
			cout << "No memory.\n";
			return 0;
		}
		cout << "Enter strings: ";
		cin.ignore();
		cin.getline(a, n);
		print_word(a, strlen(a)); // print the initial set 
		sort_word(a, strlen(a));
		int count = 0; // permutation counter
		while (next_set_word(a, strlen(a)))
		{
			count++;
			print_word(a, strlen(a));
		}
		cout << "Counter of unique set (permutations): " << count + 1 << endl;
		break;
	}
	default:
	{
		system("CLS");
		cout << "Some kind of mistake" << endl;
		break;
	}
	}
	return 0;
}