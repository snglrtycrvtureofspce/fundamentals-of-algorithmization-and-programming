#include <iostream>
#include <vector>
#include <string>
#include <list>

#define in_range(x,y,z) for (int x = y; x < z; x++)

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;
using std::list;

int division_method_hash_function(const int k) // fun hash method division
{
	return k % 10;
}

int multiplication_method_hash_function(const int k) // fun hash method multiplication
{
	/*
	the value of the variable will be calculated at compile time
	*/
	constexpr int n = 13;
	constexpr double a = 0.618033;
	return n * fmod(k * a, 1);
}

////////////////////////////////////////////////////////////////////////////

int find_substr(string t, string s) // fun search for a substring in a string
{
	const int p = 97;
	vector<int> p_pow(s.length()); // creation of an integer array p_pow by the constructor for the number of elements s.length() - how many elements are in the string s
	p_pow[0] = 1;
	/*
	The post-increment(i++) operation returns the value of the variable i before the increment is executed.
	The prefix increment operator (++i) returns the value of an already modified variable. 
	*/
	for (size_t i = 1; i < p_pow.size(); ++i)
	{
		p_pow[i] = p_pow[i - 1] * p; // calculate the hashes of all prefixes of the string s
	}
	vector<int> h(s.length()); // creation of an integer array h by the constructor for the number of elements s.length() - how many elements are in the string s
	for(size_t i = 0; i < s.length(); ++i)
	{
		h[i] = (s[i] - 't' + 1) * p_pow[i];
		if (i) // i != 0
		{
			h[i] += h[i - 1];
		}
	}
	/*
	count the hash of the string t
	*/
	int h_t = 0;
	for(size_t i = 0; i < t.length(); ++i)
	{
		h_t += (t[i] - 't' + 1) * p_pow[i];
	}
	/*
	compare hashes of string t and substrings s length |t|
	*/
	for(size_t i = 0; i < t.length(); ++i)
	{
		int cur_h = h[i + t.length() - 1];
		if(i)
		{
			cur_h -= h[i - 1];
		}
		/*
		if equality is satisfied at least once, stop searching
		*/
		if(cur_h == h_t * p_pow[i])
		{
			return int(i);
		}
	}
	return -1;
}

//////////////////////////////////////////////////

/*
a hash function that finds the hash code for a string, given the string,
the length of the hash code (the number of characters in the hash code),
the key of the hash code).
hash algorithm: (a0 + p * a1 + p^2 * a3 + ... + p^(n-1)a[n-1]) % pow(2, n)
*/
unsigned int find_hash_code_for_string(string str, int key_hash, int count_of_symbols_code)
{
	unsigned int size = pow(10, count_of_symbols_code); // size = hash size (size length), range int: -2 147 483 648; +2 147 483 647
	unsigned long long int hash_code = 0, tmp_hash = 0;
	for (size_t i = 0; i < str.length(); i++)
	{
		tmp_hash += (int)pow(key_hash, i) * (int)(str[i]);
		tmp_hash = tmp_hash % size;
	}
	hash_code = tmp_hash % size;
	return hash_code;
}

//////////////////////////////////////////////////

/*
working with a container - a dynamic list list< >.
*/
struct participant
{
	int x;
	participant(){}
	participant(int x)
	{
		this->x = x;
	}
	void show()
	{
		cout << this->x << " ";
	}
};

//////////////
struct Sportsman
{
	string country;
	string team;
	string name;
	int number; 
	int age;
	int heigth;
	int weigth;
	void print()
	{
		std::cout << "Country: " + this->country + "\nTeam: " + this->team + "\nName: " + this->name + "\nNumber: " << this->number << "\nAge: " << this->age << "\nHeigth: " << this->heigth << "\nWeigth: " << this->weigth << "\nBMI:" << (this->weigth / (double)(this->heigth * this->heigth)) << "\n";
	}
};
struct Hash {
	void* data;
	int length; 
	int hash;
	Hash* point = nullptr;
};
void allp(Hash* h) {
	((Sportsman*)(h->data))->print();
	if (h->point != nullptr) {
		allp(h->point);
	}
	return;
}
void alld(Hash* h) {
	delete h->data;
	if (h->point != nullptr) {
		allp(h->point);
		delete h->point;
	}
	return;
}
static const uint8_t K[64] = {
	0x98, 0x91, 0xcf, 0xa5, 0x5b, 0xf1, 0xa4, 0xd5,
	0x98, 0x01, 0xbe, 0xc3, 0x74, 0xfe, 0xa7, 0x74,
	0xc1, 0x86, 0xc6, 0xcc, 0x6f, 0xaa, 0xdc, 0xda,
	0x52, 0x6d, 0xc8, 0xc7, 0xf3, 0x47, 0x51, 0x67,
	0x85, 0x38, 0xfc, 0x13, 0x54, 0xbb, 0x2e, 0x85,
	0xa1, 0x4b, 0x70, 0xa3, 0x19, 0x24, 0x85, 0x70,
	0x16, 0x08, 0x4c, 0xb5, 0xb3, 0x4a, 0x4f, 0xf3,
	0xee, 0x6f, 0x14, 0x08, 0xfa, 0xeb, 0xf7, 0xf2
};

void vhashf1(Hash* hash, uint64_t key) {
	uint8_t* buf;
	uint32_t l = 0;
	{
		uint32_t m = hash->length;
		m += 64 - (m % 64);
		l = m / 64;
		buf = new uint8_t[m];
		memcpy(buf, hash->data, hash->length);
		for (int i = hash->length + 1; i < m; i++) {
			buf[i] = K[i % 64];
		}
		//  *(uint64_t*)(buf + m/8+1) = hash->length;
	}
	uint64_t h = (uint32_t)K[key % 64] + key;
	for (int i = 0; i < l; i++) {
		uint64_t a = h + 1;
		for (int j = 0; j < 64; j++) {
			a += (((uint64_t)buf[i * 64 + j] + 0x01) * (uint64_t)K[j]) * a;
		}
		h += a;
	}
	hash->hash = h;
	return;
}
////////////////
void main()
{
	int select = 0;
	cout << "Select function (only 6): "; cin >> select;
	switch (select)
	{
	case 1:
	{
		int key = 0;
		for (int i = 0; i < 10; i++)
		{
			cout << "Enter key: "; cin >> key;
			cout << "hash_function(" << key << ") = " << division_method_hash_function(key) << endl;
		}
		break;
	}
	case 2:
	{
		int key = 0;
		for (int i = 0; i < 10; i++)
		{
			cout << "Enter key: "; cin >> key;
			cout << "hash_function(" << key << ") = " << multiplication_method_hash_function(key) << endl;
		}
		break;
	}
	case 3:
	{
		vector<string>T, S, C;
		int n = 0;
		cout << "Enter count: "; cin >> n;
		string tmp;
		for (int i = 0; i < n; i++)
		{
			cout << "Enter " << i + 1 << " string: "; cin >> tmp;
			/*
			The push_back() fun is one way to insert a new element at the end of a vector,
			which increases the size of the vector by 1.
			This function is useful when one element needs to be added to the vector.
			*/
			if (tmp.length() == 1)
			{
				C.push_back(tmp); // puts any string into an array of strings t 
			}
			T.push_back(tmp);
		}
		cout << "\nEnter -1 to exit: ";
		/*
		The compare() fun is Comparing Parts of Strings
		*/
		while (cin >> tmp && tmp.compare("-1") != 0)
		{
			S.push_back(tmp); // we enter the desired substrings (words) into the array s until you enter -1 
		}
		for (int i = 0; i < S.size(); i++) // we pass through the array s from the desired strings (words) 
		{
			string s = S[i];
			if (s == "")
			{
				continue;
			}
			if (s.length() == 1)
			{
				in_range(j, 0, C.size())
				{
					string c = C[j];
					if (s == c)
					{
						cout << s << "\n";
						break;
					}
					continue;
				}
			}
			for (int j = 0; j < n; j++) // Rabin Karp algorithm
			{
				string t = T[j];
				int pos = find_substr(t, s); ////////// s
				if (pos >= 0)
				{
					cout << s << "\n";
					break;
				}
			}
		}
		break;
	}
	case 4:
	{
		int hash_key = 11;
		int count_of_symbols_code = 9;
		string str1 = "wqweqwrqwr"; // differences on the last symbol
		string str2 = "wqweqwrqwy"; // differences on the last symbol
		cout << "String: " << str1 << " hash code to this strings: " << find_hash_code_for_string(str1, hash_key, count_of_symbols_code) << endl;
		cout << "String: " << str2 << " hash code to this strings: " << find_hash_code_for_string(str2, hash_key, count_of_symbols_code) << endl;
		break;
	}
	case 5:
	{
		list<participant>li;
		participant c(0);
		li.push_back(c); // push_back() - placing the element at the end of the list
		participant c0(1);
		li.push_back(c0);
		participant c1(2);
		li.push_back(c1);
		participant c2(3);
		li.push_front(c2);
		participant c3(4);
		li.push_front(c3); // push_front() - placing the element at the beginning of the list
		participant c4(5);
		li.push_front(c4);
		/*
		An iterator is an object that is capable of iterating over the elements of a container class without the user having to know the implementation of a particular container class.
		In many containers (especially list and associative containers),
		iterators are the primary way to access the elements of these containers.
		*/
		list<participant>::iterator j; // iterator j to save a pointer to an element of the car list
		for (list<participant>::iterator i = li.begin(); i != li.end(); i++)
		{
			i->show();
			if (i->x == 3)
			{
				j = i;
			}
		}
		cout << endl;
		li.pop_back(); // pop_back() - remove the last element of the list
		li.pop_front(); // pop_front() - remove the first element of the list
		li.erase(j); // remove element on pointer
		for (list<participant>::iterator i = li.begin(); i != li.end(); i++)
		{
			(*i).show();
		}
		cout << endl;
		li.clear(); // clear all list
		break;
	}
	case 6:
	{
		list<Hash*> hashList;
		int key;
		cout << "\nEnter key:\n";
		cin >> key;
		cout << "[1] Add Structure\n[2] List structure hashes\n[3] Display all stored structures by hash\n[4] Delete all stored structures by hash\n[0] End the program\n";
		int k = 5;
		while (k != 0) {
			cout << "\tEnter:\n";
			cin >> k;
			switch (k) {
			case 1: {
				Hash* h = new Hash;
				Sportsman* s = new Sportsman;
				cout << "Country: ";
				cin >> s->country;
				cout << "Team: ";
				cin >> s->team;
				cout << "Name: ";
				cin >> s->name;
				cout << "Number: ";
				cin >> s->number;
				cout << "Age: ";
				cin >> s->age;
				cout << "Heigth: ";
				cin >> s->heigth;
				cout << "Weigth: ";
				cin >> s->weigth;
				h->data = s;
				h->length = sizeof(Sportsman);
				vhashf1(h, key);
				cout << "- generated hash: " << h->hash << "\n";
				bool f = false;
				for (auto i = hashList.begin(); i != hashList.end(); i++) {
					if ((*i)->hash == h->hash) {
						(*i)->point = h;
						f = true;
						break;
					}
				}
				if (!f) {
					hashList.push_back(h);
				}
				break;
			}
			case 2: {
				std::cout << "Hash list:\n";
				if (hashList.begin() == hashList.end()) {
					cout << "\tthe list is empty\n";
					break;
				}
				for (auto i = hashList.begin(); i != hashList.end(); i++) {
					cout << "\t" << (*i)->hash << "\n";
				}
				break;
			}
			case 3: {
				std::cout << "\tenter the hash:\n";
				int h;
				std::cin >> h;
				bool f = false;
				for (auto i = hashList.begin(); i != hashList.end(); i++) {
					if ((*i)->hash == h) {
						allp(*i);
						f = true;
						break;
					}
				}
				if (!f) {
					cout << "hash not found\n";
				}
				break;
			}
			case 4: {
				cout << "\nenter the hash\n";
				int h;
				std::cin >> h;
				bool f = false;
				for (auto i = hashList.begin(); i != hashList.end(); i++) {
					if ((*i)->hash == h) {
						alld(*i);
						delete (*i);
						hashList.erase(i);
						f = true;
						cout << "hash not found\n";
						break;
					}
				}
				if (!f) {
					cout << "hash not found\n";
				}
				break;
			}
			default:
				break;
			}
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
}