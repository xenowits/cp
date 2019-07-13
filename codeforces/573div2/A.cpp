#include<bits/stdc++.h>
using namespace std;

#define fori(i,a,b) for (long int i = a; i <= b ; ++i)
#define ford(i,a,b) for(long int i = a;i >= b ; --i)
#define mk make_pair
#define mod 1000000007
#define pb push_back
#define vec vector<long long int>
#define ll long long
#define rnd mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().count())
#define pi pair<int,int>
#define s second
#define f first


int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int x;
  cin >> x;
  vector<pi> v{mk(x%4,0), mk((x+1)%4,1), mk((x+2)%4,2)};
  
  //sort(v.begin(),v.end(),greater<pi>());
  fori(i,0,2)
  {
    if (v[i].f == 1)
    {
      cout << v[i].s << " A" << endl;
      exit(0);
    }
  }
  fori(i,0,2)
  {
    if (v[i].f == 3)
    {
      cout << v[i].s << " B" << endl;
      exit(0);
    }
  }
  fori(i,0,2)
  {
    if (v[i].f == 2)
    {
      cout << v[i].s << " C" << endl;
      exit(0);
    }
  }
  fori(i,0,2)
  {
    if (v[i].f == 0)
    {
      cout << v[i].s << " D" << endl;
      exit(0);
    }
  }
  return 0;
}
