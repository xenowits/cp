//BINARY SEARCH_Xenowits
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

vector<ll> dis;
ll timeCalculator(ll mid) {
  ll temp_t = 0, temp2, temp3;
  for (auto x : dis) {
    temp2 = min(x, mid-x);
    temp3 = x-temp2;
    temp_t += (temp2+2*temp3);
  }
  return temp_t;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  ll n, k, s, t;
  cin >> n >> k >> s >> t;

  vector<ll> c(n+1,0), v(n+1,0), g(k+1,0);
  fori(i,1,n) {
    cin >> c[i] >> v[i];
  }
  fori(i,1,k) {
    cin >> g[i];
  }
  sort(g.begin()+1,g.end());

  fori(i,1,k-1) {
    dis.pb(g[i+1]-g[i]);
  }
  dis.pb(g[1]);
  dis.pb(s-g[k]);
  sort(dis.begin(), dis.end());
  ll minu = dis[0], maxu = dis[dis.size()-1];
  ll ans = INT_MAX;

  //O(k*log(s))
  //whatta a solution : binary search rocks

  ll l = maxu, r = s;

  while (r-l > 1) {
    ll mid = l + (r-l)/2;

    //let's calculate if it is possible to have mid
    //as one of possible capacity value

    ll temp_t = timeCalculator(mid);
    if (temp_t <= t) {
      //matlab ye possible toh h
      r = mid;
    } else {
      l = mid+1;
    }
  }

  //check for l
  if (timeCalculator(r) <= t) {
    ans = r;
  }
  //check for r
  if (timeCalculator(l) <= t) {
    ans = l;
  }

  ll real_ans = INT_MAX;
  fori(i,1,n) {
    if (v[i] >= ans) {
      real_ans = min(real_ans, c[i]);
    }
  }
  cout << ((real_ans == INT_MAX) ? -1 : real_ans) << endl;
  return 0;
}
