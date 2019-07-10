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
#define badka 1000000000
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  vector<pi> v;
  ll n,temp;
  cin >> n;
  vector<ll> a(n);
  fori(i,0,n-1)
  {
    cin >> a[i];
  }
  // vector<int> tst {7,2,3,1,4,5};
  // bool result = std::equal(a.begin(),a.end(),tst.begin());
  // if (result)
  // {
  //   cout << 4 << endl;
  //   return 0;
  // }
  if (n < 3)
  {
    cout << n << endl;
    return 0;
  }
  int indx = 0;
  fori(i,1,n-1)
  {
    if (a[i] <= a[i-1])
    {
      //cout << indx << " ye " << i << endl;
      v.pb(mk(indx,i-1));
      indx = i;
    }
  }
  v.pb(mk(indx,n-1));
  // for(auto x : v)
  // {
  //   cout << x.first << " " << x.second << endl;
  // }
  // fori(i,0,v.size()-2)
  // {
  //   ll xlen = v[i].second - v[i].first + 1;
  //   ll ylen = v[i+1].second - v[i+1].first + 1;
  //   if (xlen >= 2 && ylen >= 2 && (a[v[i+1].first + 1] - a[v[i].second] >= 2))
  //   {
  //     ans = max(ans,xlen+ylen);
  //   }
  //   if (xlen == 1 && ylen > 1 && a[v[i+1].first] != 1)
  //   {
  //     ans = max(ans,ylen+1);
  //   }
  //   if (ylen == 1 && xlen > 1 && a[v[i].second] < badka)
  //     ans = max(ans,xlen+1);
  // }
  vector<ll> l(n), r(n);
  fori(i,0,v.size()-1)
  {
    ll x = v[i].first;
    ll y = v[i].second;
    fori(j,x,y)
    {
      l[j] = j-x+1;
      r[j] = y-j+1;
    }
  }
  ll ans = INT_MIN;

  fori(i,0,a.size()-1)
  {
    if (i > 0 && i < n-1 && (a[i+1] - a[i-1] > 1))
      ans = max(ans,l[i-1]+r[i+1]+1);
    else if (i>0 && i < n-1)
    {
      ans = max(ans,max(1+r[i+1],l[i-1]+1));
    }
    if (i == 0)
      ans = max(ans,1+r[i+1]);
    if (i == n-1)
      ans = max(ans,1+l[i-1]);
  }
  cout << ans << endl;
  return 0;
}
