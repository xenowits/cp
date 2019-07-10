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

vector<int> adj[25];
ll temp = -1;
vector<int> parent(135);

void dfs(int v, vector<bool> &visited)
{
  visited[v] = true;
  cout << v << " ";
  for (auto x : adj[v])
  {
    if (!visited[x])
    {
      parent[x] = v;
      dfs(x,visited);
    }
  }
  cout << parent[v] << " ";
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n,a,b;
  cin >> n;
  fori(i,1,n-1)
  {
    cin >> a >> b;
    adj[a].pb(b);
    adj[b].pb(a);
  }
  vector<bool> visited(n+1,false);
  dfs(1,visited);
  return 0;
}
/*
14
1 2
2 3
2 4
3 5
3 10
4 6
4 7
4 8
4 9
10 14
10 13
10 12
10 11
*/
