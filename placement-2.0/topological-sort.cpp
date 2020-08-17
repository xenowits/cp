//TOP OF STACK CONTAINS THE ELEMENT WITH THE "HIGHEST FINISHING TIME"
// TOPOLOGICAL -SORT(G)
// 1 call DFS.G/ to compute finishing times :f for each vertex 
// 2 as each vertex is finished, insert it onto the front of a linked list
// 3 return the linked list of vertices

void dfs(int src, vector<bool> &visited, vector<int> adj[], stack<int> &stk) {
    visited[src] = true;
    for (auto x : adj[src]) {
        if (!visited[x]) {
            dfs(x, visited, adj, stk);
        }
    }
    stk.push(src);
}

vector<int> topoSort(int V, vector<int> adj[]) {
    vector<int> ans;
    vector<bool> visited(V, false);
    stack<int> stk;

    for (int i = 0; i < V; i += 1) {
        if (!visited[i]) {
            dfs(i, visited, adj, stk);
        }
    }

    while (!stk.empty()) {
        ans.push_back(stk.top());
        stk.pop();
    }

    return ans;
}
