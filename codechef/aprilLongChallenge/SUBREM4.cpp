#include<bits/stdc++.h>
using namespace std;

#define fori(i,a,b) for (int i = a; i <= b ; ++i)
#define ford(i,a,b) for(int i = a;i >= b ; --i)
#define mk make_pair
#define mod 1000000007
#define pb push_back

long int profit = 0,X;

long dfs(int v,vector<bool> &visited, vector<int> nodes[], vector<int> &values)
{
  visited[v] = true;
  long sum = 0;
  for (auto x : nodes[v])
  {
    if (!visited[x])
    {
        sum += dfs(x,visited,nodes,values);
    }
  }
  sum += values[v];
  if (sum + X >= 0)
  {
    return sum;
  }
  else
    return -X;
}

void solve(int n, vector<int> nodes[], vector<int> values)
{
  vector<bool> visited(n+1,false);
  long final = dfs(1,visited,nodes,values);
  cout << final;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t,n,u,v;
  cin >> t;
  while (t>0)
  {
    cin >> n >> X;
    vector<int> nodes[n+1];
    vector<int> values(n+1);
    fori(i,1,n)
    {
      cin >> values[i];
    }
    fori(i,1,n-1)
    {
      cin >> u >> v;
      nodes[u].pb(v);
      nodes[v].pb(u);
    }
    solve(n,nodes,values);
    t-=1;
    if (t>0)
      cout << "\n";
  }
  return 0;
}


// 1
// 11 2
// 5 -10 4 7 7 -4 3 -10 8 -5 -1
// 1 2
// 1 3
// 1 4
// 2 5
// 5 6
// 5 7
// 2 8
// 3 9
// 3 10
// 4 11
