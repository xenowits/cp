#include<bits/stdc++.h>
using namespace std;

#define fori(i,a,b) for (long long int i = a; i <= b ; ++i)
#define ford(i,a,b) for(long long int i = a;i >= b ; --i)
#define mk make_pair
#define mod 998244353
#define pb push_back
#define ll long long int
#define MAXN 300001
#define rnd mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().cnt())
#define pi pair<long long int,long long int>
#define sc second
#define fs first
#define Key pair<double,double>

struct point{
  ll x, y;
  point(ll a, ll b) : x(a), y(b){}
};

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  ll n,x,y;
  cin >> n;
  vector<point> v;
  fori(i,1,n)
  {
    cin >> x >> y;
    v.emplace_back(x,y);
  }
  ll ans = n*(n-1)*(n-2)/6;
  map<Key, ll> mp;
  ll t = v.size();
  vector<ll> yparallel(205,0);
  fori(i,0,t-1)
  {
    fori(j,i+1,t-1)
    {
      ll temp1 = (v[j].x-v[i].x);
      ll temp2 = (v[j].y-v[i].y);
      ll temp3 = (v[j].x*v[i].y - v[i].x*v[j].y);
      if (temp1 == 0)
        yparallel[100+v[i].x] += 1;
      else
      {
        Key p((temp2+0.0)/temp1,(temp3+0.0)/temp1);
        mp[p] += 1;
      }
    }
  }

  for (auto x : mp)
  {
    //cout << x.fs.fs << " " << x.fs.sc << " " << x.sc << endl;
    ll temp = (1+(ll)sqrt(1+8*x.sc))/2;
    ans -= temp*(temp-2)*(temp-1)/6;
  }

  fori(i,0,200)
  {
    ll temp = (1+(ll)sqrt(1+8*yparallel[i]))/2;
    ans -= temp*(temp-1)*(temp-2)/6;
  }

  cout << ans << endl;

  return 0;
}
