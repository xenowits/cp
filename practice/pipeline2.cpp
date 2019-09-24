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

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  ll n,k;
  cin >> n >> k;
  if (n == 1)
  {
    cout << 0 << endl;
    exit(0);
  }
  if (n <= k)
  {
    cout << 1 << endl;
    exit(0);
  }
  ll l = 1, r = k-1;
  if (k*(k-1)/2 < n-1)
  {
    cout << -1 << endl;
    exit(0);
  }
  ll x, s = k*(k-1)/2;
  //s = {1,2,3,....,k-1}
  while (r-l > 1)
  {
    x = l + (r-l)/2;
    ll temp = s - x*(x-1)/2;
    if (temp < n-1)
      r = x;
    else if (temp == n-1)
    {
      cout << k-x << endl;
      exit(0);
    }
    else if (temp > n-1)
      l = x+1;
  }
  //cout << l << " " << r << endl;
  if (s - l*(l-1)/2 == n-1)
    cout << k-l << endl;
  else if (s-l*(l-1)/2 < n-1)
    cout << k-l+1 << endl;
  else if (s-r*(r-1)/2 == n-1)
    cout << k-r << endl;
  else if (s-r*(r-1)/2 < n-1)
    cout << k-r+1 << endl;
  return 0;
}
