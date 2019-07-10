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

ll sum;
ll n,k;

ll mul(ll i)
{
  return (i*(i-1))/2;
}

ll bsearch(ll l, ll r)
{
  if (r >= l)
  {
    ll mid = l + (r-l)/2;
    ll tmp = sum - mul(mid);
    //cout << l << " " << mid << " " << r << " " << tmp << endl;
    if (tmp >= n)
    {
      return bsearch(mid+1,r);
    }
    else if (tmp == n-1)
      return mid;
    else
      return bsearch(l,mid-1);
  }
  return l;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n >> k;
  if (n == 1)
  {
    cout << 0 << endl;
    return 0;
  }
  sum = mul(k);
  if (k >= n)
  {
    cout << 1 << endl;
  }
  else if (n-1 > mul(k))
    cout << -1 << endl;
  else
  {
    ll x = bsearch(1,k-1);
    if (n-1 == (sum - mul(x)))
      cout << (k-x) << endl;
    else
      cout << (k-x+1) << endl;
  }
  //cout << bsearch(1,k-1);
  return 0;
}
