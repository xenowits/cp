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
  ll n;
  cin >> n;
  vector<ll> v(n+1);vector<pi> change_vector, zero_vector;
  //ll pos = 0, neg = 0, zer = 0;
  fori(i,1,n)
  {
    cin >> v[i];
    if (v[i] >= 0)
      v[i] = -v[i]-1;
    change_vector.pb(mk(v[i],i));
  }
  vector<ll> ans_v = v;
  if (n&1)    ////n is odd
  {
    sort(change_vector.begin(), change_vector.end());
    change_vector[0].first = -change_vector[0].first-1;
    fori(i,0,n)
      ans_v[change_vector[i].second] = change_vector[i].first;
    fori(i,1,n)
      cout << ans_v[i] << " ";
    cout << endl;
  }
  else
  {
    ////n is even
    fori(i,1,n)
      cout << ans_v[i] << " ";
    cout << endl;
  }
  return 0;
}
