#include <iostream>
#include <string.h>
#include <algorithm>
#include <list>
using namespace std;

class Graph
{
    int V;
    list<int> *adj;
    public:

    Graph(int V) { this->V = V; adj = new list<int>[V]; }
    ~Graph()	 { delete [] adj; }

    void addEdge(int u, int v) { adj[u].push_back(v); adj[v].push_back(u); }
    void rmvEdge(int u, int v);

    void printEulerTour();
    void printEulerUtil(int s);
    int DFSCount(int v, bool visited[]);

	int isEulerian();

	bool isConnected();

	void DFSUtil(int v, bool visited[]);

    bool isValidNextEdge(int u, int v);
};

void Graph::printEulerTour()
{
    // Find a vertex with odd degree
    int u = 0;
    for (int i = 0; i < V; i++)
        if (adj[i].size() & 1)
            { u = i; break; }

    printEulerUtil(u);
    cout << endl;
}

// Print Euler tour starting from vertex u
void Graph::printEulerUtil(int u)
{
    // Recur for all the vertices adjacent to this vertex
    list<int>::iterator i;
    for (i = adj[u].begin(); i != adj[u].end(); ++i)
    {
        int v = *i;
        if (v != -1 && isValidNextEdge(u, v))
        {
            cout << u << "-" << v << " ";
            rmvEdge(u, v);
            printEulerUtil(v);
        }
    }
}

bool Graph::isValidNextEdge(int u, int v)
{

    // 1) If v is the only adjacent vertex of u
    int count = 0; // To store count of adjacent vertices
    list<int>::iterator i;
    for (i = adj[u].begin(); i != adj[u].end(); ++i)
        if (*i != -1)
            count++;
    if (count == 1)
        return true;
    bool visited[V];
    memset(visited, false, V);
    int count1 = DFSCount(u, visited);
    rmvEdge(u, v);
    memset(visited, false, V);
    int count2 = DFSCount(u, visited);
    addEdge(u, v);

    return (count1 > count2)? false: true;
}

void Graph::rmvEdge(int u, int v)
{
    list<int>::iterator iv = find(adj[u].begin(), adj[u].end(), v);
    *iv = -1;

    list<int>::iterator iu = find(adj[v].begin(), adj[v].end(), u);
    *iu = -1;
}

// A DFS based function to count reachable vertices from v
int Graph::DFSCount(int v, bool visited[])
{
    visited[v] = true;
    int count = 1;

    list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
        if (*i != -1 && !visited[*i])
            count += DFSCount(*i, visited);

    return count;
}

void Graph::DFSUtil(int v, bool visited[])
{
	visited[v] = true;
	list<int>::iterator i;
	for (i = adj[v].begin(); i != adj[v].end(); ++i)
		if (!visited[*i])
			DFSUtil(*i, visited);
}

bool Graph::isConnected()
{
	bool visited[V];
	int i;
	for (i = 0; i < V; i++)
		visited[i] = false;

	for (i = 0; i < V; i++)
		if (adj[i].size() != 0)
			break;
	if (i == V)
		return false;

	DFSUtil(i, visited);
	for (i = 0; i < V; i++)
	if (visited[i] == false && adj[i].size() > 0)
			return false;

	return true;
}
/*
0 --> If grpah is not Eulerian
1 --> If graph has an Euler path (Semi-Eulerian)
2 --> If graph has an Euler Circuit (Eulerian) */
int Graph::isEulerian()
{
	if (isConnected() == false)
		return 0;
	int odd = 0;
	for (int i = 0; i < V; i++)
		if (adj[i].size() & 1)
			odd++;

	if (odd > 2)
		return 0;

	return (odd)? 1 : 2;
}

void test(Graph &g)
{
	int res = g.isEulerian();
	if (res == 0)
		cout << "graph is not Eulerian\n";
	else if (res == 1)
		cout << "graph has a Euler path\n";
	else
		cout << "graph has a Euler cycle\n";
}

int main()
{
	Graph g1(5);
	g1.addEdge(1, 0);
	g1.addEdge(0, 2);
	g1.addEdge(2, 1);
	g1.addEdge(0, 3);
	g1.addEdge(3, 4);
	test(g1);
	g1.printEulerTour();

	Graph g2(5);
	g2.addEdge(1, 0);
	g2.addEdge(0, 2);
	g2.addEdge(2, 1);
	g2.addEdge(0, 3);
	g2.addEdge(3, 4);
	g2.addEdge(4, 0);
	test(g2);
	g2.printEulerTour();

	Graph g3(5);
	g3.addEdge(1, 0);
	g3.addEdge(0, 2);
	g3.addEdge(2, 1);
	g3.addEdge(0, 3);
	g3.addEdge(3, 4);
	g3.addEdge(1, 3);
	test(g3);

	Graph g4(3);
	g4.addEdge(0, 1);
	g4.addEdge(1, 2);
	g4.addEdge(2, 0);
	test(g4);
	g4.printEulerTour();

	Graph g5(3);
	test(g5);

	return 0;
}
