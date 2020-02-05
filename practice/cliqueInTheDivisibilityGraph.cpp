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

ll dp[MAXN];

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  ll n;
  cin >> n;

  vector<ll> v(n+1);
  fori(i,1,n) {
    cin >> v[i];
    dp[v[i]] = 1;
  }
  fori(i,1,n) {
    for(int j = 2*v[i]; j <= MAXN; j+=v[i]) {
      dp[j] = max(dp[j], dp[v[i]]+1);
      //cout << dp[i] << " " << dp[j] << endl;
    }
  }
  ll ans = 0;
  fori(i,1,n) {
    //cout << dp[v[i]] << " ";
    ans = max(ans, dp[v[i]]);
  }

  cout << ans << endl;

  return 0;
}
