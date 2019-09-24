#include<bits/stdc++.h>
using namespace std;

#define fori(i,a,b) for (long int i = a; i <= b ; ++i)
#define ford(i,a,b) for(long int i = a;i >= b ; --i)
#define mk make_pair
#define mod 1000000007
#define pb push_back
#define vec vector<long long int>
#define ll long long
#define rnd mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().count())
#define pi pair<int,int>
#define sc second
#define fs first


int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n,k;
  cin >> n >> k;

  vector<ll> v(n+1);
  ll maxu = INT_MIN;
  fori(i,1,n)
  {
    cin >> v[i];
    maxu = max(maxu,v[i]);
  }
  ll ans = INT_MAX;
  for(ll i = 0; i <= maxu; ++i)
  {
    ll no = 0;
    vector<int> vovuh;
    fori(j,1,n)
    {
      ll temp = v[j], ops = 0;
      if (temp >= i)
      {
        while (temp > i)
        {
          temp /= 2;
          ops += 1;
        }
        if (temp == i)
        {
          no += 1;
          vovuh.pb(ops);
        }
      }
    }
    if (no >= k)
    {
      sort(vovuh.begin(), vovuh.end());
      ll sum = 0;
      fori(i,0,k-1)
        sum += vovuh[i];
      ans = min(ans,sum);
    }
  }
  cout << ans << endl;
  return 0;
}
