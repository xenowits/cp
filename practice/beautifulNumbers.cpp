#include<bits/stdc++.h>
using namespace std;

#define fori(i,a,b) for (int i = a; i <= b ; ++i)
#define ford(i,a,b) for(int i = a;i >= b ; --i)
#define mk make_pair
#define mod 1000000007
#define pb push_back
#define ll long long
#define MAXN 100001
#define rnd mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().cnt())
#define pi pair<long long int,long long int>

vector<ll> fact(1000001,1);
ll N = 1000000;

ll inv(ll n, ll i)
{
  ll a = fact[n-i]*fact[i];
  a %= mod;
  ll res = 1, b = mod-2;
  while (b>0)
  {
    if (b&1)
      res = res*a%mod;
    a = a*a%mod;
    b >>= 1;
  }
  return res%mod;
}

bool isSumGood(ll sum, int a, int b)
{
  ll temp;
  while (sum)
  {
    temp = sum%10;
    if (temp != a && temp != b)
      return 0;
    sum /= 10;
  }
  return 1;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int a,b,n;
  cin >> a >> b >> n;
  fori(i,1,1000000)
  {
    fact[i] = (fact[i-1]*i)%mod;
  }
  ll ans = 0;
  fori(i,0,n)
  {
    ll sum = a*i + (n-i)*b;
    if (isSumGood(sum,a,b))
    {
      //ans = (ans + (fact[n]*inv(fact[i]*fact[n-i])))%mod;
      ans = (ans + (fact[n]*inv(n,i))%mod)%mod;
    }
  }
  cout << ans%mod << endl;
  return 0;
}
