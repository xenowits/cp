//xenowitz -- Jai Shree Ram
#include<bits/stdc++.h>
using namespace std;

#define fori(i,a,b) for (long int i = a; i <= b ; ++i)
#define ford(i,a,b) for(long int i = a;i >= b ; --i)
#define mk make_pair
#define mod 1000000007
#define pb push_back
#define eb emplace_back
#define vec vector<long long int>
#define ll long long
#define rnd mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().count())
#define pi pair<long long int,long long int>
#define sc second
#define fs first
#define stf shrink_to_fit

ll binpow(ll a, ll b) {
    ll m = 1e9+7;
    a %= m;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res%m;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  // 10^n -2*9^n + 8^n

  ll n;
  cin >> n;

  ll ans = (binpow(10,n) - binpow(9,n) + mod)%mod;
  ans = (ans - binpow(9,n) + mod)%mod;
  ans = (ans + binpow(8,n))%mod;

  cout << ans << endl;
  return 0;
}
