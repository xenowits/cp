//xenowitz -- Jai Shree Ram
#include<bits/stdc++.h>
using namespace std;

#define fori(i,a,b) for (long int i = a; i <= b ; ++i)
#define ford(i,a,b) for(long int i = a;i >= b ; --i)
#define mk make_pair
#define mod 1000000007
#define pb push_back
#define ll long long
#define rnd mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().count())
#define pi pair<long long int,long long int>
#define fs first
#define sc second

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;

    vector<ll> v(2*n,0);
    fori(i,0,2*n-1) {
      cin >> v[i];
    }

    sort(v.begin(), v.end());
    // ll ans = INT_MAX;
    // fori(i,0,2*n-2) {
    //   ans = min(ans,v[i+1]-v[i]);
    // }
    ll ans = v[n] - v[n-1];
    cout << ans << endl;
  }

  return 0;
}
