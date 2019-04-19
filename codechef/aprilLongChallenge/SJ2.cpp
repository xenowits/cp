#include<bits/stdc++.h>
using namespace std;

#define fori(i,a,b) for (int i = a; i <= b ; ++i)
#define ford(i,a,b) for(int i = a;i >= b ; --i)
#define mk make_pair
#define mod 1000000007
#define pb push_back
#define ll long long

void findAns(ll a, long long m)
{
  ll p1 = __gcd(a,m);
  if (m%p1 != 0)
    cout << m - m%p1;
  else
    cout << m - p1;
}

void dfs(int v,vector<int> nodes[], vector<ll> &gcd,vector<bool> &visited)
{
  visited[v] = true;
  for (auto x : nodes[v])
  {
    if (!visited[x])
    {
      gcd[x] = __gcd(gcd[x],gcd[v]);
      dfs(x,nodes,gcd,visited);
    }
  }
}

void solve(int n, vector<int> nodes[], vector<long long> values, vector<long long> m_values)
{
  vector<ll> gcd(n+1);
  vector<bool> visited(n+1,false);
  fori(i,1,n)
    gcd[i] = values[i];
  dfs(1,nodes,gcd,visited);
  // cout << "gcd is :\n";
  // fori(i,1,n)
  //   cout << gcd[i] << " ";
  // cout << endl;
  vector<ll> children;
  fori(i,1,n)
  {
    //cout << nodes[i].size() << " ";
    if (nodes[i].size() == 1)
    {
        children.pb(i);
        //cout << i << " done\n";
    }
  }
  //cout << endl;
  sort(children.begin(),children.end());
  //cout << children.size() << endl;
  int csize = children.size();
  for (int i = 0 ; i < csize ; ++i)
  {
    int x = children[i];
    //cout << x << "children\n";
    //cout << m_values[x] << " value h\n";
    findAns(gcd[x],m_values[x]);
    if (i != csize-1)
      cout << " ";
  }
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t,n;
  long long int u,v;
  cin >> t;
  while (t>0)
  {
    cin >> n;
    vector<int> nodes[n+1];
    fori(i,1,n-1)
    {
      cin >> u >> v;
      nodes[u].pb(v);
      nodes[v].pb(u);
    }
    vector<long long> values(n+1);
    fori(i,1,n)
    {
      cin >> values[i];
    }
    vector<long long> m_values(n+1);
    fori(i,1,n)
    {
      cin >> m_values[i];
    }
    solve(n,nodes,values,m_values);
    t-=1;
    if (t>0)
      cout << "\n";
  }
  return 0;
}

// 2
// 6
// 1 2
// 2 3
// 1 4
// 4 5
// 5 6
// 1 2 3 4 5 6
// 3 6 7 2 1 8
// 5
// 1 2
// 2 3
// 2 4
// 2 5
// 1 2 3 4 5
// 3 2 1 5 6
