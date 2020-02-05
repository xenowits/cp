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

  ll n, m;
  cin >> n >> m;

  vector<ll> a(n+1), b(n+1);

  fori(i,1,n)
    cin >> a[i];
  fori(i,1,n)
    cin >> b[i];

  sort(b.begin()+1, b.end());
  ll ans = INT_MAX;

  // fori(i,1,n)
  //   cout << b[i] << " ";
  // cout << endl;

  fori(i,1,n) {
    ll x = (b[1]-a[i]+m)%m;

    vector<ll> temp = a;
    fori(i,1,n)
      temp[i] = (temp[i]+x)%m;

    sort(temp.begin()+1, temp.end());

    if (temp == b){
      ans = min(ans, x);
    }
  }

  cout << ans << endl;

  return 0;
}
