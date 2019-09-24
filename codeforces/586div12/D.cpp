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
#define pi pair<long long int,long long int>
#define sc second
#define fs first


int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  ll n,m;
  cin >> n >> m;
  ll ans = INT_MAX;
  for(int i = 1; i*m <= n; ++i)
  {
    ll x2 = n-i*m;
    ll x1 = i*m-x2;
    if (x1 >= 0 && x2 >= 0)
    {
      ans = min(ans,i*m);
    }
  }
  cout << (ans == INT_MAX ? -1 : ans) << endl;

  return 0;
}
