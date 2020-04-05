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

  ll n;
  cin >> n;
  vector<int> v(n+1,0);
  fori(i,1,n)
    cin >> v[i];

  vector<ll> prevPosition(MAXN,0), finalAns(n+1,0);

  fori(i,1,n) {
    finalAns[i] = prevPosition[v[i]];
    prevPosition[v[i]] = i;
  }

  double ans = 0;
  fori(i,1,n) {
    // cout << finalAns[i] << " for i" << endl;
    ans += 2*(i-finalAns[i])*(n-i+1)-1;
    // cout << ans << endl;
  }

  ans = ans/(n*n+0.000000);

  cout << fixed << setprecision(6) << ans << endl;

	return 0;
}
