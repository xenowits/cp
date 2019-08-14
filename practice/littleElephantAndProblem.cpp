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
#define pi pair<long long int,long long int>
#define sc second
#define fs first

int main()
{
  int n;
  cin >> n;
  vector<long> v(n), dup(n);
  fori(i,0,n-1)
  {
    cin >> v[i];
    dup[i] = v[i];
  }
  sort(v.begin(), v.end());
  long cnt = 0;
  for(int i = 0 ; i < n; ++i)
  {
    if (v[i] != dup[i])
      cnt += 1;
    if (cnt > 2)
    {
      cout << "NO" << endl;
      return 0;
    }
  }
  cout << "YES" << endl;
  return 0;
}
