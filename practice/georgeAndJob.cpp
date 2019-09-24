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

vector<ll> v(5005,0), pre(5005,0);
ll n, m;

ll solve(ll indx, ll k)
{
  if (n-indx+1 < k*m)
    return -1;

  ll ans = INT_MIN;

  // for(int i = indx; i < n+2-m*k; ++i)
  // {
    // ll temp = solve(i+m,k-1);
    // ans = max(ans,pre[i+m-1]-pre[i-1]+temp);
  //   cout << ans << endl;
  // }
  for(int i = indx; i <= n; ++i)
  {
    if (i+m <= n)
    {
      ll temp = solve(i+m,k-1);
      cout << temp << endl;
      if (temp != -1)
        ans = max(ans,pre[i+m-1]-pre[i-1]+temp);
    }
  }
  cout << indx << " jk " << k << " " << n << endl;
  return ans;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  ll k;
  cin >> n >> m >> k;

  fori(i,1,n)
    cin >> v[i];

  fori(i,1,n)
    pre[i] = pre[i-1]+v[i];

  cout << solve(1,k);

  return 0;
}
