#include<bits/stdc++.h>
using namespace std;

#define fori(i,a,b) for (long long int i = a; i <= b ; ++i)
#define ford(i,a,b) for(long long int i = a;i >= b ; --i)
#define mk make_pair
#define mod 1000000007
#define pb push_back
#define ll long long
#define MAXN 100001
#define rnd mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().cnt())
#define pi pair<long long int,long long int>
#define sc second
#define fs first

ll ans = INT_MIN, ans_x, ans_y;

void solve(int d,vector<ll> a, vector<ll> b, int n, int m)
{
  ll x,y,t;
  auto p = upper_bound(a.begin(),a.end(),d);
  auto q = upper_bound(b.begin(),b.end(),d);

    t = p-a.begin();
    x = 2*t+3*(n-t);
    
    t = q-b.begin();
    y = 2*t+3*(m-t);

    if (ans < x-y)
    ans_x = x, ans_y = y, ans = x-y;
    else if (ans == x-y && x > ans_x)
      ans_x = x, ans_y = y;

}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n,m;
  cin >> n;

  vector<ll> a(n);
  vector<ll> v;
  fori(i,0,n-1)
  {
    cin >> a[i];
    v.pb(a[i]);
  }
  cin >> m;
  vector<ll> b(m);
  fori(i,0,m-1)
  {
    cin >> b[i];
    v.pb(b[i]);
  }

  sort(a.begin(),a.end());
  sort(b.begin(),b.end());
  sort(v.begin(),v.end());

  for(auto d : v)
  {

    ll x,y,t;
    auto p = upper_bound(a.begin(),a.end(),d);
    auto q = upper_bound(b.begin(),b.end(),d);

      t = p-a.begin();
      x = 2*t+3*(n-t);

      t = q-b.begin();
      y = 2*t+3*(m-t);

    if (ans < x-y)
      ans_x = x, ans_y = y, ans = x-y;
    else if (ans == x-y && x > ans_x)
      ans_x = x, ans_y = y;

  }

  solve(*(v.end()-1)+1,a,b,n,m);
  solve(*v.begin()-1,a,b,n,m);

  cout << ans_x << ":" << ans_y << endl;
  return 0;
}
