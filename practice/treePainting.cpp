#include<bits/stdc++.h>
using namespace std;

#define fori(i,a,b) for (long long int i = a; i <= b ; ++i)
#define ford(i,a,b) for(long long int i = a;i >= b ; --i)
#define mk make_pair
#define mod 998244353
#define pb push_back
#define ll long long
#define ld long double
#define MAXN 2*(ll)1e5+5
#define rnd mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().cnt())
#define pi pair<long long int,long long int>
#define sc second
#define fs first

vector<ll> adj[MAXN];
ll ans = INT_MIN;
vector<ll> sz(MAXN,0);
vector<ll> dp(MAXN,-1);

void calcSubtreeSize(int u, int par = -1)
{
  sz[u] = 1;
  for (auto x : adj[u])
  {
    if (x == par)
      continue;
    calcSubtreeSize(x,u);
    sz[u] += sz[x];
  }
}

void calcDP(int u, int par = -1)
{
  dp[u] = sz[u];
  for (auto x : adj[u])
  {
    if (x == par)
      continue;
    calcDP(x,u);
    dp[u] += dp[x];
  }
}

void dfs(int v, int par = -1)
{
  ans = max(ans,dp[v]);
  for (auto to : adj[v])
  {
    if (to == par)
      continue;

    dp[v] -= sz[to];
    dp[v] -= dp[to];
    sz[v] -= sz[to];

    sz[to] += sz[v];
    dp[to] += dp[v];
    dp[to] += sz[v];

    dfs(to,v);

    dp[to] -= sz[v];
    dp[to] -= dp[v];
    sz[to] -= sz[v];

    sz[v] += sz[to];
    dp[v] += dp[to];
    dp[v] += sz[to];
  }
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  ll n, u, v;
  cin >> n;

  fori(i,1,n-1)
  {
    cin >> u >> v;
    adj[u].pb(v);
    adj[v].pb(u);
  }

  calcSubtreeSize(1);
  calcDP(1);
  dfs(1);

  cout << ans << endl;

  return 0;
}
