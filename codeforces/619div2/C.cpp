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

  int t;
  cin >> t;

  while (t--) {
    ll n, m;
    cin >> n >> m;
    ll temp = (ll)ceil(n/2.0);
    if (m >= temp) {
      cout << n*(n+1)/2 - (n-m) << endl;
    } else {
      ll ans = n*(n+1)/2;
      ll sexu = (n-m)/(m+1);
      ll sexmod = (n-m)%(m+1);
      if (sexmod == 0) {
        ans -= (m+1)*(sexu*(sexu+1)/2);
      } else {
        ans -= (sexmod*(sexu+1)*(sexu+2)/2 + (m+1-sexmod)*(sexu)*(sexu+1)/2);
      }
      cout << ans << endl;

    }
  }

	return 0;
}
