#include<bits/stdc++.h>
using namespace std;

#define fori(i,a,b) for (int i = a; i <= b ; ++i)
#define ford(i,a,b) for(int i = a;i >= b ; --i)
#define mk make_pair
#define mod 1000000007
#define pb push_back
#define ll long long
#define MAXN 100001
#define rnd mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().cnt())
#define pi pair<long long int,long long int>
#define fs first
#define sc second

vector<int> adj[MAXN];
vector<bool> visited(MAXN,0);
vector<int> parent(MAXN,-1), level(MAXN,0);
ll dp[MAXN][50];

void dfs(int u)
{
  if (!visited[u])
    visited[u] = 1;

  for(auto v : adj[u])
  {
    if (!visited[v])
    {
      parent[v] = u;
      level[v] = level[u]+1;
      dfs(v);
    }
  }

}

void preprocess(ll n)
{

  fori(i,1,n)
  {
    for(int j = 0 ; (1<<j) < n; ++j)
    {
      dp[i][j] = -1;
    }
  }

  fori(i,1,n)
    dp[i][0] = parent[i];

  for(int j = 1; (1<<j) < n; ++j)
  {
    for(int i = 1; i <= n; ++i)
    {
      if (dp[i][j-1] != -1)
        dp[i][j] = dp[dp[i][j-1]][j-1];
    }
  }

}

int LCA(int a, int b, ll n)
{
  if (level[a] < level[b])
    swap(a,b);

  int dist = level[a]-level[b];

  while (dist>0)
  {
    int raise_by = log2(dist);
    a = dp[a][raise_by];
    dist -= (1<<raise_by);
  }

  if (a == b)
    return a;

  for(int j = log2(n); j >= 0; j-=1)
  {
    if ( (dp[a][j] != -1) && (dp[a][j] != dp[b][j]))
    {
      a = dp[a][j];
      b = dp[b][j];
    }
  }

  return parent[a];

}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll n,a,b;
  cin >> n;

  fori(i,1,n-1)
  {
    cin >> a >> b;
    adj[a].pb(b);
    adj[b].pb(a);
  }

  dfs(1);

  preprocess(n);

  ll q;
  cin >> q;
  while (q--)
  {
    cin >> a >> b;
    cout << LCA(a,b,n) << endl;
  }

  return 0;
}

/*
14
1 2
1 3
2 4
2 5
5 6
5 7
5 8
8 13
6 9
6 10
6 11
6 12
12 14
*/
