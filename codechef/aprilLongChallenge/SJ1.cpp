#include<bits/stdc++.h>
using namespace std;

#define fori(i,a,b) for (int i = a; i <= b ; ++i)
#define ford(i,a,b) for(int i = a;i >= b ; --i)
#define mk make_pair
#define mod 1000000007
#define pb push_back

void findAns(vector<long long> a,long long m)
{

  long long p1, p2, p3;
  p1 = a[0];
  //cout << "the array is : \n";
  for (auto x : a)
  {
    //cout << x << " ";
    p1 = __gcd(p1,x);
  }
  //cout << "gcd is " << p1 << endl;
  //cout << "m is " << m << endl;
  p1 = __gcd(p1,m);
  //cout << "p1 and m are " << p1 << " " << m <<endl;
  if (m%p1 != 0)
    cout << m - m%p1;
  else
    cout << m - p1;
}

vector<long long int> findArray(vector<int> parent,vector<long long> values, int n, int indx)
{
  vector<long long int> v;
  while (indx >= 0)
  {
    //cout << indx << " ";
    v.pb(values[indx]);
    indx = parent[indx];
  }
  //cout << " done\n";
  return v;
}

void solve(int n, vector<int> nodes[], vector<long long> values, vector<long long> m_values)
{
  //int parent[n+1] = {-1};
  vector<int> parent(n+1,-1);
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
  // for (auto x : parent)
  // {
  //   cout << x << " ";
  // }
  // cout << endl;
  //cout << "children and parent calculated " << children.size() << endl;
  sort(children.begin(),children.end());
  //cout << "children are : \n";
  // for (auto a : children)
  // {
  //     cout << a << " ";
  // }
  int children_size = children.size();
  for (int i = 0 ; i < children_size ; ++i)
  {
    int x = children[i];
    long long m = m_values[x];
    vector<long long int> v = findArray(parent,values,n,x);
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
    //cout << "done till here " << m_values.size() << endl;
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
