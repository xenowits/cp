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

  int n;
  cin >> n;

  vector<ll> v(n);
  ll ans, minima = INT_MAX;

  for(int i = 0 ; i < n; ++i)
  {
    cin >> v[i];
    if (i == 0)
      ans = v[i];
    else
      ans = __gcd(ans,v[i]);
    minima = min(minima,v[i]);
  }

  ll finale = 0, tocomp = (ll)sqrt(minima);
  //cout << ans << endl;
  set<ll> st;
  // for(int i = 1;; ++i)
  // {
  //   if (ans*i <= minima)
  //     st.insert(ans*i);
  //   else
  //     break;
  // }

  for (int i = 1; i <= (ll)sqrt(ans); ++i)
  {
    if (ans%i == 0)
    {
      st.insert(i);
      st.insert(ans/i);
    }
  }
  cout << st.size() << endl;
  return 0;
}
