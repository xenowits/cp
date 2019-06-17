#include<bits/stdc++.h>
using namespace std;

#define fori(i,a,b) for (int i = a; i <= b ; ++i)
#define ford(i,a,b) for(int i = a;i >= b ; --i)
#define mk make_pair
#define mod 1000000007
#define pb push_back
#define ll long long
#define MAXN 100001
#define rnd mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().cnt())
#define pi pair<int,int>

string solve(int p, int b, int r)
{
  int total_count = p+b+r;
  while(total_count > 1)
  {
    vector<pair<int,string> > v;
    v.pb(mk(p,"purple"));
    v.pb(mk(b,"blue"));
    v.pb(mk(r,"red"));
    sort(v.begin(), v.end());
    if (v[2].second == "purple" && v[1].second == "blue")
    {
      p-=1;b-=1;r+=1;
    }
    if (v[2].second == "blue" && v[1].second == "purple")
    {
      p-=1;b-=1;r+=1;
    }
    if (v[2].second == "red" && v[1].second == "blue")
    {
      p+=1;b-=1;r-=1;
    }
    if (v[2].second == "blue" && v[1].second == "red")
    {
      p+=1;b-=1;r-=1;
    }
    if (v[2].second == "purple" && v[1].second == "red")
    {
      p-=1;b+=1;r-=1;
    }
    if (v[2].second == "red" && v[1].second == "purple")
    {
      p-=1;b+=1;r-=1;
    }
    total_count -= 1;
  }
  if (p == 1)
    return "purple";
  if (b == 1)
    return "blue";
  if (r == 1)
    return "red";
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int purple = 33, blue = 23, red = 43;
  string a = solve(purple+1,blue,red);
  string b = solve(purple,blue+1,red);
  string c = solve(purple,blue,red+1);

  cout << a << " " << b << " " << c << endl;

  return 0;
}
