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


int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  ll l, r, x;
  cin >> n >> l >> r >> x;

  vector<ll> c(n+1,0);
  fori(i,0,n-1) {
    cin >> c[i];
  }

  ll cnt = (1 << n);
  ll ans = 0;
  // cout << cnt << endl;
  for (int i = 0; i < cnt; i++) {
    ll maxu = INT_MIN, minu = INT_MAX, sum = 0;
    for (int j = 0; j < n; j++) {
      if ((i & (1 << j)) > 0) {
        //jth bit is set in i
        // cout << i << " dfg " << j << endl;
        sum += c[j];
        maxu = max(maxu,c[j]);
        minu = min(minu,c[j]);
      }
    }
    // cout << maxu << " " << minu << endl;
    if (sum >= l && sum <= r && (maxu-minu >= x)) {
      ans += 1;
    }
  }

  cout << ans << endl;

	return 0;
}
