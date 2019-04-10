#include<bits/stdc++.h>
using namespace std;

#define fori(i,a,b) for (int i = a; i <= b ; ++i)
#define ford(i,a,b) for(int i = a;i >= b ; --i)
#define mk make_pair
#define mod 1000000007
#define pb push_back

bool sortbysec(const pair<int,int> &a,
              const pair<int,int> &b)
{
    if (a.first == b.first)
    {
        return (a.second > b.second);
    }
    else
        return (a.first < b.first);
}

void update(vector<int> values, long int a, int index, vector<int> parent)
{
  values[index] = 0;
  index = parent[index];
  while (index >= 1)
  {
    values[index] -= a;
    index = parent[index];
  }
  return;
}

void solve(int n, long int X, vector<int> nodes[], vector<int> values)
{
  int k = 0;
  vector<int> parent(n+1,0);
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

  long int final = values[1], temp;
  bool kitkat = true;
  bool doneWith[n+1] = {false};
  vector< pair<int,int> > v;
  fori(i,2,n)
  {
    v.pb(mk(values[i],i));
  }
  sort(v.begin(),v.end(),sortbysec);
  while (kitkat)
  {
    if (!doneWith[v[0].second])
    {
      long int temp = X + v[0].first;
      if (temp < 0)
      {
        doneWith[v[0].second] = false;
        for (auto x : nodes[v[0].second])
        {
          values[x] = 0;
          doneWith[x] = false;
        }
        update(values, v[0].first, v[0].second, parent);
        // vector< pair<int,int> > v;
        v.clear();
        fori(i,2,n)
        {
          if (values[i] != 0)
            v.pb(mk(values[i],i));
        }
        sort(v.begin(),v.end(),sortbysec);
      }
      else
      {
        kitkat = false;
        break;
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
