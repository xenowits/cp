#include<bits/stdc++.h>
using namespace std;

#define fori(i,a,b) for (long int i = a; i <= b ; ++i)
#define ford(i,a,b) for(long int i = a;i >= b ; --i)
#define mk make_pair
#define mod 1000000007
#define pb push_back
#define vec vector<long long int>
#define ll long long
#define rnd mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().count())
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
    ll a, b, c, d, k;
    cin >> a >> b >> c >> d >> k;
    ll e = (ll)ceil((a+0.0)/c), f = (ll)ceil((b+0.0)/d);
    if (e + f > k)
      cout << -1 << endl;
    else
      cout << e << " " << f << endl;
  }
  return 0;
}
