#include<bits/stdc++.h>
using namespace std;

#define fori(i,a,b) for (int i = a; i <= b ; ++i)
#define ford(i,a,b) for(int i = a;i >= b ; --i)
#define mk make_pair
#define mod 1000000007
#define pb push_back
#define ll long long

void dfs(vector<int> v[], vector<bool> &visited, vector<int> &path, int path_index, int src ,int dest, int n)
{
  visited[src] = true;
  path[path_index] = src;
  path_index += 1;
  if (src == dest)
  {
    for(int i = 0 ; i < path_index; ++i)
      cout << path[i] << " ";
    cout << endl;
  }
  else
  {
    for (auto x : v[src])
    {
      if (!visited[x])
        dfs(v,visited,path,path_index,x,dest,n);
    }
  }
  path_index -= 1;
  visited[src] = false;
}

void printPaths(vector<int> v[], int n, int src, int dest)
{
  vector<bool> visited(n,false);
  vector<int> path(n);
  int path_index = 0;
  dfs(v, visited, path, path_index,src,dest, n);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,e,a,b;
    cout << "enter nodes and edges: " << endl;
    cin >> n >> e;
    vector<int> v[n];
    fori(i,1,e)
    {
      cin >> a >> b;
      v[a].pb(b);
    }
    int src,dest;
    cout << "enter source and destination:" << endl;
    cin >> src >> dest;
    printPaths(v,n,src,dest);
    return 0;
}
