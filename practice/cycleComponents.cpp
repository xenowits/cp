#include<bits/stdc++.h>
using namespace std;

#define MAXN 200005
#define ll long long int
#define pb push_back

vector<int> adj[MAXN];
vector<bool> visited(MAXN);

bool flag = 1;

void dfs(int u)
{
  visited[u] = 1;
  // cout << u << " and degree " << adj[u].size() << " ";
  if (adj[u].size() != 2)
     flag = 0;
  for(auto x : adj[u])
  {
    if (!visited[x])
    {
      dfs(x);
    }
  }
}

int main()
{
  ll n,e,x,y;
  cin >> n >> e;
  for(int i = 1; i <= e; ++i)
  {
    cin >> x >> y;
    adj[x].pb(y);
    adj[y].pb(x);
  }

  ll total_count = 0;

  for(int i = 1; i <= n; ++i)
  {
    if (!visited[i])
    {
      flag = 1;
      dfs(i);
      if (flag){total_count += 1;}
        //total_count += 1;
      //cout << "done" << endl << endl;
    }
  }

  cout << total_count << endl;

  return 0;
}
