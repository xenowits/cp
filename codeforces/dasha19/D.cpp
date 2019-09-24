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
#define pi pair<long long int,long long int>
#define sc second
#define fs first
#define MAXN 100005

vector<int> adj[MAXN];
vector<bool> visited(MAXN,0);

void dfs(int u)
{
  visited[u] = 1;
  for(auto x : adj[u])
  {
    if (!visited[x])
      dfs(x);
  }
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n,k,x,y;
  cin >> n >> k;

  fori(i,1,k)
  {
    cin >> x >> y;
    adj[x].pb(y);
    adj[y].pb(x);
  }
  int cnt = 0;
  fori(i,1,n)
  {
    if (!visited[i])
    {
      cnt += 1;
      dfs(i);
    }
  }

  cout << k - (n-cnt) << endl;

  return 0;
}
