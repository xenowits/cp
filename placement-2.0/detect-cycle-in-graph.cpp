//IN DIRECTED GRAPH - DON'T ADD parent[src] != x CONDITION [ LINE 9]
//IN UNDIRECTED GRAPH - ADD ABOVE

void dfs(int src, vector<int> &color, vector<int> adj[], vector<int> &parent, bool &flag) {
    if (flag) {
        return;
    }
    color[src] = 1; //JUST DISCOVERED
    for (auto x : adj[src]) {
        if (color[x] == 1 && (parent[src] != x)) {
            // parent[x] = src;
            //BACK EDGE - CYCLE
            flag = true;
        } else if (color[x] == 0) {
            parent[x] = src;
            dfs(x, color, adj, parent, flag);
        } else if (color[x] == 2) {
            //DO NOTHING - ALREADY KAAM TAMAM
        }
    }
    //ALL DONE
    color[src] = 2;
}

bool isCyclic(vector<int> adj[], int V) {
    //DIRECTED GRAPH + UNDIRECTED GRAPH
    //graph may be disconnected - FOREST
    vector<int> color(V, 0), parent(V, -1);    //NONE ARE VISITED SO FAR
    bool cycleExists = false;
    bool flag = false;

    for (int i = 0; i < V; i += 1) {
        if (color[i] == 0) {
            dfs(i, color, adj, parent, flag);
            if (flag) {
                return true;
            }
        }
    }
    return false;
}
