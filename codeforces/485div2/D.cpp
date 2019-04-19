#include<bits/stdc++.h>
using namespace std;

#define fori(i,a,b) for (long int i = a; i <= b ; ++i)
#define ford(i,a,b) for(long int i = a;i >= b ; --i)
#define mk make_pair
#define mod 1000000007
#define pb push_back
#define ll long long

void solve(vector<int> graph[], vector<int> arr, int n, int m, int k, int s)
{
  fori(i,1,n)
  {
    vector<bool> visited(n+1,false);
    vector<int> goods(k+1,0);
    vector<int> dist(n+1,0);
    vector<int> parent(n+1);
    queue<int> q;
    q.push(i);
    visited[i] = true;
    goods[arr[i]] = true;
    int gCount = 0,total_dist = 0;
    parent[i] = 0;
    while (!q.empty())
    {
      int temp = q.front();
      q.pop();
      if (goods[arr[temp]] == 1)
      {
          gCount += 1, total_dist += dist[temp];
      }
      if (gCount == s)
        break;
      for (auto x : graph[temp])
      {
        if (!visited[x])
        {
          visited[x] = true;
          q.push(x);
          dist[x] = 1 + dist[temp];
          goods[arr[x]] += 1;
        }
      }
    }
    cout << total_dist << " ";
  }
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n,m,k,s,a,b;
  cin >> n >> m >> k >> s;
  vector<int> arr(n+1);
  fori(i,1,n)
    cin >> arr[i];
  vector<int> graph[n+1];
  fori(i,1,m)
  {
    cin >> a >> b;
    graph[a].pb(b);
    graph[b].pb(a);
  }
  solve(graph,arr,n,m,k,s);
  return 0;
}
