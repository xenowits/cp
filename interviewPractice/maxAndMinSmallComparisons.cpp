#include<bits/stdc++.h>
using namespace std;

#define fori(i,a,b) for (long int i = a; i <= b ; ++i)
#define ford(i,a,b) for(long int i = a;i >= b ; --i)
#define mk make_pair
#define mod 1000000007
#define pb push_back
#define ll long long
#define rnd mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().count())
#define pi pair<int,int>

struct popa {
  int mina,maxa;
};

popa solve(vector<int> v, int l, int h)
{
  popa a,b,c;
  int mid;

  if (l == h)
  {
    a.maxa = v[l];
    a.mina = v[l];
    return a;
  }
  if (h == l+1)
  {
    a.maxa = max(v[l],v[h]);
    a.mina = min(v[l],v[h]);
    return a;
  }
  mid = (l+h)/2;
  b = solve(v,l,mid);
  c = solve(v,mid+1,h);
  a.maxa = max(b.maxa,c.maxa);
  a.mina = min(b.mina,c.mina);
  return a;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  rnd;
  vector<int> v;
  fori(i,0,9)
  {
    v.pb(uniform_int_distribution<int>(1,20)(rng));
  }
  for(int a : v)
    cout << a << " ";
  cout << endl;
  popa ans = solve(v,0,v.size()-1);
  cout << "min and max are " << ans.mina << " " << ans.maxa << endl;
  return 0;
}
