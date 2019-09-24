#include<bits/stdc++.h>
using namespace std;

#define fori(i,a,b) for (int i = a; i <= b ; ++i)
#define ford(i,a,b) for(int i = a;i >= b ; --i)
#define mk make_pair
#define mod 1000000007
#define pb push_back
#define ll long long
#define MAXN 300005
#define rnd mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().cnt())
#define pi pair<long long int,long long int>
#define sc second
#define fs first

vector<ll> adj[MAXN];
vector<ll> parent(MAXN,0),v1,v2;
vector<bool> visited(MAXN,0);

void construct()
{
  queue<int> q;
  q.push(1);
  visited[1] = 1;
  while (!q.empty())
  {
    int t = q.front();
    //cout << t << " ";
    q.pop();
    for(auto x : adj[t])
    {
      if (!visited[x])
      {
        q.push(x);
        visited[x] = 1;
        parent[x] = t;
      }
    }
  }
  //cout << endl;
}

int sizeCalc(int pos, int n)
{
  vector<bool> vis(n+1,0);
  queue<int> q;
  q.push(pos);
  vis[pos] = 1;
  int ans = -1;
  while (!q.empty())
  {
    int t = q.front();
    ans += 1;
    q.pop();
    for(auto x : adj[t])
    {
      if (!vis[x] && parent[x] == t)
      {
        q.push(x);
        vis[x] = 1;
      }
    }
  }
  return ans;
}

int main()
{

  ll n,x,y,a,b;
  cin >> n >> x >> y;

  for(int i = 0 ; i<n-1; ++i)
  {
    cin >> a >> b;
    adj[a].pb(b);
    adj[b].pb(a);
  }

  // lets root the tree at 1
  construct();

  ll tx = x, ty = y;
  while (tx != 0)
  {
    v1.pb(tx);
    tx = parent[tx];
    //cout << tx << endl;
  }
  while (ty != 0)
  {
    v2.pb(ty);
    ty = parent[ty];
    //cout << ty << endl;
  }

  reverse(v1.begin(),v1.end());
  reverse(v2.begin(),v2.end());
  ll lca=1;

  for (int i = 0; i < min(v1.size(), v2.size()); ++i)
  {
  //  cout << i << " " << v1[i] << " " << v2[i] << endl;
    if (v1[i] != v2[i])
      break;
    lca = v1[i];
  }
//  cout << "lca is " << lca << endl;
  ll sx = sizeCalc(x,n), sy = sizeCalc(y,n);
//  cout << sx << " sizes " << sy << endl;

  if (lca == x)
  {
    ty = y;
    while (parent[ty] != lca)
      ty = parent[ty];

    ll sxh = sizeCalc(ty,n)+1;

    //cout << p << " " << sxh << " " << sy << endl;
    ll ans = n*(n-1) - (n-sxh)*(sy+1);
    cout << ans << endl;
  }

  else if (lca == y)
  {
    tx = x;
    while (parent[tx] != lca)
      tx = parent[tx];

    int syh = sizeCalc(tx,n)+1;

    ll ans = n*(n-1) - (n-syh)*(sx+1);
    cout << ans << endl;
  }

  else
  {
    ll ans = n*(n-1) - (sx+1)*(sy+1);
    cout << ans << endl;
  }

  return 0;
}
