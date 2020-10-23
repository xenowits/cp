//xenowitz -- Jai Shree Ram
#include<bits/stdc++.h>
using namespace std;

#define fori(i,a,b) for (long int i = a; i <= b ; ++i)
#define ford(i,a,b) for(long int i = a;i >= b ; --i)
#define mk make_pair
#define mod 998244353
#define pb push_back
#define eb emplace_back
#define vec vector<long long int>
#define ll long long
#define rnd mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().count())
#define pi pair<long long int,long long int>
#define sc second
#define fs first
#define stf shrink_to_fit

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  ll n, k, l, r;
  cin >> n >> k;

  vector<pair<ll,ll> > v;
  fori(i,1,k) {
      cin >> l >> r;
      v.pb(mk(l, r));
  }

  vector<ll> dp(410005, 0);
  dp[1] = 1;

  fori(i, 1, n) {
     dp[i] = (dp[i] + dp[i-1])%mod;
     for (auto x : v) {
         arr[i+x.fs] = (dp[i] + arr[i+x.fs])%mod;
         arr[i+x.sc+1] = (-dp[i] + arr[i+x.sc+1])%mod;
     }
  }

  cout << dp[n]%mod << endl;

  return 0;
}
