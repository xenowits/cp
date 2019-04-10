#include<bits/stdc++.h>
#include <boost/functional/hash.hpp>
using namespace std;

#define fori(i,a,b) for (int i = a; i <= b ; ++i)
#define ford(i,a,b) for(int i = a;i >= b ; --i)
#define mk make_pair
#define mod 1000000007
#define pb push_back

void findAns(vector<long long> a,long long m)
{
  long long b,c,d;
  if (a.size() == 1)
  {
    if (a[0]%m != 0)
      cout << m-1;
    else
      cout << 0;
  }
  if (a.size() == 2)
  {
    b = a[0];
    c = a[1];
    if (__gcd(b,c) % m == 0)
      cout << 0;
    else
      cout << m-1;
  }
  else
  {
    d = a[0];
    fori (i, 1, a.size()-1)
    {
      b = a[i];
      d = __gcd(d,b);
    }
    if (d%m == 0)
      cout << 0;
    else
      cout << m-1;
  }
}

vector<long long int> findArray(int parent[],vector<long long> values, int n, int indx)
{
  vector<long long int> v;
  while (indx >= 1)
  {
    v.pb(values[indx]);
    indx = parent[indx];
  }
  return v;
}

void solve(int n, vector<int> nodes[], vector<long long> values, vector<long long> m_values)
{
  int parent[n+1] = {-1};
  vector<int> children;
  ford(i,n,1)
  {
    if (nodes[i].size() >= 1)
    {
      //cout << i << " ghusa " << endl;
      for(auto x : nodes[i])
      {
        parent[x] = i;
      }
    }
    else
    {
      children.pb(i);
    }
  }
  //cout << "children and parent calculated " << children.size() << endl;
  sort(children.begin(),children.end());
  int children_size = children.size();
  for (int i = 0 ; i < children_size ; ++i)
  {
    int x = children[i];
    vector<long long int> v = findArray(parent,values,n,x);
    long long m = m_values[x];
    findAns(v,m);
    if (i <= children_size-2)
    {
      cout << " ";
    }
  }
  //cout << endl;
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
      //nodes[v].pb(u);
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
    //cout << "done till here " << m_values.size() << endl;
    solve(n,nodes,values,m_values);
    t-=1;
    if (t>0)
      cout << endl;
  }
  return 0;
}
