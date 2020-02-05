#include<bits/stdc++.h>
using namespace std;

#define fori(i,a,b) for (long long int i = a; i <= b ; ++i)
#define ford(i,a,b) for(long long int i = a;i >= b ; --i)
#define mk make_pair
#define mod 998244353
#define pb push_back
#define ll long long
#define ld long double
#define MAXN (ll)1e5+5
#define rnd mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().cnt())
#define pi pair<long long int,long long int>
#define sc second
#define fs first

vector<ll> adj[MAXN];
vector<ll> sz(MAXN,0);

void noOfLeaves(int u, int par = -1)
{
  if (adj[u].size() == 1)
  {
    sz[u] = 1;
    return;
  }
  for (auto x : adj[u])
  {
    if (x == par)
      continue;
    noOfLeaves(x,u);
    sz[u] += sz[x];
  }
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  ll n, u;
  cin >> n;

  fori(i,2,n)
  {
    cin >> u;
    adj[i].pb(u);
    adj[u].pb(i);
  }

  noOfLeaves(1);
  map<ll,ll> mp;

  fori(i,1,n)
  {
    if (sz[i] != 0)
      mp[sz[i]] += 1;
  }

  for(auto x : mp)
  {
    auto cnt = x.sc;
    fori(i,1,cnt)
      cout << x.fs << " ";
  }

  return 0;
}
