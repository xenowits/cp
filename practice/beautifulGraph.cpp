#include<bits/stdc++.h>
using namespace std;

#define fori(i,a,b) for (long long int i = a; i <= b ; ++i)
#define ford(i,a,b) for(long long int i = a;i >= b ; --i)
#define mk make_pair
#define mod 998244353
#define pb push_back
#define ll long long
#define MAXN 300005
#define rnd mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().cnt())
#define pi pair<long long int,long long int>
#define sc second
#define fs first

vector<int> adj[MAXN];
bool flag;

long long binpow(long long a, long long b) {
    a %= mod;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

ll isBipartite(int s, vector<int> &color)
{
  int a = 0, b = 0;
  queue<int> q;
  q.push(s);
  //vector<int> color(n+1,-1);
  color[s] = 1;
  b += 1;
  while (!q.empty())
  {
    int t = q.front();
    q.pop();
    for(auto x : adj[t])
    {
      if (color[x] == -1)
      {
        color[x] = 1-color[t];
        if (color[x] == 0)
          a += 1;
        else
          b += 1;
        q.push(x);
      }
      else if (color[x] == color[t])
      {
        flag = 1;
        break;
      }
    }
    if (flag)
    {
      return 0;
    }
  }
  //cout << a << " " << b << " are these" << endl;
  return (binpow(2,a) + binpow(2,b))%mod;
}


int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t,n,m,a,b;
  cin >> t;

  while (t--)
  {
    flag = 0;
    cin >> n >> m;
    fori(i,1,m)
    {
      cin >> a >> b;
      adj[a].pb(b);
      adj[b].pb(a);
    }

    vector<int> color(n+1,-1);
    ll ans = 1;
    fori(i,1,n)
    {
      if (color[i] == -1)
      {
        ans = (ans*isBipartite(i,color))%mod;
        //cout << ans << " ans h" << endl;
      }
      if (flag)
        break;
    }

    cout << ans << endl;
    fori(i,1,n)
      adj[i].clear();
  }

  return 0;
}
