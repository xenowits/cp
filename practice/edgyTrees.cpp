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
#define pi pair<int,int>

ll n,k;
vector<int> adj[100001];
vector<bool> visited(100001,false);

ll bfs(int s){
  int cnt = 0;
  queue<int> q;
  q.push(s);
  visited[s] = true;
  while(!q.empty())
  {
    int temp = q.front();
    cnt+=1;
    q.pop();
    for(auto x : adj[temp])
    {
      if (!visited[x])
      {
        q.push(x);
        visited[x] = true;
      }
    }
  }
  return cnt;
}

ll power(ll x)
{
  ll res = 1;
  ll y = k;
  x = x%mod;
  while(y>0)
  {
    if (y&1)
      res = (res*x)%mod;
    y = y>>1;
    x = (x*x)%mod;
  }
  return res;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n >> k;
  fori(i,1,n-1)
  {
    ll u,v,x;
    cin >> u >> v >> x;
    if (x == 0)
    {
      adj[u].pb(v);
      adj[v].pb(u);
    }
  }
  ll cnt = 0;
  //ll ans = power(n);
  fori(i,1,n)
  {
    if (!visited[i])
    {
      // cnt += (ll)(pow(bfs(i),k)+0.5);
      ll temp = power(bfs(i));
      //cout << temp << " h" << endl;
      // ans = ans - temp;
      // ans = ans + mod;
      // ans = ans%mod;
      cnt = cnt+temp;
      cnt = cnt%mod;
      //cout << "cnt " << cnt << endl;
    }
  }
  //cout << ans << endl;
  cout << (power(n) - cnt + mod)%mod << endl;
  return 0;
}
