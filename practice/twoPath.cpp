#include<bits/stdc++.h>
using namespace std;

#define fori(i,a,b) for (long long int i = a; i <= b ; ++i)
#define ford(i,a,b) for(long long int i = a;i >= b ; --i)
#define mk make_pair
#define mod 998244353
#define pb push_back
#define ll long long
#define MAXN 300001
#define rnd mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().cnt())
#define pi pair<long long int,long long int>
#define sc second
#define fs first

vector<int> adj[250];
vector<ll> subtreeSize(250,0);
// vector<int> parent(250,-1);

// void dfs(int z)
// {
//   //cout << z << endl;
//   for(auto x : adj[z])
//   {
//     if (x != parent[z])
//     {
//       parent[x] = z;
//       dfs(x);
//       subtreeSize[z] += subtreeSize[x];
//     }
//   }
//   subtreeSize[z] += 1;
//   return;
// }

void dfsMaxDepth(int z,int nottotake, vector<int> &parent, vector<int> &longest_path)
{
  //cout << z << endl;
  int maxH = -1;
  for(auto x : adj[z])
  {
    if (x != parent[z] && x != nottotake)
    {
      parent[x] = z;
      dfsMaxDepth(x,nottotake,parent,longest_path);
      maxH = max(maxH,longest_path[x]);
    }
  }
  longest_path[z] = 1+maxH;
}

ll ansFinder(int a, int b, int n)
{
  vector<int> parent(n+1,-1), longest_path(n+1,0);
  dfsMaxDepth(a,b,parent,longest_path);
  vector<int> v;
  for (auto p : adj[a])
  {
    if (p != b)
      v.pb(longest_path[p]);
  }
  sort(v.begin(), v.end(), greater<int>());
  if (v.size() == 0)
    return 0;
  if (v.size() == 1)
    return 1+v[0];
  else
  {
    return 2 + v[0]+v[1];
  }
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  ll n,x,y;
  cin >> n;
  vector<pi> v;
  fori(i,1,n-1)
  {
    cin >> x >> y;
    adj[x].pb(y);
    adj[y].pb(x);
    v.pb(mk(x,y));
  }

  ll ans = INT_MIN;

  for(auto p : v)
  {
    ll temp1 = ansFinder(p.fs,p.sc, n);
    ll temp2 = ansFinder(p.sc,p.fs, n);
    //cout << p.fs << " " << p.sc << " " << temp1 << " " << temp2 << endl;
    ans = max(ans,temp1*temp2);
  }

  cout << ans << endl;

  return 0;
}
