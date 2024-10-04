#include <iostream>
#include <vector>

using namespace std;


class Graph {
private:
	int count;
	int** matrix;
public:
	Graph(int a, int** matrix);
	Graph(int a);
	int get(int out, int in);
	void set(int out, int in, int weight);
	void print();
	void floid();
};
Graph::Graph(int a) {
	this->count = a;
	this->matrix = new int* [this->count];
	for (int i = 0; i < this->count; i++) {
		this->matrix[i] = new int[this->count];
		for (int j = 0; j < this->count; j++) {
			this->matrix[i][j] = 0;
		}
	}
}

Graph::Graph(int a, int** matrix) : Graph(a) {
	for (int i = 0; i < this->count; i++) {
		for (int j = 0; j < this->count; j++) {
			this->matrix[i][j] = matrix[i][j];
		}
	}
}

void Graph::print() {
	cout << "[-]\t";
	for (int i = 0; i < this->count; i++) {
		cout << "[" << i << "]\t";
	}
	cout << "\n";
	for (int i = 0; i < this->count; i++) {
		cout << "[" << i << "]\t";
		for (int j = 0; j < this->count; j++) {
			cout << this->matrix[i][j] << "\t";
		}
		cout << "\n";
	}
}

int Graph::get(int out, int in) {
	return this->matrix[out][in];
}

void Graph::set(int out, int in, int weight) {
	this->matrix[out][in] = weight;
}

void Graph::floid() {
	int max = 0;
	for (int i = 0; i < this->count; i++) {
		for (int j = 0; j < this->count; j++) {
			max += this->matrix[i][j];
		}
	}
	for (int i = 0; i < this->count; i++) {
		for (int j = 0; j < this->count; j++) {
			if (this->matrix[i][j] == 0 && i != j) {
				this->matrix[i][j] = max;
			}
		}
	}
	for (int k = 0; k < this->count; k++) {
		for (int i = 0; i < this->count; i++) {
			for (int j = 0; j < this->count; j++) {
				if (this->matrix[i][k] + this->matrix[k][j] < this->matrix[i][j]) {
					this->matrix[i][j] = this->matrix[i][k] + this->matrix[k][j];
				}
			}
		}
	}
}

int main()
{
	int p = 0;
	cout << "1 - Algorithm\n" << "2 - Task\n" << "0 - Exit\n" << "Enter: ";
	cin >> p;
	switch (p)
	{
	case 0:
	{
		break;
	}
	case 1:
	{
		Graph graph(8);
		graph.set(0, 7, 30);
		graph.set(0, 1, 40);
		graph.set(1, 2, 30);
		graph.set(2, 3, 40);
		graph.set(3, 4, 30);
		graph.set(4, 5, 40);
		graph.set(5, 6, 30);
		graph.set(6, 7, 40);
		graph.set(0, 5, 20);
		graph.set(5, 7, 40);
		cout << "Adjacency matrix\n";
		graph.print();
		cout << "\n";
		cout << "Adjacency matrix after solving the problem\n";
		graph.floid();
		graph.print();
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