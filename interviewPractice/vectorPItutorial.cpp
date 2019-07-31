#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define pi pair<int,int>
#define fs first
#define sc second

bool comp(pi x, pi y)
{
  if (x.fs == y.fs)
  {
    return x.sc < y.sc;
  }
  return x.fs > y.fs;
}

void solve(int n, vector<int> dist, vector<int> cost)
{
  vector<pair<long,long> > v;
  for(int i = 0; i < n; ++i)
    v.pb(mk(dist[i],cost[i]));
  //sort(v.begin(), v.end(), comp);
  sort(v.begin(), v.end(), [] (pi x, pi y) -> bool
  {
  if (x.fs == y.fs)
  {
    return x.sc < y.sc;
  }
  return x.fs > y.fs;
  });
  for (auto x : v)
  {
    cout << x.first << " " << x.second << endl;
  }
}

int main()
{
  int n;
  cin >> n;
  vector<int> dist(n), cost(n);
  for(int i = 0 ; i < n; ++i)
  {
    cin >> dist[i];
  }
  for(int i = 0; i  < n; ++i)
    cin >> cost[i];
  solve(n, dist, cost);

}


/*
3
2 3 3
5 4 2
*/
