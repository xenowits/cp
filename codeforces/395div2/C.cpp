#include<bits/stdc++.h>
using namespace std;

#define fori(i,a,b) for (long int i = a; i <= b ; ++i)
#define ford(i,a,b) for(long int i = a;i >= b ; --i)
#define mk make_pair
#define mod 1000000007
#define pb push_back
#define ll long long

bool truth;

bool solve(vector<ll> t[], int v, vector<bool> &visited, unordered_set<int> &s,vector<ll> c)
{
  visited[v] = true;
  if (s.find(c[v]) == s.end())
    s.insert(c[v]);
  else
    truth = false;
  for (auto x : t[v])
  {
    if (!visited[x])
      solve(t,x,visited,s,c);
  }
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n,a,b;
  cin >> n;
  vector<ll> t[n+1];
  vector<ll> c(n+1);
  fori(i,1,n-1)
  {
    cin >> a >> b;
    t[a].pb(b);
    t[b].pb(a);
  }
  fori(i,1,n)
    cin >> c[i];
  fori(i,1,n)
  {
    for (int x : t[i])
    {
      vector<bool> visited(n+1,false);
      unordered_set<int> s;
      truth = true;
      solve(t,x,visited,s,c);
      if (truth)
      {
        cout << "YES" << endl << x;
        return 0;
      }
    }
  }
  cout << "NO";
  return 0;
}
