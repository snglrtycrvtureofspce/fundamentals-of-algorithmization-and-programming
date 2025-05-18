#include <iostream>
#include <queue>
#include <stack>


using namespace std;



/*
A graph is a collection of points connected by lines.
Points are called vertices, or nodes, and lines are called edges, or arcs.
The entry degree of a vertex is the number of edges entering it,
and the exit degree of a vertex is the number of edges outgoing from this vertex.
A graph containing edges between all pairs of vertices is a complete graph.
There are graphs whose edges are assigned a specific numerical value (weight),
they are called weighted graphs, and this value is the weight of the edge.
When both ends of the edge coincide,
i.e. an edge leaves a vertex and enters the same vertex,
then such an edge is called a loop.
// Graph classification //
1. connected
// There is at least one path between any pair of vertices.
2. disconnected
// There is at least one vertex that is not connected to other vertices of this graph.
3. Oriented
// The edges are directed,
// i.e. there is only one available direction of movement between two connected vertices.
4. Non-oriented
// Each of the edges can be navigated in both directions.
5. Mixed
// It contains both directed and undirected edges. 
// Ways to represent a graph //
1. adjacency matrix;
// The adjacency matrix of a graph is a square matrix in which each element takes one of two values: 0 or 1.
The number of rows of the adjacency matrix is equal to the number of columns and corresponds to the number of graph vertices:
//// 0 - corresponds to the absence of an edge,
//// 1 - corresponds to the presence of an edge.
2. incidence matrix;
// The incidence (incidence) matrix of a graph is a matrix in which the number of rows corresponds to the number of vertices,
and the number of columns corresponds to the number of edges.
It indicates the connections between the incident elements of the graph: an edge (arc) and a vertex.
In an undirected graph, if a vertex is incident to an edge,
then the corresponding element is 1; otherwise, the element is 0.
In a directed graph, if an edge leaves a vertex, then the corresponding element is 1;
if the edge enters the vertex, then the corresponding element is -1;
if there is no edge, then the element is 0.
The incidence matrix for its representation requires the numbering of edges, which is not always convenient.
3. adjacency list(incidents);
// If the number of graph edges compared to the number of vertices is small,
then the values ​​of most elements of the adjacency matrix will be equal to 0.
In this case, the use of this method is inappropriate.
For such graphs, there are more optimal ways to represent them.
With respect to computer memory, adjacency lists are less demanding than adjacency matrices.
Such a list can be represented as a table with 2 columns and no more rows than vertices in the graph.
In each line, the first column contains the exit vertex, and the second column contains a list of vertices that include edges from the current vertex.
//// Advantages of adjacency list: ////
// 1. Rational use of memory.
// 2.Allows you to quickly sort through the neighbors of a given vertex.
// 3.Allows you to check for the presence of an edge and delete it.
//// Adjacency List Disadvantages: ////
// 1. When working with saturated graphs (with a large number of edges),
the speed may not be enough to process the entire large graph.
// 2. There is no quick way to check if an edge exists between two vertices.
// 3. The number of graph vertices must be known in advance.
// 4. For weighted graphs, you have to store a list whose elements must contain two meaningful fields (see below),
which complicates the code:
//// 4.1. the number of the vertex that the current vertex connects to.
//// 4.2. edge weight (number).
4. list of edges.
In the list of edges,
each line contains two adjacent vertices and the weight of the edge connecting them (for a weighted graph).
The number of rows in the list of edges must always be equal to the value obtained by adding directed edges to twice the number of undirected edges.
What is the best way to represent a graph? The answer depends on the relationship between the number of vertices and the number of edges.
The number of edges can be quite small (of the same order as the number of vertices) or quite large (if the graph is complete).
Graphs with a large number of edges are called dense, with a small number - sparse. It is more convenient to store dense graphs in the form of an adjacency matrix, sparse graphs - in the form of an adjacency list.
////////////////////////////////////////
When the passage from one vertex to another is free (there is an edge), 1 is entered into the cell, otherwise 0.
All elements on the main diagonal are 0 if the graph has no loops.
*/


struct edge {
	int begin;
	int end;
};


int main()
{
	int p = 0;
	cout << "Enter number: "; cin >> p;
	switch (p)
	{
	case 1: // directed graphs
	{
		queue<int>q; // create a queue named q to store integer values
		cout << "Enter 7 numbers:\n";
		for (int i = 0; i < 7; i++)
		{
			int a = 0;
			cout << "Enter number #" << i << ": ";
			cin >> a;
			q.push(a); // add the number a to the end of the queue q. If the queue is empty, the number will become the first.
		}
		cout << "The very first element in the queue: " << q.front() << endl;
		q.pop(); // remove the current first element from the queue
		cout << "New first element (after removal): " << q.front() << endl;
		if (!q.empty())
		{
			cout << "The queue is not empty!\n";
		}
		while (q.empty() == false)
		{
			cout << "The queue is not empty. It has the first element: " << q.front() << " and the last element: " << q.back() << ". Let's remove the last element.\n";
			q.pop(); // remove the current first element from the queue
		}
		break;
	}
	case 2: // undirected graphs
	{
		queue<int> queue; // create a queue named queue to store integer values
		const int n = 7; // number of vertices in a graph
		int mas[n][n]{
			{0, 1, 1, 0, 0, 0, 1}, // adjacency matrix of each vertex (its number is equal to the row number)
			{1, 0, 1, 1, 0, 0, 0}, // with each vertex (all options in the row, including with itself)
			{1, 1, 0, 0, 0, 0, 0}, // adjacency matrix implemented as a two-dimensional array
			{0, 1, 0, 0, 1, 0, 0},
			{0, 0, 0, 1, 0, 1, 0},
			{0, 0, 0, 0, 1, 0, 1},
			{1, 0, 0, 0, 0, 1, 0}
		};
		int nodes[n]; // graph vertices, n pieces
		for (int i = 0; i < n; i++) // let's go to all the peaks
		{
			nodes[i] = 0; // initially we make all vertices equal to 0 (they have not been visited yet)
		}
		int x = 0;
		bool f = false;
		cout << "Enter the number of the vertex whose presence in the column you want to check: ";
		cin >> x;
		queue.push(0); // put the first vertex in the queue
		while (!queue.empty()) // until the queue is empty
		{
			int node = queue.front(); // read the value stored in the element (top) at the head of the queue
			queue.pop(); // extract (remove) the vertex (value) from the head of the queue
			nodes[node] = 2; // mark the extracted vertex as visited (value equal to 2)
			for (int j = 0; j < n; j++) // check for it all adjacent vertices
			{
				if (mas[node][j] == 1 && nodes[j] == 0) // if the vertex is adjacent and has not been discovered before
				{
					queue.push(j); // add a vertex to the queue
					nodes[j] = 1; // mark the vertex as already discovered
				}
			}
			cout << endl << node; // display the vertex number for the user
			if (node == x)
			{
				cout << "This top was the one you were looking for.";
				f = true;
			}
		}
		if (!f)
		{
			cout << "\nThe vertex you are looking for was not found in this graph.\n";
		}
		cout << endl;
		break;
	}
	case 3:
	{
		queue<int> Queue;
		stack<edge> Edges;
		int req;
		edge e;
		int mas[7][7] = { { 0, 1, 1, 0, 0, 0, 1 },
		{ 1, 0, 1, 1, 0, 0, 0 },
		{ 1, 1, 0, 0, 0, 0, 0 },
		{ 0, 1, 0, 0, 1, 0, 0 },
		{ 0, 0, 0, 1, 0, 1, 0 },
		{ 0, 0, 0, 0, 1, 0, 1 },
		{ 1, 0, 0, 0, 0, 1, 0 } };
		int nodes[7]; // graph vertices
		for (int i = 0; i < 7; i++) // initially all vertices are 0
			nodes[i] = 0;
		cout << "N = "; cin >> req; req--;
		Queue.push(0); // put the first vertex in the queue
		while (!Queue.empty())
		{
			int node = Queue.front(); // extract the vertex
			Queue.pop();
			nodes[node] = 2; // mark it as visited
			for (int j = 0; j < 7; j++)
			{
				if (mas[node][j] == 1 && nodes[j] == 0)
				{ // if the vertex is adjacent and not found
					Queue.push(j); // add it to the queue
					nodes[j] = 1; // mark the vertex as discovered
					e.begin = node; e.end = j;
					Edges.push(e);
					if (node == req) break;
				}
			}
			cout << node + 1 << endl; // get the vertex number
		}
		cout << "Way to the top " << req + 1 << endl;
		cout << req + 1;
		while (!Edges.empty()) {
			e = Edges.top();
			Edges.pop();
			if (e.end == req) {
				req = e.begin;
				cout << " <- " << req + 1;
			}
		}
		cin.get();
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