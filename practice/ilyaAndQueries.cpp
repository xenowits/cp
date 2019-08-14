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
  int n,m,l,r;
  string s;
  cin >> s >> m;
  n = s.length();
  vector<int> v(n+1,0), ans(n+1,0);
  for(int i = 0 ; i < n-1; ++i)
  {
    if (s[i] == s[i+1])
      v[i+1] = 1;
  }
  ans[1] = v[1];
  for (int i = 2; i <= n; ++i)
  {
      ans[i] = ans[i-1]+v[i];
      //cout << ans[i] << " ";
  }
  //cout << endl;
  while (m--)
  {
    cin >> l >> r;
    cout << ans[r-1] - ans[l-1] << endl;
  }
  return 0;
}
