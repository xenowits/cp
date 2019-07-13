#include<bits/stdc++.h>
using namespace std;

#define fori(i,a,b) for (long int i = a; i <= b ; ++i)
#define ford(i,a,b) for(long int i = a;i >= b ; --i)
#define mk make_pair
#define mod 1000000007
#define pb push_back
#define ll long long
#define rnd mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().count())
#define pi pair<int,int>

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;
  vector<ll> v(n+1);
  fori(i,1,n)
    cin >> v[i];
  if (n < 3)
  {
    cout << n << endl;
    exit(0);
  }
  vector<ll> vp(n+1,0);
  fori(i,1,n)
  {
    if (i < 3)
      vp[i] = 1;
    else if (v[i] == v[i-1]+v[i-2])
    {
      vp[i] = 1;
    }
  }
  ll ans = INT_MIN, l = 2;
  fori(i,1,n)
  {
    cout << vp[i] << " ";
    if (vp[i] == 1)
      l += 1;
    else
    {
      ans = max(l,ans);
      //cout << ans << " ans h" << endl;
      l = 0;
    }
    //cout << l << " l h" << endl;
  }
  ans = max(ans,l);
  cout << ans << endl;
  return 0;
}
