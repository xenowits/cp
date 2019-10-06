#include<bits/stdc++.h>
using namespace std;

#define fori(i,a,b) for (long int i = a; i <= b ; ++i)
#define ford(i,a,b) for(long int i = a;i >= b ; --i)
#define mk make_pair
#define mod 1000000007
#define pb push_back
#define vec vector<long long int>
#define ll unsigned long long
#define rnd mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().count())
#define pi pair<long long int,long long int>
#define sc second
#define fs first

vector<ll> primeFactors(ll x)
{
  vector<ll> v;
  set<ll> s;

  while (x%2 == 0)
  {
    s.insert(2);
    x /= 2;
  }

  ll temp = (ll)sqrt(x);
  for (ll i = 3; i <= temp; i += 2)
  {
    while (x%i == 0)
    {
      s.insert(i);
      x = x/i;
    }
  }

  if (x > 2)
    s.insert(x);

  for (auto p : s)
    v.pb(p);

  return v;
}


ll binpow(ll a, ll b) {
    a %= mod;
    ll res = 1;
    while (b > 0) {
        if (b & 1)
            res = (res * a)%mod;
        a = (a * a)%mod;
        b >>= 1;
    }
    return res;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  ll x, n;
  cin >> x >> n;
  //cout<< x << " " << n <<endl;

  vector<ll> v = primeFactors(x);
  ll ans = 1;

  for(ll a : v)
  {
    ll temp = a;
    ll powerhai = 0;

    while (temp <= n && temp > 0)
    {
      powerhai += n/temp;
      if (temp > n/a)
        break;
      temp *= a;
    }
    ans = (ans*binpow(a,powerhai))%mod;
    //cout << powerhai << endl;
    // ans%=mod;
  }

  cout << ans << endl;

  return 0;
}
