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

  ll n, k;
  cin >> n >> k;

  vector<int> a(n+1,0);
  fori(i,1,n) {
    cin >> a[i];
  }

  ford(i,k,1) {
    int maximum = a[i];
    for(int j = 1; (i+j*k) <= n; j++) {
      maximum = max(maximum,a[i+j*k]);
    }
    if (maximum > a[i]) {
      //dikkt h isi ko 1 se badha do
      a[i] += 1;
      break;
    }
  }

  fori(i,1,k) {
    for(int j = 1; (i+j*k) <= n; j++) {
      a[i+j*k] = a[i];
    }
  }

  fori(i,1,n) {
    cout << a[i];
  }

  return 0;
}
