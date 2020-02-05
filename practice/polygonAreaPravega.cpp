#include<bits/stdc++.h>
using namespace std;

#define fori(i,a,b) for (long long int i = a; i <= b ; ++i)
#define ford(i,a,b) for(long long int i = a;i >= b ; --i)
#define mk make_pair
#define mod 1000000007
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

  ll n, q, l, r;
  cin >> n;

  vector<ll> x(n+1,0), y(n+1,0);
  vector<ll> preX(n+1,0), preY(n+1,0);
  vector<ll> preX1(n+1,0), preY1(n+1,0);

  fori(i,1,n) {
    cin >> x[i] >> y[i];
  }

  fori(i,1,n) {
    if (i == n)
      preX[i] = (x[i]*y[1])%mod;
    else
      preX[i] = (x[i]*y[i+1])%mod;
  }

  fori(i,1,n) {
    if (i == n)
      preY[i] = (x[1]*y[i])%mod;
    else
      preY[i] = (x[i+1]*y[i])%mod;
  }

  fori(i,1,n) {
    preX1[i] = (preX1[i-1]+preX[i])%mod;
    // cout << i << " preX1 " << preX1[i] << endl;
  }

  fori(i,1,n) {
    preY1[i] = (preY1[i-1]+preY[i])%mod;
    // cout << i << " preY1 " << preY1[i] << endl;
  }

  //total area of the polygon

  ll total = abs(preX1[n] - preY1[n]);
  total = total%mod;
  //cout << total << endl;

  cin >> q;
  while (q--) {
    cin >> l >> r;
    if (l > r) {
      swap(l,r);
      //cout << r-1 << " so " << l << " " << preX1[r-1] << " " << preX1[l-1] << endl;
      ll sum1 = ((preX1[r-1]-preX1[l-1])%mod + x[r]*y[l])%mod;
      ll sum2 = ((preY1[r-1]-preY1[l-1])%mod + y[r]*x[l])%mod;
      //cout << sum1 << " is sum1 and the next is sum2 " << sum2 << endl;
      ll sum3 = abs(sum1 - sum2)%mod;
      cout << (total - sum3)%mod << endl;
    } else if (l < r) {
      //cout << r-1 << " so " << l << " " << preX1[r-1] << " " << preX1[l-1] << endl;
      ll sum1 = ((preX1[r-1]-preX1[l-1])%mod + x[r]*y[l])%mod;
      ll sum2 = ((preY1[r-1]-preY1[l-1])%mod + y[r]*x[l])%mod;
      //cout << sum1 << " is sum1 and the next is sum2 " << sum2 << endl;
      ll sum3 = abs(sum1 - sum2)%mod;
      cout << sum3 << endl;
    } else {
      cout << 0 << endl;
    }
  }

  return 0;
}
