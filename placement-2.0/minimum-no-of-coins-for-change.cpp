class Solution {
public:
    int coinChange(vector<int>& coins, int v) {
    vector<int> visited(v+1, -1);
    queue<int> q;
    q.push(v);
    visited[v] = 0;
    int cnt = 1, n = coins.size();

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        // cout << u << " " << visited[u] << endl;
        for (int i = 0; i < n; i += 1) {
            if (u - coins[i] >= 0 && visited[u-coins[i]] == -1) {
                // cout << (u - coins[i]) << " " << (1 + visited[u]) << endl;
                visited[u - coins[i]] = 1 + visited[u];
                q.push(u-coins[i]);
            }
        }
        if (visited[0] != -1) {
            return visited[0];
        }
    }

    return visited[0];
    }
};
