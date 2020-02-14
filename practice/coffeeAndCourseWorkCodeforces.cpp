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

  ll n, m;
  cin >> n >> m;
  ll sum = 0;
  vector<int> v(n,0);
  fori(i,0,n-1) {
    cin >> v[i];
    sum += v[i];
  }

  if (sum < m) {
    cout << -1 << endl;
    exit(0);
  }

  sort(v.begin(), v.end(), greater<ll>());
  ll l = 1, r = n;

  while (l < r) {
    //binary search lagao no of days m
    //utne hisso m array ko todna jitna no of days h
    ll mid = l + (r-l)/2;
    sum = 0;
    for(int i = 0; i < n; i++) {
      //i+k
      if(v[i]-i/mid > 0){
        sum += v[i]-i/mid;
      } else {
        break;
      }
    }
    if (sum >= m) {
      r = mid;
    } else {
      l = mid+1;
    }
  }

  cout << l << endl;

	return 0;
}
