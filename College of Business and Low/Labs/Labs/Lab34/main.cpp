#include <iostream>

using namespace std;


/*
In combinatorics, an ordered selection of M elements from a proposed set of N different elements is called a placement of N elements by M.
All combinations within the placement can differ from each other both in the elements themselves and in the order of their arrangement.
There are also placements without repetitions (when all M elements within the sample are different) and placements with repetitions.
*/

/*
without_repetition
*/
void swap_without_repetition(int* a, int i, int j)
{
	int s = a[i];
	a[i] = a[j];
	a[j] = s;
}
bool next_set_without_repetition(int* a, int n, int m)
{
	int j = 0;
	do // repeat until the next placement is found
	{
		j = n - 1;
		while (j != -1 && a[j] >= a[j + 1])
		{
			j--;
		}
		if (j == -1)
		{
			return false; // no more accommodations
		}
		int k = n - 1;
		while (a[j] >= a[k])
		{
			k--;
		}
		swap_without_repetition(a, j, k);
		int l = j + 1, r = n - 1; // sort the rest of the sequence
		while (l < r)
		{
			swap_without_repetition(a, l++, r--);
		}
	} while (j > m - 1);
	return true;
}
void print_without_repetition(int* a, int n) // placement withdrawal
{
	static int num = 1; // accommodation number
	cout.width(3); // width of the placement number input field
	cout << num++ << " ";
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
}

/*
with repetition
*/
bool next_set_with_repetition(int* a, int n, int m)
{
	int j = m - 1;
	while (j >= 0 && a[j] == n)
	{
		j--;
	}
	if(j < 0)
	{
		return false;
	}
	if (a[j] >= n)
	{
		j--;
	}
	a[j]++;
	if (j == m - 1)
	{
		return true;
	}
	for (int k = j + 1; k < m; k++)
	{
		a[k] = 1;
	}
	return true;
}
void print_with_repetition(int* a, int n)
{
	static int num = 1;
	cout.width(3);
	cout << num++ << ": ";
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
}



/*
In combinatorics, a conjunction of N different elements over M is a set of M elements selected from a set of N elements.
Such sets differ only in the occurrence of certain M elements in them, the order of the elements in such a set is not important.
Sets that differ only in the order of the elements (but not in composition) are considered the same, and this is how conjunction differ from placements.
*/

/*
Ñonjunction without repetition
*/
bool next_set_conjunction_without_repetition(int* a, int n, int m)
{
	int k = m;
	for (int i = k - 1; i >= 0; --i)
	{
		if (a[i] < n - k + i + 1)
		{
			++a[i];
			for (int j = i + 1; j < k; ++j)
			{
				a[j] == a[j - 1] + 1;
			}
			return true;
		}
	}
	return false;
}
void print_conjunction_without_repetition(int* a, int n)
{
	static int num = 1;
	cout.width(3);
	cout << num++ << ": ";
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
}

/*
Ñonjunction with repetition
*/
bool next_set_conjunction_with_repetition(int* a, int n, int m)
{
	int j = m - 1;
	while (a[j] == n && j >= 0)
	{
		j--;
	}
	if (j < 0)
	{
		return false;
	}
	if (a[j] >= n)
	{
		j--;
	}
	a[j]++;
	if (j == m - 1)
	{
		return true;
	}
	for (int k = j + 1; k < m; k++)
	{
		a[k] = a[j];
	}
	return true;
}
void print_conjunction_with_repetition(int* a, int n)
{
	static int num = 1;
	cout.width(3);
	cout << num++ << ": ";
	for (int i = 0; i < n; i++) 
	{
		cout << a[i] << " ";
	}
	cout << endl;
}



int main()
{
	int p = 0;
	cout << "Enter number: "; cin >> p;
	switch (p)
	{
	case 1: // placement without repetition
	{
		int n, m, * a;
		do
		{
			cout << "N = ";
			cin >> n;
			cout << "N = ";
			cin >> m;
		} while (n < m); // placement without repetition
		a = new int[n];
		if (!a)
		{
			cout << "No memory.\n";
			return 0;
		}
		for (int i = 0; i < n; i++)
		{
			a[i] = i + 1; // fill with numbers in ascending order (lexicographic order) without repetitions
		}
		print_without_repetition(a, m);
		while (next_set_without_repetition(a, n, m))
		{
			print_without_repetition(a, m);
		}
		delete[] a;
		break;
	}
	case 2:// placement with repetition
	{
		int n, m, * a;
		cout << "N = "; cin >> n;
		cout << "M = "; cin >> m;
		int h = n > m ? n : m;
		a = new int[h];
		if (!a)
		{
			cout << "No memory.\n";
			return 0;
		}
		for (int i = 0; i < h; i++)
		{
			a[i] = 1;
		}
		print_with_repetition(a, m);
		while (next_set_with_repetition(a, n, m))
		{
			print_with_repetition(a, m);
		}
		delete[] a;
		break;
	}
	case 3: // conjunction without repetition
	{
		int n, m, * a;
		cout << "N = "; cin >> n;
		cout << "M = "; cin >> m;
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
		print_conjunction_without_repetition(a, m);
		if (n >= m)
		{
			while (next_set_conjunction_without_repetition(a, n, m))
			{
				print_conjunction_without_repetition(a, m);
			}
		}
		delete[] a;
		break;
	}
	case 4: // conjunction with repetition
	{
		int n, m, * a;
		cout << "N = "; cin >> n;
		cout << "M = "; cin >> m;
		int h = n > m ? n : m;
		a = new int[h];
		if (!a)
		{
			cout << "No memory.\n";
			return 0;
		}
		for (int i = 0; i < h; i++)
		{
			a[i] = 1;
		}
		print_conjunction_with_repetition(a, m);
		while (next_set_conjunction_with_repetition(a, n, m))
		{
			print_conjunction_with_repetition(a, m);
		}
		delete[] a;
		break;
	}
	case 5: // task
	{
		int n, m, * a;
		cout << "N = "; cin >> n;
		cout << "M = "; cin >> m;
		int h = n > m ? n : m;
		a = new int[h];
		if (!a)
		{
			cout << "No memory.\n";
			return 0;
		}
		cout << "Select an array location option: "; cin >> p;
		switch (p)
		{
		case 1:
		{
			for (int i = 0; i < n; i++)
			{
				a[i] = i + 1; // fill with numbers in ascending order (lexicographic order) without repetitions
			}
			print_without_repetition(a, m);
			while (next_set_without_repetition(a, n, m))
			{
				print_without_repetition(a, m);
			}
			break;
		}
		case 2:
		{
			for (int i = 0; i < h; i++)
			{
				a[i] = 1;
			}
			print_with_repetition(a, m);
			while (next_set_with_repetition(a, n, m))
			{
				print_with_repetition(a, m);
			}
			break;
		}
		case 3:
		{
			for (int i = 0; i < n; i++)
			{
				a[i] = i + 1;
			}
			print_conjunction_without_repetition(a, m);
			if (n >= m)
			{
				while (next_set_conjunction_without_repetition(a, n, m))
				{
					print_conjunction_without_repetition(a, m);
				}
			}
			break;
		}
		case 4:
		{
			for (int i = 0; i < h; i++)
			{
				a[i] = 1;
			}
			print_conjunction_with_repetition(a, m);
			while (next_set_conjunction_with_repetition(a, n, m))
			{
				print_conjunction_with_repetition(a, m);
			}
			break;
		}
		default:
		{
			system("CLS");
			cout << "Some kind of mistake" << endl;
			break;
		}
		}
		delete[] a;
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