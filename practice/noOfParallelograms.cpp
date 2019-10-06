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

struct point{
  ll x, y;
  point(ll a, ll b) : x(a), y(b){}
};

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  ll n,a,b;
  cin >> n;

  vector<point> v;

  fori(i,1,n)
  {
    cin >> a >> b;
    v.emplace_back(a,b);
  }

  map<ll,ll> mp;

  fori(i,0,n-1)
  {
    fori(j,i+1,n-1)
    {
      ll temp1 = (v[i].x+v[j].x);
      ll temp2 = (v[i].y+v[j].y);
      ll cantor_pair_value = (temp1+temp2)*(temp1+temp2+1)/2 + temp2;
      mp[cantor_pair_value] += 1;
    }
  }

  ll ans = 0;

  for(auto p : mp)
  {
    ans += p.sc*(p.sc-1)/2;
  }

  cout << ans << endl;

  return 0;
}
