#include <iostream>

using namespace std;


struct Stack
{
	char info;
	Stack* Next;
};
int prior(char a)
{
	switch (a)
	{
	case '*':
	case '/':
	{
		return 3;
	}
	case '-':
	case '+':
	{
		return 2;
	}
	case '(':
	{
		return 1;
	}
	}
	return 0;
}
Stack* InS(Stack* t, char s)
{
	Stack* t1 = new Stack();
	if (!t1)
	{
		cout << "No memory for new element of stack.\n";
		return NULL;
	}
	t1->info = s;
	t1->Next = t;
	return t1;
}
Stack* OutS(Stack* t, char* s)
{
	Stack* t1 = t;
	*s = t->info;
	t = t->Next;
	delete t1;
	t1 = NULL;
	return t;
}
char* PolishStack(char* In, char* Out, Stack* t, Stack* Op)
{
	char a;
	int i = 0, j = 0;
	while (In[i] != '\0')
	{
		if (In[i] == ')')
		{
			while ((Op->info) != '(')
			{
				Op = OutS(Op, &a);
				if (!Op)
				{
					a = '\0';
				}
				Out[j++] = a;
			}
			t = Op;
			Op = Op->Next;
			delete t;
			t = NULL;
		}
		if (In[i] >= 'a' & In[i] <= 'z')
		{
			Out[j++] = In[i];
		}
		if (In[i] == '(')
		{
			Op = InS(Op, In[i]);
		}
		if (In[i] == '+' | In[i] == '-' | In[i] == '/')
		{
			while (Op != NULL && prior(Op->info) >= prior(In[i]))
			{
				Op = OutS(Op, &a);
				Out[j++] = a;
			}
			Op = InS(Op, In[i]);
		}
		i++;
	}
	while (Op != NULL)
	{
		Op = OutS(Op, &a);
		Out[j++] = a;
	}
	Out[j] = '\0';
	return Out;
}

////
struct node {
	int val;
	node* next;
	node(int v, node* st) :val(v), next(st) {}
};

void  stack_push(node*& st, int val);
void  stack_pop(node*& st);
node* stack_min(node* st);


int main()
{
	int p = 0;
	cout << "Enter number: "; cin >> p;
	switch (p)
	{
	case 1:
	{
		const int n = 50;
		Stack* T = NULL, * Op = NULL;
		char In[n];
		char* Out = new char[n];
		if (!Out)
		{	
			cout << "No memory for string of " << n << " characters.\n";
			return 0;
		}
		cout << "Enter an arithmetic expression (possible with brackets (), spaces and multi-character variables (it is better to start with a capital letter)): ";
		cin.getline(In, n);
		cout << "You entered: " << In << endl;
		Out = PolishStack(In, Out, T, Op);
		cout << "Reverse Polish Notation (RPN): " << Out << endl;
		break;
	}
	case 2:
		{
		srand(static_cast<unsigned int>(time(NULL)));

		node* st = NULL;
		for (int i = 0; i < 10; ++i)
			stack_push(st, rand() % 10);

		//вывести изначальный исходный стек
		for (const node* j = st; j != NULL; j = j->next)
			std::cout << j->val << ' ';
		std::cout << std::endl;

		//Перенести в другой стек все элементы...
		node* p = stack_min(st);
		node* st1 = NULL;
		if (p != st) {
			st1 = st;
			st = p->next;
			p->next = NULL;
		}

		//вывести полученный стек
		while (st1 != NULL) {
			std::cout << st1->val << ' ';
			stack_pop(st1);
		}
		std::cout << std::endl;

		//вывести оставшиеся элементы в исходном стеке
		while (st != NULL) {
			std::cout << st->val << ' ';
			stack_pop(st);
		}
		std::cin.get();
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

//добавить
void stack_push(node*& st, int val) {
	st = new node(val, st);
}

//вытолкнуть
void stack_pop(node*& st) {
	node* t;
	if (st != NULL) {
		t = st;
		st = st->next;
		delete t;
	}
}

//мин. элемент
node* stack_min(node* st) {
	node* p = st;
	for (; st != NULL; st = st->next) {
		if (st->val < p->val)
			p = st;
	}
	return p;
}