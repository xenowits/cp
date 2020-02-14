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

  int n;
  cin >> n;

  vector<ll> v(n+1,0), prefixSum(n+1,0);
  vector<ll> counter(n+3,0);

  ll sum = 0;
  fori(i,1,n) {
    cin >> v[i];
    sum += v[i];
    prefixSum[i] = sum;
  }

  if (sum%3) {
    cout << 0 << endl;
    exit(0);
  }

  sum /= 3;
  ll temp = 0;

  ford(i,n,1) {
    temp += v[i];
    if (temp == sum) {
      counter[i] += (1+counter[i+1]);
    } else {
      counter[i] += counter[i+1];
    }
  }

  ll cnt = 0;
  fori(i,2,n-1) {
    if (prefixSum[i-1] == sum) {
      cnt += counter[i+1];
    }
  }

  cout << cnt << endl;

	return 0;
}
