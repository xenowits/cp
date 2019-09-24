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

  ll n,temp;
  cin >> n;

  vector<pi> v;
  fori(i,1,n)
  {
    cin >> temp;
    v.pb(mk(temp,i));
  }

  sort(v.begin(), v.end());
  reverse(v.begin(), v.end());

  ll ans = 0, hell = 0;

  fori(i,0,n-1)
  {
    ans += (v[i].fs*hell);
    hell += 1;
  }

  cout << ans+n << endl;

  fori(i,0,n-1)
    cout << v[i].sc << " ";

  return 0;
}
