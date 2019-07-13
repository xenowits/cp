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

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t>0)
  {
    ll n;
    cin >> n;
    string s,u;
    cin >> s >> u;
    ll ans = 0;
    fori(i,0,n-1)
    {
      if (s[i] == u[i])
        ans += 1;
      else if (u[i] == 'N')
        continue;
      else if (s[i] == u[i])
        ans += 1;
      else if (s[i] != u[i])
      {
        i += 1;
      }
    }
    cout << ans << endl;
    t-=1;
  }
  return 0;
}
