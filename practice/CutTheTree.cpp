#include<bits/stdc++.h>
using namespace std;

#define fori(i,a,b) for (long int i = a; i <= b ; ++i)
#define ford(i,a,b) for(long int i = a;i >= b ; --i)
#define mk make_pair
#define mod 1000000007
#define pb push_back
#define ll long long
#define rnd mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().count())

// void dfsUtil
//
// void dfs(vector<int> sumOfSubtree,vector<int> tree[], vector<int> data, vector<bool> visited)
// {
//   dfsUtil(1,sumOfSubtree,tree,data,visited);
// }
vector<int> data(10001);
vector<int> parent(100001,0);
vector<int> dist(100001,0);

void dfsUtil(int v, int d, vector<bool> visited, vector<int> tree[])
{
  visited[v] = true;
  //cout << v << " ";
  d += 1;
  for (auto i = tree[v].begin(); i != tree[v].end(); ++i)
  {
    if (!visited[*i])
    {
      parent[*i] = v;
      // if (parent[*i] == v)
      //   cout << *i << " " << v << " done" << endl;
      dist[*i] = d;
      dfsUtil(*i,d,visited,tree);
    }
  }
}

void dfs(int n, vector<int> tree[])
{
  vector<bool> visited(n+1,false);
  int d = 0;
  dfsUtil(1, d, visited, tree);
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n,a,b;
  cin >> n;
  //vector<int> data(n+1);
  fori(i,1,n)
    cin >> data[i];
  vector<int> tree[n+1];
  fori(i,1,n-1)
  {
    cin >> a >> b;
    tree[a].pb(b);
    tree[b].pb(a);
  }
  dfs(n,tree);
  //cout << endl;
  vector<pair<int,int> > disVer;
  fori(i,1,n)
  {
    //cout << i << " " << parent[i] << " dist from root " << dist[i] << endl;
    disVer.pb(mk(dist[i],i));
  }
  sort(disVer.begin(), disVer.end(), [] (pair<int,int> a, pair<int,int> b) -> bool
  {
      return a.first > b.first;
  });
  vector<int> sum = data;
  for(auto x : disVer)
  {
    int temp = parent[x.second];
    sum[temp] += sum[x.second];
    //cout << x.first << " " << x.second << endl;
  }
  // fori(i,1,n)
    //cout << i << " " << parent[i] << " " << sum[i] << endl;
  ll total = sum[1];
  vector<int> adj[100007];
  fori(i,1,n)
    adj[parent[i]].pb(i);
  //cout << endl;
  int ans = INT_MAX;
  fori(i,1,n)
  {
    for(auto x = adj[i].begin() ; x != adj[i].end(); ++x)
    {
      if (*x>0)
      {
        int a = abs(total-2*sum[*x]);
        //cout << i << " " << *x << " " << a << endl;
        ans = min(ans,a);
      }
    }
  }
  cout << ans << endl;
  return 0;
}
