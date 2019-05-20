#include<bits/stdc++.h>
using namespace std;

#define fori(i,a,b) for (long int i = a; i <= b ; ++i)
#define ford(i,a,b) for(long int i = a;i >= b ; --i)
#define mk make_pair
#define mod 1000000007
#define pb push_back
#define ll long long
#define rnd mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().count())

void dfs(vector<int> adj[], vector<int> &path, int &indx, vector<bool> &visited, int n, int v)
{
  visited[v] = true;
  path[indx] = v;
  if (adj[v].size() == 1)
  {
    fori(i,0,indx)
      cout << path[i] << " ";
    cout << endl;
    indx -= 1;
    return;
  }
  else
  {
    for (auto x : adj[v])
    {
      if (!visited[x])
      {
        indx += 1;
        dfs(adj,path,indx,visited,n,x);
      }
    }
    indx -= 1;
  }
}

void printPathsDfs(vector<int> adj[], int n)
{
  int indx = 0;
  vector<int> path(n+1,0);
  vector<bool> visited(n+1,false);
  dfs(adj,path,indx,visited,n,1);
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n,a,b;
  cin >> n;
  vector<int> adj[n+1];
  fori(i,1,n-1)
  {
    cin >> a >> b;
    adj[a].pb(b);
    adj[b].pb(a);
  }
  printPathsDfs(adj,n);
  return 0;
}


// 10
// 1 2
// 1 3
// 2 4
// 2 5
// 3 6
// 3 7
// 4 8
// 5 9
// 5 10
