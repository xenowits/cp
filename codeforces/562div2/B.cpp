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
#define sc second
#define fs first


int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n,m,a,b;
  cin >> n >> m;

  vector<pi> v;
  for(int i = 1; i <= m; ++i)
  {
    cin >> a >> b;
    v.pb(mk(a,b));
  }

  sort(v.begin(), v.end(), [](const pi a, const pi b){
    if (a.fs == b.fs)
      return a.sc < b.sc;
    return a.fs < b.fs;
  });
  
  return 0;
}
