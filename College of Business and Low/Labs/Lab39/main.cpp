#include <iostream>
#include <queue>
#include <stack>

using namespace std;

class Graph
{
private:
	int count;
	vector<pair<int, pair<int, int>>> egde;
public:
	Graph(int a);
	void AddWeightedEdge(int u, int v, int weigth);
	void print();
	void BellFord(int start);
};
Graph::Graph(int count) {
	this->count = count;
	this->egde.clear();
}

void Graph::AddWeightedEdge(int u, int v, int weigth) {
	this->egde.push_back(pair<int, pair<int, int>>(weigth, pair<int, int>(u - 1, v - 1)));
}

void Graph::print() {
	for (int i = 0; i < egde.size(); i++) {
		cout << "<" << egde[i].second.first + 1 << ">\t" << egde[i].first << "\t<" << egde[i].second.second + 1 << ">\n";
	}
}

void Graph::BellFord(int start) {
	vector<int> dist(count, INT_MAX / 2);
	dist[start - 1] = 0;
	for (int i = 0; i < count - 1; i++) {
		for (int j = 0; j < egde.size(); j++) {
			if (dist[egde[j].second.first] + egde[j].first < dist[egde[j].second.second]) {
				dist[egde[j].second.second] = dist[egde[j].second.first] + egde[j].first;
			}
		}
	}
	for (int i = 0; i < count; i++) {
		cout << "Vertex " << i + 1 << ": " << dist[i] << "\n";
	}
}

int main()
{
	int p = 0;
	cout << "1 - Dijkstra's algorithm\n" << "2 - The task of finding the shortest path\n" << "3 - Task\n" << "0 - Exit\n" << "Enter: ";
	cin >> p;
	switch (p)
	{
	case 0:
	{
		break;
	}
	case 1:
	{
		const int SIZE = 6;
		int a[SIZE][SIZE] = { // link matrix and its initialization
		{0, 7, 9, 0, 0, 14},
		{7, 0, 10, 15, 0, 0},
		{9, 10, 0, 11, 0, 2},
		{0, 15, 11, 0, 6, 0},
		{0, 0, 0, 6, 0, 9},
		{14, 0, 2, 0, 9, 0}
		};
		int d[SIZE]; // array of minimum distances
		int v[SIZE]; // array of visited vertices
		int temp, minindex, min;
		int begin_index = 0;
		for (int i = 0; i < SIZE; i++) // relationship matrix output
		{
			for (int j = 0; j < SIZE; j++)
			{
				cout << a[i][j] << '\t';
			}
			cout << endl;
		}
		for (int i = 0; i < SIZE; i++) // vertex and distance initialization
		{
			d[i] = 10000;
			v[i] = 1;
		}
		d[begin_index] = 0;
		do
		{
			minindex = 10000;
			min = 10000;
			for (int i = 0; i < SIZE; i++)
			{
				if ((v[i] == 1) && (d[i] < min))
				{ // If the vertex has not yet been bypassed and the weight is less than min, then we assign the values
					min = d[i];
					minindex = i;
				}
			}
			if (minindex != 10000)
			{ // Add the found minimum weight to the current vertex weight and compare with the current minimum vertex weight
				for (int i = 0; i < SIZE; i++)
				{
					if (a[minindex][i] > 0)
					{
						temp = min + a[minindex][i];
						if (temp < d[i])
						{
							d[i] = temp;
						}
					}
				}
				v[minindex] = 0;
			}
		} while (minindex < 10000);
		cout << "Shortest distance to peaks:\n";
		for (int i = 0; i < SIZE; i++)
		{
			cout << d[i] << ' ';
		}
		// Restoring the paths
		int ver[SIZE]; // array of visited vertices
		int end = 4; // end vertex index = 5 - 1
		ver[0] = end + 1; // start element - end vertex
		int k = 1; // previous peak index
		int weight = d[end]; // end vertex weight
		while (end != begin_index) // until you reach the top
		{
			for (int i = 0; i < SIZE; i++) // look at all vertices
			{
				if (a[i][end] != 0) // if there is a connection
				{
					int temp = weight - a[i][end]; // determine the weight of the path from the previous vertex
					if (temp == d[i]) // if the weight coincided with the calculated weight, then there was a transition from this vertex
					{
						weight = temp; // keep the new weight
						end = i; // save the previous vertex
						ver[k] = i + 1; // and write it to an array
						k++;
					}
				}
			}
		}
		cout << "\nOutput of the shortest path:\n";
		for (int i = k - 1; i >= 0; i--)
		{
			cout << ver[i] << ' ';
		}
		cout << endl;
		break;
	}
	case 2:
	{
		struct Edge // Structure Edge (Arc graph)
		{
			int begin; // number of one vertex connected by this arc
			int end; // number of another vertex connected by this arc
		};
		queue<int> Queue; // queue of integers - graph vertices
		stack<Edge> Edges; // stack of graph arcs
		int req;
		Edge e;
		int mas[7][7] = { // link matrix and its initialization
		{0, 1, 1, 0, 0, 0, 1},
		{1, 0, 1, 1, 0, 0, 0},
		{1, 1, 0, 0, 0, 0, 0},
		{0, 1, 0, 0, 1, 0, 0},
		{0, 0, 0, 1, 0, 1, 0},
		{0, 0, 0, 0, 1, 0, 1},
		{1, 0, 0, 0, 0, 1, 0}
		};
		int nodes[7]; // graph vertices
		for (int i = 0; i < 7; i++) // initially all vertices are 0
		{
			nodes[i] = 0;
		}
		cout << "Enter the number of the required graph vertex (from 1 to 7): ";
		cin >> req;
		req--;
		Queue.push(0); // put the first vertex in the queue
		while (!Queue.empty()) // the loop runs until the queue is empty
		{
			int node = Queue.front(); // read the value of the vertex from the front queue
			Queue.pop(); // extract (remove) the vertex from the queue in front
			nodes[node] = 2; // mark this vertex as visited
			for (int j = 0; j < 7; j++)
			{
				if (mas[node][j] == 1 && nodes[j] == 0) // if the vertex is adjacent and not previously discovered
				{
					Queue.push(j); // then add it to the queue
					nodes[j] = 1; // mark this vertex as discovered
					e.begin = node; // apex of the beginning of the arc
					e.end = j; // vertex of the end of the arc
					Edges.push(e); // push this arc onto the stack
					if (node == req) // if the vertex number is the same as the desired vertex number
					{
						break; // stop passing through the vertices of the graph
					}
				}
			}
			cout << node + 1 << endl; // print the number of the vertex of the graph
		}
		cout << "Way to the top " << req + 1 << ":\n";
		cout << req + 1;
		while (!Edges.empty()) // the loop is executed until the stack with arcs is empty
		{
			e = Edges.top(); // take the top (last) top of the stack (there is an edge), copy (save) its data to the edge e
			Edges.pop(); // remove that edge from the top of the stack
			if (e.end == req) // if the final vertex of the taken edge is equal to the number of the required vertex
			{
				req = e.begin; // then we make the initial vertex of the edge the required one
				cout << " <- " << req + 1; // print path along arcs between vertices (numbers of vertices)
			}
		}
		cout << endl;
		break;
	}
	case 3:
	{
		Graph graph(5);
		graph.AddWeightedEdge(2, 1, 6);
		graph.AddWeightedEdge(4, 1, 1);
		graph.AddWeightedEdge(1, 2, 2);
		graph.AddWeightedEdge(3, 2, 6);
		graph.AddWeightedEdge(2, 3, 3);
		graph.AddWeightedEdge(4, 3, 3);
		graph.AddWeightedEdge(1, 4, 1);
		graph.AddWeightedEdge(5, 4, 1);
		graph.AddWeightedEdge(1, 5, 5);
		graph.AddWeightedEdge(2, 5, 1);
		graph.AddWeightedEdge(4, 5, 1);
		graph.BellFord(2);
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