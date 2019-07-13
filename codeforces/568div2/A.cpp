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

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll a,b,c,d;
  cin >> a >> b >> c >> d;
  vector<int> v;
  v.pb(a);v.pb(b);v.pb(c);
  sort(v.begin(),v.end());
  a = v[0];b= v[1]; c= v[2];
  ll ans = 0;
  if (b-a <= d)
    ans += d-(b-a);
  if (c-b <= d)
    ans += d-(c-b);
  cout << ans << endl;
  return 0;
}
