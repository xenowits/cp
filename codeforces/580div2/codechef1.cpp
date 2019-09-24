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

  int t;
  cin >> t;

  while (t--)
  {
    int n,m,k,l,r,a,b;
    cin >> n >> m >> k >> l >> r;
    vector<pi> v;
    fori(i,1,n)
    {
      cin >> a >> b;
      if (a > k)
        v.pb(mk(max(k,a-m),b));
      else
        v.pb(mk(min(k,a+m),b));
    }
    sort(v.begin(), v.end(), [](const pi a, const pi b){
      if (a.sc == b.sc)
        return a.fs < b.fs;
      return a.sc < b.sc;
    });
    // for(auto x : v)
    //   cout << x.fs << " " << x.sc << endl;
    bool flag = 0;
    for(auto x : v)
    {
      if (x.fs >= l && x.fs <= r)
      {
        cout << x.sc << endl;
        flag = 1;
        break;
      }
    }
    if (!flag)
      cout << -1 << endl;
  }
  return 0;
}
