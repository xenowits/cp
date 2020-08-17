#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

vector<int> adj[8];

void bfs(int src) {
	queue<int> q;
	q.push(src);
	
	vector<bool> visited(11,false);
	visited[src] = true;

	while (!q.empty()) {
		int t = q.front();
		q.pop();

		cout << t << " ";
		for (auto x : adj[t]) {
			if (!visited[x]) {
				visited[x] = true;
				q.push(x);
			}
		}
	}
}

void dfs(int src, vector<bool> &visited) {
	visited[src] = true;
	cout << src << " ";

	for (auto x : adj[src]) {
		if (!visited[x]) {
			dfs(x,visited);
		}
	}
}

int main() {
	int a, b;
	for (int i = 0; i < 4; i += 1) {
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	bfs(1);
	cout << endl;
	vector<bool> visited(10,false);
	dfs(1, visited);
}
