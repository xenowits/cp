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

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll n,x,y;
  cin >> n;
  vector<ll> c(n+1);
  //set<ll> a,b;
  //ll temp,semp;
  ll a,b,ans = -1;
  vector<pi> v;
  fori(i,1,n-1)
  {
    cin >> x >> y;
    v.pb(mk(x,y));
  }
  fori(i,1,n)
  {
    cin >> c[i];
  }
  if (n == 2)
  {
    cout << "YES" << endl << 1 << endl;
    return 0;
  }
  vector<pi> vi;
  fori(i,0,v.size()-1)
  {
    if (c[v[i].first] != c[v[i].second])
      vi.pb(v[i]);
  }
  //cout << vi.size() << " is the size()" << endl;
  if (vi.size() == 0)
  {
    cout << "YES" << endl << 1 << endl;
    return 0;
  }
  if (vi.size() == 1)
  {
    a = c[vi[0].first]; b = c[vi[0].second];
    ll a1 = 0, b1 = 0;
    cout << "YES" << endl;
    for(auto x : v)
    {
      if (c[x.first] == a)
        a1 += 1;
      else if (c[x.second] == b)
        b1 += 1;
      else if (c[x.first] == b)
        b1 += 1;
      else if (c[x.second] == a)
        a1 += 1;
    }
    if (a1 > b1)
      cout << vi[0].second << endl;
    else
      cout << vi[0].first << endl;
    return 0;
  }
  /// this part is for vi size() > 1 that means there
  // are more than 1 edges having different color end points
  bool done = false, flag = false;
  fori(i,0,vi.size()-1)
  {
    ll x = vi[i].first;
    ll y = vi[i].second;
    //cout << x << " " << y << " h accha na" << endl;
    if (flag)
    {
      //cout << x << " " << y << " " << c[x] << " " << c[y] << " yeha bhi dekh le" << endl;
      if (x != ans && y != ans)
      {
        //cout << x << " " << y << " " << c[x] << " " << c[y] << endl;
        cout << "NO" << endl;
        return 0;
      }
    }
    else if (done)
    {
      if (x == a)
        ans = a;
      else if (x == b)
        ans = b;
      else if (y == a)
        ans = a;
      else if (y == b)
        ans = b;
      //cout << ans << " is the answer" << endl;
      flag = true;
      if (ans == -1)
      {
        cout << "NO" << endl;
        return 0;
      }
      //cout << x << " " << y << " " << a << " " << b << endl;
    }
    else if (!done)
    {
      // a.insert(x);
      // b.insert(y);
      done = true;
      //cout << x << " " << y << " " << c[x] << " " << c[y] << endl;
      a = x; b =y;
      //cout << a << " " << b << " yeha ghus gya m" << endl;
    }
  }
  cout << "YES" << endl << ans << endl;
  return 0;
}
