#include<bits/stdc++.h>
using namespace std;

#define fori(i,a,b) for (int i = a; i <= b ; ++i)
#define ford(i,a,b) for(int i = a;i >= b ; --i)
#define mk make_pair
#define mod 1000000007
#define pb push_back

void solve(set<pair<int,int> > s, long int n, long int m, long int k)
{
  long long int cnt = 0;
  for (auto x : s)
  {
    if (s.find(mk(x.first,x.second-1)) == s.end())
      cnt += 1;
    if (s.find(mk(x.first,x.second+1)) == s.end())
      cnt += 1;
    if (s.find(mk(x.first-1,x.second)) == s.end())
      cnt += 1;
    if (s.find(mk(x.first+1,x.second)) == s.end())
      cnt += 1;
  }
  cout << cnt;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t,k;
  long int n,m,r,c;
  pair<int,int> p;
  cin >> t;
  while (t>0)
  {
    cin >> n >> m >> k;
    set<pair<int,int> > s;
    fori(i,1,k)
    {
      cin >> r >> c;
      p.first = r;
      p.second = c;
      s.insert(p);
    }
    solve(s,n,m,k);
    t-=1;
    if (t>0)
      cout << "\n";
  }
  return 0;
}
