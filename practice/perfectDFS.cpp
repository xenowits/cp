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
vector<int> color(MAXN), discovery(MAXN), finish(MAXN), parent(MAXN);
ll t;
bool cyclesPresent = 0;

void dfs(int u)
{
  t+=1;
  discovery[u] = t;
  color[u] = 1;
  //cout << u << endl;
  for(auto x : adj[u])
  {
    if (color[x] == 1)
      cyclesPresent = 1;
    if (color[x] == 0)
    {
      parent[x] = u;
      dfs(x);
    }
  }
  t+=1;
  color[u] = 2;
  finish[u] = t;
}

void dfsUtil(int u)
{
  if (color[u] == 0)
    dfs(u);
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll n,e,a,b;
  cin >> n >> e;
  t = 0;
  fori(i,1,e)
  {
    cin >> a >> b;
    adj[a].pb(b);
    adj[b].pb(a);
  }
  dfsUtil(1);
  if (cyclesPresent)
    cout << "cycle is present in the graph" << endl;
  return 0;
}
