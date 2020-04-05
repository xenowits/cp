//xenowitz -- Jai Shree Ram
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

int dp[2005][2005];

ll binpow(ll a, ll b) {
    ll res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  ll n, m, k;
  cin >> n >> m >> k;

  //dp(i,j) ==> there are j special bricks(to whose left color is different)
  //among the first i elements

  // fori(i,0,k) {
  //   dp[1][i] = m;
  // }

  dp[1][0] = m;

  fori(i,2,n) {
    fori(j,0,k) {
      dp[i][j] = ((dp[i-1][j-1]*(m-1))%mod + dp[i-1][j])%mod;
      // cout << i << " " << j << " " << dp[i][j] << endl;
    }
  }

  cout << dp[n][k] << endl;
	return 0;
}
