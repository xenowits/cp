#include<bits/stdc++.h>
using namespace std;

#define fori(i,a,b) for (long int i = a; i <= b ; ++i)
#define ford(i,a,b) for(long int i = a;i >= b ; --i)
#define mk make_pair
#define mod 1000000007
#define MAXN 1000000
#define pb push_back
#define vec vector<long long int>
#define ll long long
#define rnd mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().count())
#define pi pair<long long int,long long int>
#define sc second
#define fs first

vector<int> adj[1000005];

void graphClear(int n)
{
  fori(i,1,n)
    adj[i].clear();
}

void dfs(int u, vector<bool> &visited, vector<int> &hello)
{
  visited[u] = 1;
  hello.pb(u);
  for (auto x : adj[u])
  {
    if (!visited[x])
      dfs(x,visited,hello);
  }
}

void ansGiver(int a, vector<int> &ans, int sz)
{
    vector<bool> visited(sz+1,0);
    visited[a] = 1;
    ans[a] = 3;
    for (auto x : adj[a])
    {
        vector<int> hello;
        if (!visited[x])
            dfs(x,visited,hello);
        ll sum_of_degrees = 0;
        for(int p : hello)
        {
            sum_of_degrees += adj[p].size();
        }
        ll edges = sum_of_degrees/2;
        if (edges%2 == 0)   //even edges
        {
            for (int p : hello)
                ans[p] = 1;
        }
        else        //odd edges
        {
            for(int p : hello)
                ans[p] = 2;
        }
    }
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  cin >> t;
  while(t--)
  {
    ll n, m, x, y;
    cin >> n >> m;

    fori(i,1,m)
    {
      cin >> x >> y;
      adj[x].pb(y);
      adj[y].pb(x);
    }
    vector<vector<int> > components;
    vector<bool> visited(n+1,0);
    fori(i,1,n)
    {
      if (!visited[i])
      {
        vector<int> hello;
        dfs(i,visited,hello);
        components.pb(hello);
      }
    }
    vector<int> ans(n+1,0);
    ll max_k = 1, no_of_odd_edge_components = 0;
    vector<int> one_odd_edge_component;
    bool done_or_not_done = 0, zero = 0, one = 0;
    vector<bool> degree_parity(n+1,0);
    //there are atmost 3 components
    int cnt = 0;
    for (auto x : components)
    {
      ll sum_of_degrees = 0;
      for (int p : x)
        sum_of_degrees += adj[p].size();

      ll edges = sum_of_degrees/2;
      // cout << edges << " no of edges " << endl;
      if (edges%2 == 0)
        degree_parity[cnt] = 0, zero = 1;
      else
        degree_parity[cnt] = 1, one = 1;
      cnt += 1;
    }
    if (zero&&one)
    {

    }
    else if (zero && !one)
    {
      for (auto x : components)
      {
        for(int p : x)
          ans[p] = 1;
      }
    }
    else if (!zero && one)
    {

    }
    return 0;
}
