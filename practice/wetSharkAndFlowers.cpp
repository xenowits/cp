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

  ld n, p, l, r;
  cin >> n >> p;

  ld ans = 0;
  vector<pair<ld, ld> > vp;
  fori(i,1,n)
  {
    cin >> l >> r;
    vp.pb(mk(l,r));
  }
  ll temp = (ll)n;
  fori(i,0,n-1)
  {
    pair<ld, ld> p1 = vp[i], p2 = vp[(i+1)%temp];
    ld space1 = p1.sc-p1.fs+1;
    ld primes1 = (ll)p1.sc/(ll)p - (ll)(p1.fs-1)/(ll)p;

    ld space2 = p2.sc-p2.fs+1;
    ll primes2 = (ll)p2.sc/(ll)p - (ll)(p2.fs-1)/(ll)p;

    //cout << p1.sc << " " << p1.fs << " " << primes1 << " " << primes2 << endl;

    ld prob = 2000*(1-(1-primes1/space1)*(1-primes2/space2));
    //cout << prob << endl;

    ans += prob;
  }

  cout << fixed << setprecision(6) << ans << endl;

  return 0;
}
