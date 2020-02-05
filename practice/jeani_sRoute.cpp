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

vector<pi> adj[25];
ll cnt = 0;
set<ll> k_set;

// void dfs(int v, vector<bool> &visited)
// {
//   visited[v] = true;
//   cout << v << " ";
//   for (auto x : adj[v])
//   {
//     if (!visited[x])
//       dfs(x,visited);
//   }
// }

void Dfs(int v, vector<bool> &visited)
{
  visited[v] = true;
  //cout << v << " ";
  for (auto x : adj[v])
  {
    if (!visited[x.first])
    {
      if (k_set.count(x.first) != 0)
      {
        cnt += 2*x.second;
        cout << x.first << " " << x.second <<  " cnt uptill now " << cnt << endl;
      }
      Dfs(x.first,visited);
    }
  }
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n,a,b,c,k;
  cin >> n >> k;
  fori(i,1,k)
  {
    cin >> a;
    k_set.insert(a);
  }
  fori(i,1,n-1)
  {
    cin >> a >> b >> c;
    adj[a].pb(mk(b,c));
    adj[b].pb(mk(a,c));
  }
  vector<bool> visited(n+1,false);
  //dfs(1,visited);
  Dfs(*k_set.begin(),visited);
  cout << endl << cnt << endl;
  return 0;
}
