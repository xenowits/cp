#include<bits/stdc++.h>
using namespace std;

#define fori(i,a,b) for (long long int i = a; i <= b ; ++i)
#define ford(i,a,b) for(long long int i = a;i >= b ; --i)
#define mk make_pair
#define mod 998244353
#define pb push_back
#define ll long long
#define MAXN 1005
#define rnd mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().cnt())
#define pi pair<long long int,long long int>
#define sc second
#define fs first

vector<int> adj[MAXN];

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n,m,x,y;
  cin >> n >> m;

  vector<pi> v;
  vector<int> val(n+1);
  fori(i,1,n)
  {
    cin >> x;
    v.pb(mk(x,i));
    val[i] = x;
  }

  fori(i,1,m)
  {
    cin >> x >> y;
    adj[x].pb(y);
    adj[y].pb(x);
  }

  ll ans = 0;

  vector<bool> visited(n+1,0);

  sort(v.begin(), v.end());

  reverse(v.begin(), v.end());

  for(auto x : v)
  {
    if (!visited[x.sc])
    {
      visited[x.sc] = 1;
      //cout << x.fs << " " << x.sc << endl;
      for(auto i : adj[x.sc])
      {
        if (!visited[i])
          ans += val[i];
      }
      //cout << ans << endl;
    }
  }

  cout << ans << endl;

  return 0;
}
