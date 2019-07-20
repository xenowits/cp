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
#define fs first
#define sc second
#define MAXN 101100

vector<ll> v(1001,0), papa(MAXN+5,-1), dist(MAXN+5,INT_MAX);

vector<bool> visited(MAXN+5,0);
ll n,x,y;

void bfs()
{
  visited[x] = 1;
  queue<ll> q;
  q.push(x);
  ll ans = INT_MAX;
  dist[x] = 0;
  while (!q.empty())
  {
    ll t = q.front();
    //cout << t << " front h " << endl;
    q.pop();
    if (t == y)
    {
      ans = min(dist[t],ans);
      continue;
    }
    fori(i,1,n)
    {
      ll temp = (v[i]*t)%MAXN;
      //cout << temp << " yehi temp h" << endl;
      if (!visited[temp] && temp <= y)
      {
        papa[temp] = t;
        visited[temp] = 1;
        q.push(temp);
        dist[temp] = 1+dist[t];
      }
    }
  }
  if (ans == INT_MAX)
    cout << -1 << endl;
  else
    cout << ans << endl;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n >> x >> y;
  fori(i,1,n)
    cin >> v[i];

  bfs();

  return 0;
}
