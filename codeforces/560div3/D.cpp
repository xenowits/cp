#include<bits/stdc++.h>
using namespace std;

#define fori(i,a,b) for (long int i = a; i <= b ; ++i)
#define ford(i,a,b) for(long int i = a;i >= b ; --i)
#define mk make_pair
#define mod 1000000007
#define pb push_back
#define ll long long
#define rnd mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().count())

void func(vector<ll> v, ll n)
{
  ll x = v[0]*v[n-1];
  vector<ll> divisors;
  // fori(i,2,sqrt(temp))
  // {
  //   if (i == temp/i)
  //   {
  //     divisors.pb(i);
  //     continue;
  //   }
  //   if (temp%i == 0)
  //   {
  //     divisors.pb(i);
  //     divisors.pb(temp/i);
  //   }
  // }
  for (int i = 2; i * 1ll * i <= x; ++i) {
  if (x % i == 0) {
    divisors.push_back(i);
    if (i != x / i) {
      divisors.push_back(x / i);
    }
  }
}
  sort(divisors.begin(),divisors.end());
  // fori(i,0,n-1)
  // {
  //   cout << v[i] << " " << divisors[i] << endl;
  // }
  if (divisors == v)
    cout << x << endl;
  else
    cout << -1 << endl;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t,n;
  cin >> t;
  while (t>0)
  {
    cin >> n;
    vector<ll> d(n);
    fori(i,0,n-1)
      cin >> d[i];
    sort(d.begin(),d.end());
    func(d,n);
    // if (n&1)  // perfect square
    // {
    //   set<ll> ss;
    //   fori(i,0,n/2)
    //   {
    //     ss.insert(d[i]*d[n-1-i]);
    //   }
    //   if (ss.size() == 1)
    //   {
    //     cout << *ss.begin() << endl;
    //   }
    //   else
    //     cout << -1 << endl;
    // }
    // else
    // {
    //   set<ll> ss;
    //   fori(i,0,n/2-1)
    //   {
    //     ss.insert(d[i]*d[n-1-i]);
    //     //cout << d[i]*d[n-1-i] << " ";
    //   }
    //   if (ss.size() == 1)
    //   {
    //     cout << *ss.begin() << endl;
    //   }
    //   else
    //     cout << -1 << endl;
    // }
    t-=1;
  }
  return 0;
}
