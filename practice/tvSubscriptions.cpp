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
  ll t;
  cin >> t;
  while (t--)
  {
    ll n, k, d;
    cin >> n >> k >> d;
    map<ll,ll> mp;
    ll ans = INT_MAX;
    vector<ll> v(n+1);
    fori(i,1,n)
      cin >> v[i];
    fori(i,1,d)
    {
      mp[v[i]] += 1;
    }
    ans = min(ans,(ll)mp.size());
    fori(i,d+1,n)
    {
      mp[v[i-d]] -= 1;
      mp[v[i]] += 1;
      if (mp[v[i-d]] == 0)
      {
        mp.erase(v[i-d]);
      }
      ans = min(ans,(ll)mp.size());
    }
    cout << ans << endl;
  }
  return 0;
}
