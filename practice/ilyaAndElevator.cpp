#include<bits/stdc++.h>
using namespace std;

#define fori(i,a,b) for (long long int i = a; i <= b ; ++i)
#define ford(i,a,b) for(long long int i = a;i >= b ; --i)
#define mk make_pair
#define mod 998244353
#define pb push_back
#define ll long long
#define ld long double
#define MAXN (ll)1e6+5
#define rnd mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().cnt())
#define pi pair<long long int,long long int>
#define sc second
#define fs first

ld dp[2005][2005];
//dp(i,j) is the prob. that after i seconds j people
//are on the elevator

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  ll n, t;
  ld p;

  cin >> n >> p >> t;
  dp[0][0] = 1;

  fori(i,0,t)
  {
    fori(j,0,n)
    {
      // i seconds k baad j log elevator m khade h
      if (j == n)
      {
        dp[i+1][j] += dp[i][j];
      }
      else
      {
        dp[i+1][j+1] += dp[i][j]*p;
        dp[i+1][j] += dp[i][j]*(1-p);
      }
      //cout << i << " " << j << " " << dp[i][j] << endl;
    }
  }

  ld ans = 0;

  fori(i,0,n)
  {
    ans += dp[t][i]*i;
  }

  cout << fixed << setprecision(14) << ans << endl;

  return 0;
}
