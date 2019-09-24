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

vector<int> adj[9];

void dfs(vector<bool> &visited, int u)
{
  visited[u] = 1;
  for(auto x : adj[u])
  {
    if (!visited[x])
    {
      dfs(visited,x);
    }
  }
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n,m;
  cin >> n >> m;
  if(n<7)
  {
    cout<<m<<endl;
    //cout<<"Ysasd"<<endl;
    return 0;
  }

  int x, y;
  vector<int> cnt(8,0);
  fori(i,1,m)
  {
    cin >> x >> y;
    cnt[x] += 1;
    cnt[y] += 1;
    adj[x].pb(y);
    adj[y].pb(x);
  }
  vector<bool> visited(8,0);
  int hello = 0;
  fori(i,1,n)
  {
    if (!visited[i])
    {
      hello += 1;
      dfs(visited,i);
    }
  }

  if(hello>1)
  {
    cout<<m<<endl;
    //cout<<"saldka"<<endl;
  }
  else
  {
    int min_deg = INT_MAX;
    fori(i,1,7)
    {
      min_deg = min(min_deg,cnt[i]);
    }
    //cout<<min_deg<<endl;
    if (min_deg != 0)
    {
      cout << m-min_deg+1 << endl;
    }
    else
      cout << m << endl;
  }
  return 0;
}
