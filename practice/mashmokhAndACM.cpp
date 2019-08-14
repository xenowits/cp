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
#define sc second
#define fs first

int dp[2001][2001];

vector<long> divs[2001];

void construct(int n)
{
  for(int i = 1; i <= n; ++i)
  {
    for (int p = 1; p <= (long)sqrt(i); ++p)
    {
      if (i%p == 0)
      {
        if (i/p == p)
          divs[i].pb(p);
        else
          divs[i].pb(p), divs[i].pb(i/p);
      }
    }
    // for(auto x : divs[i])
    //   cout << x << " ";
    // cout << endl;
  }
}

int main()
{
  int n,k;
  cin >> n >> k;
  construct(n);
  for (int i = 1; i <= k; ++i)
  {
    for (int j = 1; j <= n; ++j)
    {
      dp[i][j] = 0;
      if (i == 1)
        dp[i][j] = 1;
      else
      {
        for (auto x : divs[j])
          dp[i][j] = (dp[i][j] + dp[i-1][x])%mod;
      }
    }
  }
  ll ans = 0;
  for (int i = 1; i <= n; ++i)
    ans += dp[k][i]%mod, ans = ans%mod;
  cout << ans << endl;
  return 0;
}
