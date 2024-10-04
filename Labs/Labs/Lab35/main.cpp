#include <iostream>
#include <vector>
#include <queue>


using namespace std;
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;

/*
The depth-first search (DFS) algorithm allows you to build a traversal of a directed or undirected graph, in which all vertices accessible from the initial vertex are visited.
The difference between depth-first search and breadth-first search is that (in the case of a non-directed graph) the result of the depth-first search algorithm is some route,
following which you can sequentially traverse all the vertices of the graph accessible from the initial vertex. This is fundamentally different from breadth-first search,
where many vertices are processed at the same time; in depth-first search, only one vertex is processed at each moment of the algorithm execution.
On the other hand, depth-first search does not find the shortest paths, but it is applicable in situations where the graph is not known as a whole,
but is being explored by some automated device. If the graph is directed, then depth-first search builds a tree of paths from the initial vertex to all accessible from it.
Depth traversal can be imagined as follows. Let the researcher be in some maze (graph) and he wants to bypass the entire maze (visit all available vertices in the graph).
The researcher is at some vertex and sees edges coming from this vertex. The obvious sequence of actions of the researcher is as follows:
// 1) Go to some adjacent vertex.
// 2) Go around everything that is available from this vertex.
// 3) Return to the starting vertex.
// 4) Repeat the algorithm for all other vertices adjacent to the initial one.
We see that the algorithm is recursive - to traverse the entire graph, you need to move to a neighboring vertex, and then repeat the traversal algorithm for this vertex.
But the looping problem arises - if you can go from node A to node B, then you can go from node B to node A and the recursion will be infinite.
To combat recursion, you need to apply a very simple idea - the researcher should not go to the vertex that he has already been to, that is,
which is not of interest to him (we believe that only vertices that he has not been to before are of interest to the researcher ).
So the refined algorithm might look like this:
// 1) Go to some adjacent vertex that has not been visited before.
// 2) Run the depth-first search algorithm from this vertex.
// 3) Return to the starting vertex.
// 4) Repeat steps 1-3 for all previously unvisited adjacent vertices.
To implement the algorithm, it will be necessary to mark which vertices the researcher was at and which were not.
The label will be in the visited list, where visited[i] == true for visited vertices, and visited[i] == false for unvisited ones.
The mark "about visiting the peak" is placed when entering this peak. Since the purpose of depth-first traversal is often to build a depth-first traversal tree,
we will immediately store a predecessor for each vertex. The depth-first traversal algorithm is presented as a recursive function dfs,
where start is the number of the vertex from which the traversal is started.
*/
void dfs1(int start, vector<bool>& visited, vector <int>& prev, const vector <vector <int> > g)
{
	visited[start] = true;
	for (auto u : g[start])
	{
		if (!visited[u])
		{
			prev[u] = start;
			dfs1(u, visited, prev, g);
		}
	}
}



/*
// Identification of connectivity components //
The depth-first search algorithm allows you to solve many different problems.
For example, let's use the depth-first search algorithm to count the number of connected components in an undirected graph.
To do this, we will go around all the vertices of the graph and check whether the next vertex has been visited before.
If not, then it means that a new connectivity component has been found, to select the entire connectivity component, you need to run DFS from this vertex.
*/
void dfs2(int start, vector<bool>& visited, const vector <vector <int> > g)
{
	visited[start] = true;
	for (auto u : g[start])
	{
		if (!visited[u])
		{
			dfs2(u, visited, g);
		}
	}
}



/*
// Checking a graph for bipartite //
A graph is called bipartite if its vertices can be divided into two sets so that the ends of each edge belong to different sets.
In other words, it is possible to color the vertices of the graph in two colors so that the ends of each edge are painted in a different color.
We modify the DFS algorithm in such a way that it will check the graph for bipartite and build a coloring of the graph in two colors (if it is bipartite).
To do this, we will replace the Visited list with the Color list, in which we will store the value 0 for unvisited vertices,
and for visited vertices we will face the value 1 or 2 - its color.
The DFS algorithm for each edge will check the color of the end vertex of that edge.
If the vertex has not been visited, then it is painted in a color that is not equal to the color of the current vertex.
If the vertex has been visited, then the edge is either skipped if its ends are multi-colored, and if its ends are of the same color,
then a note is made that the graph is not bipartite (the IsBipartite variable is assigned the value False, its value can be used to judge whether bipartite graph).
*/
bool is_bipartite = true;
void dfs3(int start, vector<int>& color, const vector <vector <int> > g)
{
	for (auto u : g[start])
	{
		if (color[u] == 0)
		{
			color[u] = 3 - color[start];
			dfs3(u, color, g);
		}
		else
		{
			if (color[u] == color[start])
			{
				is_bipartite = false;
			}
		}
	}
}



/*
// Finding a Cycle in a Directed Graph //
A cycle in a directed graph can be detected by the presence of an edge leading from the current vertex to a vertex that is currently being processed,
that is, the DFS algorithm has entered such a vertex, but has not yet left it. In such a DFS algorithm, we will paint the vertices in three colors.
The color 0 ("white") will denote not yet visited vertices. Color 1 (“gray”) will denote the vertices in the process of processing,
and color 2 (“black”) will denote already processed vertices. The vertex is painted in color 1 when entering this vertex and in color 2 when leaving.
A cycle exists in a graph if the DFS algorithm detects an edge whose end is colored 1.
*/
bool cycle_found = false;
void dfs4(int start, vector<int>& color, const vector <vector <int> > g)
{
	color[start] = 1;
	for (auto u : g[start])
	{
		if (color[u] == 0)
		{
			dfs4(u, color, g);
		}
		else
		{
			if (color[start] == 1)
			{
				cycle_found = true;
			}
		}
	}
	color[start] = 2;
}



/*
// Topological sort //
Finally, another important application of depth-first search is topological sorting.
Let a directed graph not containing cycles be given.
Then the vertices of this graph can be ordered in such a way that all edges will go from vertices with a lower number to vertices with a higher number.
For topological sorting of a graph, it is enough to run the DFS algorithm, when leaving a vertex, adding the vertex to the end of the list with the answer.
After the end of the algorithm, expand the list with the answer in the opposite order.
*/
void dfs5(int start, vector <bool>& visited, vector <bool>& ans, const vector <vector <int> > g)
{
	visited[start] = true;
	for (auto u : g[start])
	{
		if (!visited[u])
		{
			dfs5(u, visited, ans, g);
		}
	}
	ans.push_back(start);
}



/*
// Bridge search //
A bridge is an edge, upon removal of which the graph splits into two connected components.
The depth-first search algorithm allows you to find all bridges in a connected graph in one DFS, that is, in O(n) complexity.
Let's hang the graph by some vertex, launch DFS from this vertex.
DFS will build a graph traversal tree, while finding back edges - edges that go from the current vertex to the vertex that is currently being processed.
Each vertex u is assigned the value h(u) – its depth in the traversal tree. In addition, each vertex is associated with the value of the function f(u),
where f(u) is the minimum value of h(v) for all vertices v that are reachable from the vertex u in the traversal tree,
and are also reachable by passing one by one backward edge from any descendant of u in the traversal tree.
Then the edge uv will be a bridge if f(v) > h(u). The values ​​h(u) and f(u) can be considered as one DFS.
////////////////////////////////////
Parameters passed to the function:
u - current vertex
parent - the parent to not traverse the edge in the opposite direction (this implementation does not work on a graph with multiple edges).
curr_h - current depth
g – graph adjacency lists
h - array of depth values for vertices
f – array of objective function values for vertices
*/
void dfs6(int u, int parent, int curr_h, vector <vector<int> >& g, vector <bool>& visited, vector<int> &h, vector<int>& f)
{
	h[u] = curr_h++;
	f[u] = h[u];
	visited[u] = true;
	for (auto v : g[u])
	{
		if (v == parent)
		{
			continue;
		}
		if (!visited[v])
		{
			dfs6(v, u, curr_h, g, visited, h, f);
			f[u] = min(f[u], f[v]);
			if (f[v] > h[u])
			{
				// u-v bridge found
			}
		}
		else
		{
			f[u] = min(f[u], h[v]);
		}
	}
}


/*
// Recursive depth-first search function //
We pass it a two-dimensional dynamic square array as the adjacency matrix of the graph,
a logical array to control the visited vertices of the graph, the current vertex (its number), the dimension of the array (the number of graph vertices).
*/
void DFS7(int** graph, bool* visited, int st, int n)
{
	cout << st + 1 << " "; // printing of the vertex number (counting from one)
	visited[st] = true;
	for (int r = 0; r <= n; r++)
	{
		if ((graph[st][r] != 0) && (!visited[r])) // visited[r] == false
		{
			DFS7(graph, visited, r, n); // let's visit this peak
		}
	}
}

////////////////////////////
void printgrav(int** grav, int n)
{
for (int i = 0; i < n; i++) {
	for (int j = 0; j < n; j++) {
		cout << grav[i][j] << " ";
	}
	cout << endl;
}
}
void dfsDeep(int** grav, bool* visited, int start, int n, int k)
{
	bool dell = false;
	if (visited == nullptr) {
		visited = new bool[n];
		for (int i = 0; i < n; i++) {
			visited[i] = false;
		}
		dell = true;
	}
	if (start + 1 == k) {
		cout << "(" << start + 1 << ") ";
	}
	else {
		cout << start + 1 << " ";
	}
	visited[start] = true;
	for (int i = 0; i < n; i++) {
		if ((grav[start][i] != 0) && (!visited[i])) {
			dfsDeep(grav, visited, i, n, k);
		}
	}
	if (dell) {
		delete[] visited;
	}
	return;
}
////////////////////////////


void main()
{
	//int n = 5;
	//int** graph = new int* [n]
	//{
	//	new int[n]
	//	{
	//		0, 1, 0, 0, 1
	//	},
	//		new int[n]
	//		{
	//			1, 0, 1, 1, 0
	//		},
	//			new int[n]
	//			{
	//				0, 1, 0, 0, 1
	//			},
	//				new int[n]
	//				{
	//					0, 1, 0, 0, 1
	//				},
	//					new int[n]
	//					{
	//						1, 0, 1, 1, 0
	//					}
	//};
	//bool* visited = new bool[n];
	//if (!visited)
	//{
	//	cout << "No memory for boolean array.";
	//	return;
	//}
	//cout << "Graph Adjacency Matrix:\n";
	//for (int i = 0; i < n; i++)
	//{
	//	visited[i] = false;
	//	for (int j = 0; j < n; j++)
	//	{
	//		cout << " " << graph[i][j];
	//	}
	//	cout << endl;
	//}
	//int start;
	//do
	//{
	//	cout << "Starting top: "; cin >> start;
	//} while (start < 1 || start > n);
	//cout << "The order of traversal of the graph vertices in depth from the one you entered: ";
	//DFS7(graph, visited, start - 1, n);
	//cout << endl;
	/////////////////////////////
	int select = 0;
	cout << "Select function (only 6): "; cin >> select;
	switch (select)
	{
	//case 1:
	//{
	//	vector <bool> visited(n + 1); // first you need to create dynamic arrays for the graph vector <data-type> name
	//	vector <int> prev(n + 1, -1);
	//	dfs1(start, visited, prev, g);
	//	break;
	//}
	/*case 2:
	{
		vector <bool> visited(n + 1);
		int ncomp = 0;
		for (int i = 1; i <= n; ++i)
		{
			if (!visited[i])
			{
				++ncomp;
				dfs2(start, visited, g);
			}
		}
		break;
	}*/
	/*case 3:
	{
		vector <int> color(n + 1);
		for (int i = 1; i <= n; ++i)
		{
			if (color[i] == 0)
			{
				color[i] = 1;
				dfs3(i, color, g);
			}
		}
		break;
	}*/
	/*case 4:
	{
		vector <int> color(n + 1);
		for (int i = 1; i <= n; ++i)
		{
			if (color[i] == 0)
			{
				dfs4(start, color, g);
			}
		}
		break;
	}*/
	/*case 5:
	{
		vector <bool> visited(n + 1);
		vector <int> ans;
		for (int i = 1; i <= n; ++i)
		{
			if (!visited[i])
			{
				dfs5(start, visited, ans, g);
			}
		}
		reverse(ans.begin(), ans.end());
		break;
	}*/
	case 6:
	{
		int k; // стартовая вершина
		cout << "Starting peak: ";
		cin >> k;
		int n = 8; // вершины
		int** grav = new int* [n] {
			new int[n] {0, 1, 0, 0, 0, 0, 1, 0},
				new int[n] {0, 0, 0, 0, 1, 0, 0, 0},
				new int[n] {0, 1, 0, 0, 0, 0, 0, 0},
				new int[n] {0, 0, 0, 0, 0, 0, 0, 0},
				new int[n] {0, 0, 0, 1, 0, 1, 0, 0},
				new int[n] {0, 0, 0, 0, 0, 0, 1, 0},
				new int[n] {0, 0, 0, 0, 0, 0, 0, 1},
				new int[n] {1, 0, 0, 0, 0, 0, 0, 0},
		};
		printgrav(grav, n);
		cout << "Bypass\n";
		dfsDeep(grav, nullptr, 0, n, k);
		cout << "\nÏðîõîä â øèðèíó\n";
		queue<int> q;
		q.push(0);
		break;
	}
	default:
	{
		system("CLS");
		cout << "Some kind of mistake" << endl;
		break;
	}
	}
	/*delete[] visited;
	visited = NULL;
	for (int i = 0; i < n; i++)
	{
		delete[] graph[i];
	}
	delete[] graph;
	graph = NULL;*/
}