#include <iostream>
#include <vector>
#include <algorithm>
#define INF 9999999; // (for Prim's algorithm)
#define edge pair<int, int> // (for Kruskal's algorithm) define an edge as a pair of two integers (vertex numbers)

using namespace std;

/*
Prim's algorithm
*/
const int V = 5; // Number of vertices in a graph
int G[V][V] = { // Two-dimensional array of size 5x5 for the adjacency matrix to represent the weighted graph
	{0, 9, 75, 0, 0},
	{9, 0, 95, 19, 42},
	{75, 95, 0, 51, 66},
	{0, 19, 51, 0, 31},
	{0, 42, 66, 31, 0}
};

/*
Kruskal's algorithm
*/
class Graph
{
private:
	vector<pair<int, edge>> G; // graph as a dynamic array of pairs (weight, arc)
	vector<pair<int, edge>> T; // spanning graph minimum weight as a dynamic array of pairs (weight, arc)
	int* parent; // point to the parent node
	int V; // number of vertices (nodes) in the graph
public:
	Graph(int V);
	void AddWeightedEdge(int u, int v, int w); // method for adding a weighted arc, takes vertex numbers and the weight of the arc between them
	int find_set(int i); // vertex set method
	void union_set(int u, int v); // vertex merge method
	void kruskal(); // Kruskal's method for finding the spanning tree of a minimum weight graph
	void print(); // method for printing an arc (two numbers of connected vertices) and its weight
};
Graph::Graph(int V) // graph constructor with parameters, takes the number of graph vertices
{
	parent = new int[V];
	for (int i = 0; i < V; i++)
	{
		parent[i] = i;
	}
	G.clear();
	T.clear();
}
void Graph::AddWeightedEdge(int u, int v, int w)
{
	G.push_back(make_pair(w, edge(u, v)));
}
int Graph::find_set(int i)
{
	if (i == parent[i]) // if the vertex with number i is cyclically closed on itself ("its own parent")
	{
		return i;
	}
	else // otherwise, if ai is not a parent of itself, then ai is not a representative of its set, so we recursively call the method to find its "parent"
	{
		return find_set(parent[i]);
	}
}
void Graph::union_set(int u, int v)
{
	parent[u] = parent[v];
}
void Graph::kruskal()
{
	int i, uRep, vRep;
	sort(G.begin(), G.end()); // sort the weights of the arcs in ascending order (increasing weight)
	for (i = 0; i < G.size(); i++)
	{
		uRep = find_set(G[i].second.first);
		vRep = find_set(G[i].second.second);
		if (uRep != vRep)
		{
			T.push_back(G[i]); // add a vertex to the spanning tree of the minimum weight graph
			union_set(uRep, vRep);
		}
	}
}
void Graph::print()
{
	cout << "Edge:\this weight\n"; // print the edge (between which vertices it is) and its weight
	for (int i = 0; i < T.size(); i++)
	{
		cout << T[i].second.first << " - " << T[i].second.second << ":\t" << T[i].first << endl;
	}
}



int main()
{
	srand(time(NULL));
	int p = 0;
	cout << "1 - Prim's algorithm\n" << "2 - Kruskal's algorithm\n" << "3 - Task\n" << "0 - Exit\n" << "Enter: ";
	cin >> p;
	switch (p)
	{
	case 0:
	{
		break;
	}
	case 1:
	{
		/*
		Prim's algorithm
		*/
		// the number of edges in the minimum spanning tree will be (V - 1), where V is the number of vertices in the graph
		int no_edge; // Number of ribs
		int selected[V]; // array to keep track of selected vertices (selected vertex will be true, unselected will be false)
		memset(selected, false, sizeof(selected)); // set all vertices to false initially
		no_edge = 0; // set the number of edges as initially zero
		selected[0] = true; // array to keep track of selected vertices (selected vertex will be true, unselected will be false)
		int x, y; // x - number of rows, y - number of columns
		cout << "Edge:\this weight\n"; // print the edge (between which vertices it is) and its weight
		while (no_edge < V - 1) // go through all the edges (there are 1 less of them than all the vertices of the connected graph)
		{ // for each vertex in the set With find all neighboring vertices, calculate the distance (weight) from the vertex selected in step 1
			int min = INF; // if the vertex is already in set 5, discard it, otherwise select another vertex,
			x = 0; // closest to the vertex selected in step 1
			y = 0;
			for (int i = 0; i < V; i++)
			{
				if (selected[i])
				{
					for (int j = 0; j < V; j++)
					{
						if (!selected[j] && G[i][j]) // is this a vertex and it's not selected yet?
						{
							if (min > G[i][j]) // if the weight of this edge is less than the minimum
							{
								min = G[i][j]; // then we make this weight minimal
								x = i; // We save the vertex number A
								y = j; // We save the vertex number B
							}
						}
					}
				}
			}
			cout << x << " - " << y << ":\t" << G[x][y] << endl;
			selected[y] = true; // the vertex has already been selected, mark it as true
			no_edge++; // increment the vertex number to work with the new vertex in the next iteration
			break;
		}
	}
	case 2:
	{
		/*
		Kruskal's algorithm
		*/
		Graph g(6); // create a graph with 6 vertices
		g.AddWeightedEdge(0, 1, 4); // add an arc to the graph between vertices 0 and 1, weight 4
		g.AddWeightedEdge(0, 2, 4); // add an arc to the graph between vertices 0 and 2, weight 4
		g.AddWeightedEdge(1, 2, 2); // add an arc to the graph between vertices 1 and 2, weight 2
		g.AddWeightedEdge(1, 0, 4); // add an arc to the graph between vertices 1 and 0, weight 4
		g.AddWeightedEdge(2, 0, 4); // add an arc to the graph between vertices 2 and 0, weight 4
		g.AddWeightedEdge(2, 1, 2); // add an arc to the graph between vertices 2 and 1, weight 2
		g.AddWeightedEdge(2, 3, 3); // add an arc to the graph between vertices 2 and 3, weight 3
		g.AddWeightedEdge(2, 5, 2); // add an arc to the graph between vertices 2 and 5, weight 2
		g.AddWeightedEdge(2, 4, 4); // add an arc to the graph between vertices 2 and 4, weight 4
		g.AddWeightedEdge(3, 2, 3); // add an arc to the graph between vertices 3 and 2, weight 3
		g.AddWeightedEdge(3, 4, 3); // add an arc to the graph between vertices 3 and 4, weight 3
		g.AddWeightedEdge(4, 2, 4); // add an arc to the graph between vertices 4 and 2, weight 4
		g.AddWeightedEdge(4, 3, 3); // add an arc to the graph between vertices 4 and 3, weight 3
		g.AddWeightedEdge(5, 2, 2); // add an arc to the graph between vertices 5 and 2, weight 2
		g.AddWeightedEdge(5, 4, 3); // add an arc to the graph between vertices 5 and 4, weight 3
		g.kruskal();
		g.print();
		break;
	}
	case 3:
	{
		Graph g(9);
		g.AddWeightedEdge(1, 2, rand());
		g.AddWeightedEdge(1, 4, rand());
		g.AddWeightedEdge(1, 6, rand());
		g.AddWeightedEdge(2, 8, rand());
		g.AddWeightedEdge(3, 8, rand());
		g.AddWeightedEdge(3, 7, rand());
		g.AddWeightedEdge(4, 5, rand());
		g.AddWeightedEdge(5, 6, rand());
		g.AddWeightedEdge(5, 9, rand());
		g.AddWeightedEdge(6, 7, rand());
		g.AddWeightedEdge(8, 9, rand());
		g.kruskal();
		g.print();
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