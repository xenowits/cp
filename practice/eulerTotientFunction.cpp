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

vector<ll> primeFactorisation(ll n) {
  vector<ll> factorisation;
  for(ll i = 2; i*i <= n; i++) {
    while (n%i == 0) {
      factorisation.pb(i);
      n /= i;
    }
  }
  if (n > 1)
    factorisation.pb(n);
  return factorisation;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int q;
  cin >> q;

  while (q--) {
    map<ll, vector<pi> > mp;
    // map<ll, bool> mptruth;
    ll n, m, t, l, h;
    cin >> n >> m;
    fori(i,1,n) {
      cin >> t >> l >> h;
      mp[t].pb(mk(l,h));
    }
    bool flag = true;
    ll minu = m, maxu = m, prevt = 0;
    for (auto x : mp) {
      // if (maxu < minu) {
      //   flag = !flag;
      //   break;
      // }
      for (auto y : x.sc) {
        //y is a pair x.sc is a vector
        ll temp1 = y.fs, temp2 = y.sc;
        minu -= (x.fs-prevt);
        maxu += (x.fs-prevt);
        prevt = x.fs;
        // cout << maxu << " maxmin " << minu << endl;
        // cout << x.sc.fs << " " << x.sc.sc << endl;
        bool galathai = (maxu < temp1) || (minu > temp2);
        if (!galathai) {
          maxu = min(maxu, temp2);
          minu = max(minu, temp1);
        } else {
          flag = false;
          break;
        }
      }
    }
    cout << (flag ? "YES" : "NO") << endl;
  }

	return 0;
}
