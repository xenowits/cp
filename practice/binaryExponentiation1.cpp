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

//basic algorithm

ll binpow(ll a, ll b)
{
  ll ans = 1;
  while (b > 0) {
    // wo bit set h, tujhe a ka value pta h, tu bas ans m use multiply kr de---ingenious
    if (b&1)
      ans = ans*a;
    // hr loop m a ko a squared krte ja
    a = a*a;
    // b ko right shift krte jaa
    b >>= 1;
  }
}

//exponent modulo m

ll binpow (ll a, ll b, ll m) {
  a = a%m;
  ll res = 1;
  while (b > 0) {
    if (b&1)
      res = res*a%m;
    a = a*a%m;
    b >>= 1;
  }
}

//nth fibonacci number

pi fib(int n) {
  if (n == 0)
    return {0,1};
  // n/2 th aur n/2+1 th fibonacci numbers nikal lo
  auto p = fib(n >> 1);
  int c = p.fs*(2*p.sc-p.fs);
  int d = p.fs*p.fs + p.sc*p.sc;
  if (n&1)
    return {d,c+d};
  else
    return {c,d};
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  auto ans = fib(5);
  cout << ans.fs << " " << ans.sc << endl;
  int a = 0, b = 1;
  for (in)
  return 0;
}
