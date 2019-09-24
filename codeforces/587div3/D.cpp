//https://codeforces.com/contest/279/problem/B
//two pointer problem

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
#define pi pair<long long int,long long int>
#define sc second
#define fs first


int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  ll n,t;
  cin >> n >> t;

  vector<int> v(n+1);

  fori(i,1,n)
    cin >> v[i];

  ll l = 1, r = 1, sum = v[1], ans = INT_MIN;
  while (l <= n && r <= n)
  {
    if (sum <= t)
    {
      while (r <= n && sum <= t)
      {
        ans = max(ans,r-l+1);
        r += 1;
        sum += v[r];
      }
      // now sum becomes greater than t
    }
    else
    {
      while (l <= n && sum >= t)
      {
        sum -= v[l];
        l += 1;
        if (sum <= t)
          ans = max(ans,r-l+1);
      }
      // now sum becomes less than t
    }
  }

  cout << ans << endl;

  return 0;
}
