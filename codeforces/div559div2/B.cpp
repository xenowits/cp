#include<bits/stdc++.h>
using namespace std;

#define fori(i,a,b) for (long long int i = a; i <= b ; ++i)
#define ford(i,a,b) for(long long int i = a;i >= b ; --i)
#define mk make_pair
#define mod 1000000007
#define pb push_back
#define ll long long
#define rnd mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().count())

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll n;
  cin >> n;
  vector<ll> v(n+1);
  ll ans = INT_MAX;
  //cout << max(5,7);
  fori(i,1,n)
  {
    cin >> v[i];
    ll temp = std::max(i-1,n-i);
    ans = std::min(ans,v[i]/temp);
  }
  cout << ans;
  return 0;
}
