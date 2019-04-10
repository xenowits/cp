#include<bits/stdc++.h>
using namespace std;

#define fori(i,a,b) for (int i = a; i <= b ; ++i)
#define ford(i,a,b) for(int i = a;i >= b ; --i)
#define mk make_pair
#define mod 1000000007
#define pb push_back

multimap<int,int>::iterator findIndex(multimap<int,int> m)
{
  int initial = (m.begin())->second;
  multimap<int,int>::iterator it, temp;
  for (it = m.begin() ; it != m.end() ; ++it)
  {
    if (it->second != initial)
      break;
    else
      temp = it;
  }
  return temp;
}


bool someComp(pair<int,int> a, pair<int,int> b)
{
  if (a.second == b.second)
  {
    return (a.first > b.first);
  }
  return (a.second < b.second);
}

void solve(int n, long int X, vector<int> nodes[], vector<int> values)
{
  int k = 0;
  int parent[n+1] = {-1};
  ford(i,n,1)
  {
    if (nodes[i].size())
    {
      for(auto x : nodes[i])
      {
        values[i] += values[x];
        parent[x] = i;
      }
    }
  }
  long int final = values[1];
  // fori(i, 1, n)
  // {
  //   cout << values[i] << " " << parent[i] << endl;
  // }
  map<int, int> m;
  fori(i,2,n)
  {
    m.insert(mk(i, values[i]));
  }
  // for (auto x : m)
  //   cout << x.first << " " << x.second << endl;
  bool kitkat = true;
  while (kitkat)
  {
    set< pair<int,int>, decltype(&someComp)> s(&someComp);
    for (auto x : m)
      s.insert(x);
    auto t = s.begin();
    int tt1 = (*t).first;
    // for (auto t = s.begin() ; t != s.end() ; ++t)
    // {
    //   cout << (*t).first << " " << (*t).second << endl;
    // }
    //cout << typeid(*t).name();
    long int tt2 = X + (*t).second;
    int tt3 = (*t).second;
    //cout << tt1 << " " << tt2 << " " << tt3 << endl;
    if (tt2 >= 0)
    {
      kitkat = false;
      break;
    }
    else
    {
      final -= tt2;
      //cout << "final is " << tt2 << endl;
      m.erase(tt1);
      int root = parent[tt1];
      while (root >= 1)
      {
        m[root] -= tt3;
        root = parent[root];
      }
      for (auto x : nodes[tt1])
      {
        m.erase(x);
      }
    }
  }
  cout << final;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t,n,u,v;
  long int x;
  cin >> t;
  while (t>0)
  {
    cin >> n >> x;
    vector<int> nodes[n+1];
    vector<int> values(n+1);
    fori(i,1,n)
    {
      cin >> values[i];
    }
    fori(i,1,n-1)
    {
      cin >> u >> v;
      nodes[u].pb(v);
    }
    solve(n,x,nodes,values);
    t-=1;
    if (t>0)
      cout << "\n";
  }
  return 0;
}


// 1
// 10 2
// 5 -10 4 7 7 -1 3 8 -5 -3
// 1 2
// 1 3
// 1 4
// 2 5
// 3 8
// 3 9
// 4 10
// 5 6
// 5 7
