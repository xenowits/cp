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
  ll n, p;
  cin >> n >> p;

  fori(i,1,MAXN)
  {
    ll nip = n-i*p;
    int bitcnt = __builtin_popcount(nip);
    if (nip >= 0 && bitcnt <= i && nip >= i)
    {
      cout << i << endl;
      exit(0);
    }
  }
  cout << -1 << endl;
  return 0;
}
