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

vector<int> dp(100001),ans;
vector<int> adj[100001];

void solve(vector<int> color, int v, int prev)
{
  dp[v] = 0;
  if (color[v])
    dp[v] = 1;
  for (int x : adj[v])
  {
    if (x != prev)
    {
      solve(color,x,v);
      //cout << v << " and " << x << " " << dp[v] << " " << dp[x] <<  endl;
      dp[v] += dp[x];
    }
  }
  // if (dp[v] == 1)
  //   ans.pb(v);
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n,a,b,c;
  cin >> n;
  vector<int> color(n+1,0);
  fori(i,1,n-1)
  {
    cin >> a >> b >> c;
    adj[a].pb(b);
    adj[b].pb(a);
  //  color[a] = color[b] = c-1;
    if (!color[a])
      color[a] = c-1;
    if (!color[b])
      color[b] = c-1;
  }
  // fori(i,1,n)
  //   cout << i << " and the color is " << color[i] << endl;
  solve(color,1,-1);
  fori(i,1,n)
    if (color[i] && dp[i] == 1)
        ans.pb(i);
  cout << ans.size() << endl;
  for (int x : ans)
    cout << x << " ";
  cout << endl;
  return 0;
}
