#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;


struct DataField // struct for for data storage
{
	string name = "";
	int unit_price = 0;
	size_t number_of_units = 0; // unsigned integer type
	void input(); // def prototype
	void show(); // def prototype
	void set_random(); // def prototype
};
struct BinarTree
{
	DataField data_field;
	BinarTree* left = nullptr;
	BinarTree* right = nullptr;
};

void DataField::input()
{
	cout << "Enter name of product : ";
	cin >> name;
	cout << "Enter number of units: ";
	cin >> number_of_units;
	cout << "Enter unit price: ";
	cin >> unit_price;
};
void DataField::show()
{
	cout << "Name of product: " << name << "\t Number of units: " << number_of_units << "\t Unit price: " << unit_price << endl;
}

void DataField::set_random()
{
	unit_price = rand() % 100;
	name = 'A' + rand() % ('Z' - 'A' + 1);
	for (int i = 0; i < 5; i++)
	{
		name = 'a' + rand() % ('z' - 'a' + 1);
	}
	number_of_units = 100 + rand() % 201;
}
void treeprint(BinarTree* tree);
void treeprint_byname(string name, BinarTree* tree);
BinarTree* add_node(DataField x, BinarTree* tree);
void delete_tree(BinarTree* tree);
void delete_branches(BinarTree* tree);
BinarTree* find_the_knot_tree(string name_delete, BinarTree* tree);
BinarTree* copy_tree(BinarTree* tree, BinarTree* find_element_copy);
BinarTree* subfunction_delete_element_tree(string name_delete, BinarTree* new_tree, BinarTree* old_tree);
BinarTree* delete_element_tree(string name_delete, BinarTree* tree);
BinarTree* find_parent_tree(BinarTree* element_tree, BinarTree* tree);
BinarTree* delete_element_tree2(string name_delete, BinarTree* tree);
void treeprint(BinarTree* tree)
{
	if(tree!= nullptr)
	{
		treeprint(tree->left);
		treeprint(tree->right);
		tree->data_field.show();
	}
}
void treeprint_byname(string name, BinarTree* tree)
{
	if (tree != nullptr && tree->data_field.name == name)
	{
		treeprint_byname(name, tree->left);
		treeprint_byname(name, tree->right);
		tree->data_field.show();
	}
}
BinarTree* add_node(DataField x, BinarTree* tree)
{
	if(tree == nullptr)
	{
		tree = new BinarTree();
		tree->data_field = x;
		tree->left = nullptr;
		tree->right = nullptr;
	}
	else
	{
		if(x.name < (tree->data_field).name)
		{
			tree->left = add_node(x, tree->left);
		}
		else
		{
			tree->right = add_node(x, tree->right);
		}
	}
	return tree;
}
void delete_tree(BinarTree* tree)
{
	if(tree != nullptr)
	{
		delete_tree(tree->left);
		delete_tree(tree->right);
		delete tree;
	}
}
void delete_branches(BinarTree* tree)
{
	delete_tree(tree->left);
	delete_tree(tree->right);
	tree->left = nullptr;
	tree->right = nullptr;
}
BinarTree* find_the_knot_tree(string name_delete, BinarTree* tree)
{
	if(tree != nullptr)
	{
		if(tree->data_field.name == name_delete)
		{
			return tree;
		}
		else
		{
			if(name_delete < (tree->data_field).name)
			{
				return find_the_knot_tree(name_delete, tree->left);
			}
			else
			{
				return find_the_knot_tree(name_delete, tree->right);
			}
		}
	}
	return nullptr;
}
BinarTree* copy_tree(BinarTree* tree, BinarTree* find_element_copy)
{
	if(find_element_copy != nullptr)
	{
		tree = add_node(find_element_copy->data_field, tree);
		tree = copy_tree(tree, find_element_copy->left);
		tree = copy_tree(tree, find_element_copy->right);
	}
	return tree;
}
BinarTree* subfunction_delete_element_tree(string name_delete, BinarTree* new_tree, BinarTree* old_tree)
{
	if(old_tree != nullptr)
	{
		if(old_tree->data_field.name != name_delete)
		{
			new_tree = subfunction_delete_element_tree(name_delete, new_tree, old_tree->left);
			new_tree = subfunction_delete_element_tree(name_delete, new_tree, old_tree->right);
		}
	}
	return new_tree;
}
BinarTree* delete_element_tree(string name_delete, BinarTree* tree)
{
	BinarTree* tmp_tree = nullptr;
	tree = subfunction_delete_element_tree(name_delete, tmp_tree, tree);
	delete_tree(tmp_tree);
	return tree;
}
BinarTree* find_parent_tree(BinarTree* element_tree, BinarTree* tree)
{
	if(tree != nullptr && tree != element_tree)
	{
		if(tree->left == element_tree || tree->right == element_tree)
		{
			return tree;
		}
		else
		{
			if((element_tree->data_field).name < (tree->data_field).name)
			{
				return find_parent_tree(element_tree, tree->left);
			}
			else
			{
				return find_parent_tree(element_tree, tree->right);
			}
		}
	}
	return tree;
}
BinarTree* delete_element_tree2(string name_delete, BinarTree* tree)
{
	BinarTree* find_element_tree = find_the_knot_tree(name_delete, tree);
	BinarTree* parent_element = find_parent_tree(find_element_tree, tree);
	BinarTree* tmp_tree = nullptr;
	tmp_tree = copy_tree(tmp_tree, find_element_tree->left);
	tmp_tree = copy_tree(tmp_tree, find_element_tree->right);
	if(tree == find_element_tree)
	{
		delete_branches(find_element_tree);
		tree = nullptr;
	}
	else
	{
		if(parent_element->left == find_element_tree)
		{
			delete_branches(find_element_tree);
			parent_element->left = nullptr;
		}
		else
		{
			if(parent_element->right == find_element_tree)
			{
				delete_branches(find_element_tree);
				parent_element->right = nullptr;
			}
		}
	}
	tree = copy_tree(tree, tmp_tree);
	return tree;
}
int main()
{
	setlocale(LC_ALL, "");
	BinarTree* tree = nullptr;
	DataField data_field;
	string name_find;
	int menu = 0;
	bool exit_menu = true;
	while (exit_menu)
	{
		cout << "\n1-To add in tree element\n2-To add in tree element random value\n3-To show all tree\n4-To find the knot tree by the name\n5-To delete the knot tree by the name\n0-To exit\nEnter nubmer: ";
		cin >> menu;
		switch (menu)
		{
		case 1:
		{
			cout << "Enter element tree: ";
			data_field.input();
			tree = add_node(data_field, tree);
			break;
		}
		case 2:
		{
			cout << "Random element tree: - OK.\n";
			data_field.set_random();
			tree = add_node(data_field, tree);
			break;
		}
		case 3:
		{
			cout << "Show all tree:\n";
			treeprint(tree);
			break;
		}
		case 4:
		{
			cout << "Enter name: ";
			cin >> name_find;
			treeprint_byname(name_find, tree);
			break;
		}
		case 5:
		{
			cout << "Enter name: ";
			cin >> name_find;
			tree = delete_element_tree2(name_find, tree);
			break;
		}
		case 0:
		{
			exit_menu = false;
			break;
		}
		default:
		{
			break;
		}
		}
	}
	delete_tree(tree);
	return 0;
}