#include<bits/stdc++.h>
using namespace std;

#define fori(i,a,b) for (long long int i = a; i <= b ; ++i)
#define ford(i,a,b) for(long long int i = a;i >= b ; --i)
#define mk make_pair
#define mod 998244353
#define pb push_back
#define ll long long
#define MAXN 300001
#define rnd mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().cnt())
#define pi pair<long long int,long long int>
#define sc second
#define fs first

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  cin >> t;

  while (t--)
  {

    ll n, x, d, h;
    cin >> n >> x;

    vector<pi> v;
    ll M = INT_MIN, m = INT_MIN;
    fori(i,1,n)
    {
      cin >> d >> h;
      v.pb(mk(d,h));
      if (d >= h)
        m = max(m,d-h);
      M = max(M,d);
    }

    if (x <= M)
      cout << 1 << endl;
    else if (m == INT_MIN || m == 0)
      cout << -1 << endl;
    else
      cout << (ll)ceil((x-M+0.0)/m) + 1 << endl;
  }

  return 0;
}
