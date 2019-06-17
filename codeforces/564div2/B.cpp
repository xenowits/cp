#include<bits/stdc++.h>
using namespace std;

#define fori(i,a,b) for (long int i = a; i <= b ; ++i)
#define ford(i,a,b) for(long int i = a;i >= b ; --i)
#define mk make_pair
#define mod 1000000007
#define pb push_back
#define ll long long
#define rnd mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().count())
#define pi pair<int,int>

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int queries,u,v;
  cin >> queries;
  while(queries>0)
  {
    int n,m,s;
    cin >> n >> m;
    vector<int> adj[n+1];
    fori(i,1,m)
    {
      cin >> u >> v;
      adj[u].pb(v);
      adj[v].pb(u);
    }
    cin >> s;
    vector<int> dist(n+1,-1);
    queue<int> q;
    vector<bool> visited(n+1,false);
    visited[s] = true;
    q.push(s);
    dist[s] = 0;
    while (!q.empty())
    {
      int x = q.front();
      q.pop();
      for(auto a : adj[x])
      {
        if (!visited[a])
        {
          visited[a] = true;
          dist[a] = 1+dist[x];
          q.push(a);
        }
      }
    }
    fori(i,1,n)
    {
      if (i == s)
        continue;
      else if (dist[i] != -1)
        cout << 6*dist[i] << " ";
      else
        cout << dist[i] << " ";
    }
    cout << endl;
    queries-=1;
  }
  return 0;
}
