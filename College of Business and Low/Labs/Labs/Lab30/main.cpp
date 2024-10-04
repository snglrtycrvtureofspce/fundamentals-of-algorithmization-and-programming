#include <iostream>

//using namespace std;
using std::cout;
using std::cin;
using std::endl;


struct stack // array limit
{
	int* arr = new int[0]; // stack size, currently empty
	int head = 0; // index the last element of the stack
	static int* change_size_array(int* old_arr, int size, int change_size) // def for change size of arr <type int>
	{
		const auto change_arr = new int[change_size];
		for (int i = 0; i < ((size < change_size) ? size : change_size); i++)
		{
			change_arr[i] = old_arr[i];
		}
		delete[] old_arr;
		return change_arr;
	}
	void push(int x) // add element to stack
	{
		arr = change_size_array(arr, head, head + 1);
		arr[head] = x;
		head++;
	}
	int pop() // delete element from stack
	{
		if(head - 1 != -1) // check stack is empty or no
		{
			int tmp = arr[head - 1];
			arr = change_size_array(arr, head, head - 1);
			head--;
			return tmp;
		}
		else
		{
			cout << "Ошибка, попытка извлечь элемент из пустого стека.\n";
			return -1;
		}
	}
	bool is_empty() // check stack is empty or no
	{
		return head - 1 == -1; // if true = empty
	}
};

void function_stack() // divine def for work with stack
{
	stack my_stack;
	int element_stack;
	int menu = 0;
	bool exit_menu = true;
	while (exit_menu)
	{
		cout << "\n1-Enter add element stack\n2-Enter to extract element from stack\n3-Enter check empty stack?\n0-Enter exit\nEnter number: ";
		cin >> menu;
		switch (menu)
		{
		case 1:
		{
			cout << "Enter element stack: ";
			cin >> element_stack;
			my_stack.push(element_stack);
			break;
		}
		case 2:
		{
			element_stack = my_stack.pop();
			cout << "Element stack: " << element_stack << endl; // if the stack is empty, garbage is returned
			break;
		}
		case 3:
		{
			cout << "Stack is empty: " << ((my_stack.is_empty() == true) ? "true" : "false") << endl;
			break;
		}
		default:
		{
			exit_menu = false;
			break;
		}
		}
	}
}



struct queue // like stack, but opposite
{
	int* arr = new int[NULL];
	int head = 0; // index the first element of the stack
	int tail = 0; // queue length 
	static int* change_size_array(int* old_arr, int size, int change_size) // def for change size of arr <type int>
	{
		const auto change_arr = new int[change_size];
		for (int i = 0; i < ((size < change_size) ? size : change_size); i++)
		{
			change_arr[i] = old_arr[i];
		}
		delete[] old_arr;
		return change_arr;
	}
	void push(int x) // add element to queue
	{
		arr = change_size_array(arr, tail, tail + 1);
		arr[tail];
		tail++;
	}
	int pop() // delete element from queue
	{
		if (head!= tail)
		{
			int tmp = arr[head];
			for (int i = 0; i < tail; i++)
			{
				arr[i] = arr[i + 1];
			}
			arr = change_size_array(arr, tail, tail - 1);
			tail--;
			return tmp;
		}
		else
		{
			cout << "Ошибка, попытка извлечь элемент из пустой очереди.\n";
			return -1;
		}
	}
	bool is_empty() // check queue is empty or no
	{
		return head == tail;
	}
};

void function_queue() // divine def for work with queue
{
	queue my_queue;
	int element_queue;
	int menu = 0;
	bool exit_menu = true;
	while (exit_menu)
	{
		cout << "\n1-Enter add element in queue\n2-Enter to extract element queue\n3-Enter check empty queue?\n0-Enter exit\nEnter number: ";
		cin >> menu;
		switch (menu)
		{
		case 1:
		{
			cout << "Enter element stack: ";
			cin >> element_queue;
			my_queue.push(element_queue);
			break;
		}
		case 2:
		{
			cout << "Element queue: " << element_queue << endl; // if the queue is empty, garbage is returned
			break;
		}
		case 3:
		{
			cout << "Queue is empty: " << ((my_queue.is_empty() == true) ? "true" : "false") << endl;
			break;
		}
		default:
		{
			exit_menu = false;
			break;
		}
		}
	}
}



struct list // doubly linked cyclic (ring) list
{
	int field; // data field
	list* next; // pointer to next element
	list* prev; // pointer to prev element
};

list* init(int number_a) // initialization of the first node
{
	list* new_unit_list = new list[1]; // allocate memory for the root of the list
	new_unit_list->field = number_a;
	new_unit_list->next = new_unit_list; // pointer to next node
	new_unit_list->prev = new_unit_list; // pointer to prev node
	return new_unit_list;
}

list* addelem(list* lst, int number_a) // def to add a node
{
	list* temp, * p;
	temp = new list[1];
	p = lst->next; // save a pointer to the next node
	lst->next = temp; // the previous node points to the one being created 
	temp->field = number_a; // save the data field of the added node
	temp->next = p; // created node points to the next node
	temp->prev = lst; // created node points to the prev node
	p->prev = temp;
	return temp; // return def value is node address added
}
list* deleteelem(list* lst) // def to delete a node
{
	list* prev, * next;
	prev = lst->prev; // node prev per lst
	next = lst->next; // node next per lst
	prev->next = lst->next; // rearrange pointer
	next->prev = lst->prev; // rearrange pointer
	delete lst; // release memory of the removable element
	return prev;
}

void listprint(list* lst) // print elements // argument - pointer to the root of list
{
	list* p;
	p = lst;
	do
	{
		cout << p->field << " "; // print value of the element "p"
		p = p->next; // transition to the next node
	} while (p != lst);
}
void listprintr(list* lst) // reverse print
{
	list* p;
	p = lst;
	do
	{
		p = p->prev; // transition to the prev node
		cout << p->field << " "; // print value of the element "p"
	} while (p != lst);
}



list* swap(list* lst1, list* lst2, list* head) // swap two nodes and return new root of the list
{
	list* prev1, * prev2, * next1, * next2;
	prev1 = lst1->prev; // node prev per lst
	prev2 = lst2->prev; // node prev per lst
	next1 = lst1->next; // node next per lst
	next2 = lst2->next; // node next per lst
	if(lst2 == next1) // swap the neighboring nodes
	{
		lst2->next = lst1;
		lst2->prev = prev1;
		lst1->next = next2;
		lst1->prev = lst2;
		next2->prev = lst1;
		prev1->next = lst2;
	}
	else if(lst1 == next2) // // swap the neighboring nodes
	{
		lst1->next = lst2;
		lst2->prev = prev1;
		lst1->next = next2;
		lst1->prev = lst2;
		next2->prev = lst1;
		prev1->next = lst2;
	}
	else // // swap the (no neighboring) nodes
	{
		prev1->next = lst2;
		lst2->next = next1;
		prev2->next = lst1;
		lst1->next = next2;
		lst2->prev = prev1;
		next2->prev = lst1;
		lst1->prev = prev2;
		next1->prev = lst2;
	}
	if (lst1 == head)
	{
		return lst2;
	}
	if(lst2 == head)
	{
		return lst1;
	}
	return head;
}

void function_list() // // divine def for work with doubly linked cyclic (ring) list
{
	list* my_list, * head, * unit; // list, head of the list, node-list
	int element_list;
	int menu = 0;
	bool exit_menu = true;
	cout << "Enter initialization element list: ";
	cin >> element_list;
	head = init(element_list); // head of the list
	my_list = head; // head of the list = list
	while (exit_menu)
	{
		cout << "\n1-Enter add element to list\n2-Enter print list\n3-Enter swap 2 and 3 element\n4-Enter delete element 3\n0-Enter exit\nEnter number: ";
		cin >> menu;
		switch (menu)
		{
		case 1: // add
		{
			cout << "Enter element list: ";
			cin >> element_list;
			my_list = addelem(my_list, element_list);
			break;
		}
		case 2: // print
		{
			listprint(head);
			break;
		}
		case 3: // swap
		{
			head = swap(head->next, head->next->next, head);
			break;
		}
		case 4: // delete
		{
			deleteelem(head->next->next);
			break;
		}
		default:
		{
			exit_menu = false;
			break;
		}
		}
	}
}

///////////////////////////////////////////////////////////////////////////

struct  Node
{
	int x;
	Node* Next;
};

class List
{
	Node* Head, * Tail; // first element, last element                                          
	int size; // count elements in list                                                    
public:
	List() :Head(NULL), Tail(NULL), size(0) {} // initialize elements to zero with constructor                  
	~List(); // destructor prototype, created below                                                     
	void Add(int x); // def prototype to add elements in list                                           
	void Show(int size); // def prototype to show (print) elements in list                                           
	int Count(); // def prototype to return count of elements in list                                                    
};

List::~List() // destructor
{
	while (size != 0)                        
	{
		Node* temp = Head->Next;
		delete Head;                           
		Head = temp;                           
		size--;                               
	}
}

int List::Count() // def to return count of elements in list
{
	return size;                          
}

void List::Add(int x) // def to add elements in list
{
	size++;                                   
	Node* temp = new Node;                  
	temp->Next = Head;                       
	temp->x = x;                              

	if (Head != NULL)                     
	{
		Tail->Next = temp;                   
		Tail = temp;                        
	}
	else Head = Tail = temp;                
}

void List::Show(int temp) // def to show (print) elements in list
{
	Node* tempHead = Head;                 
	temp = size;                           
	while (temp != 0)                        
	{
		cout << tempHead->x << " ";          
		tempHead = tempHead->Next;          
		temp--;                              
	}
}

int main()
{
	setlocale(LC_ALL, "");
	List lst;
	lst.Add(100);
	lst.Add(200);
	lst.Add(300);
	lst.Show(lst.Count());
	int menu = 0;
	bool exit_menu = true;
	while (exit_menu)
	{
		cout << "\n***** Menu *****\n1-Enter stack\n2-Enter queue\n3-Enter list\n0-Enter exit\nEnter number: ";
		cin >> menu;
		switch (menu)
		{
		case 1:
		{
			system("CLS");
			function_stack();
			break;
		}
		case 2:
		{
			system("CLS");
			function_queue();
			break;
		}
		case 3:
		{
			system("CLS");
			function_list();
			break;
		}
		default:
		{
			system("CLS");
			exit_menu = false;
			break;
		}
		}
	}
	return 0;
}