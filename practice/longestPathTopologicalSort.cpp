#include<bits/stdc++.h>
using namespace std;

#define fori(i,a,b) for (long int i = a; i <= b ; ++i)
#define ford(i,a,b) for(long int i = a;i >= b ; --i)
#define mk make_pair
#define mod 1000000007
#define pb push_back
#define ll long long
#define rnd mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().count())
#define MAX 1001

int adj[MAX][MAX];

void dfs(int node, vector<int> adj[], int dp[], bool vis[])
{
    // Mark as visited
    vis[node] = true;

    // Traverse for all its children
    for (int i = 0; i < adj[node].size(); i++) {

        // If not visited
        if (!vis[adj[node][i]])
            dfs(adj[node][i], adj, dp, vis);

        // Store the max of the paths
        dp[node] = max(dp[node], 1 + dp[adj[node][i]]);
    }
}

// Function that returns the longest path
int findLongestPath(vector<int> adj[], int n)
{
    // Dp array
    int dp[n + 1];
    memset(dp, 0, sizeof dp);

    // Visited array to know if the node
    // has been visited previously or not
    bool vis[n + 1];
    memset(vis, false, sizeof vis);

    // Call DFS for every unvisited vertex
    for (int i = 1; i <= n; i++) {
        if (!vis[i])
            dfs(i, adj, dp, vis);
    }

    int ans = 0;

    // Traverse and find the maximum of all dp[i]
    for (int i = 1; i <= n; i++) {
        ans = max(ans, dp[i]);
    }
    return ans;
}

// ll longestPath(vector<int> adj[], int n)
// {
//
// }

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  vector<int> per[10];
  int n,e,a,b;
  cin >> n >> k;
  fori(i,1,k)
  {
    fori(j,1,n)
    {
        cin >> a;
        per[i].pb(a);
    }
  }

  fori(i,0,n-2)
  {
    fori(j,i+1,n-1)
    {
      int temp = per[1][j];
      adj[i+1].pb(temp);
      adj[i+1][temp] = 1;
    }
  }
  fori(y,2,k)
  {
    fori(i,0,n-2)
    {
      fori(j,i+1,n-1)
      {
        int temp = per[y][j];
        if (adj[temp][i+1])
          adj[temp][i+1] = 0;
      }
    }
  }
  cout << findLongestPath(adj,n);
  return 0;
}
