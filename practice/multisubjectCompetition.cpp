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

bool comp(pi a, pi b) {
  if (a.fs == b.fs) {
    return a.sc > b.sc;
  }
  return a.fs < b.fs;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  ll n, m, s, r;
  cin >> n >> m;

  vector<pi> v;
  fori(i,1,n) {
    cin >> s >> r;
    v.pb(mk(s,r));
  }

  sort(v.begin(), v.end(), comp);

  // for (auto x : v) {
  //   cout << x.fs << " " << x.sc << endl;
  // }

  vector<ll> ans(n+1,0);

  for(int i = 0; i < n;) {
    ll cnt = 1;
    ll temp = v[i].sc;
    ans[cnt] += max((ll)0,temp);
    cnt += 1;
    int j;
    for (j = i+1; j < n && (v[j].fs == v[i].fs) ; j++) {
      temp += v[j].sc;
      ans[cnt] += max((ll)0,temp);
      cnt += 1;
    }
    i = j;
  }

  ll realAns = INT_MIN;
  fori(i,1,n) {
    realAns = max(realAns,ans[i]);
    // cout << i << " " << ans[i] << endl;
  }

  cout << max(realAns,(ll)0) << endl;

	return 0;
}
