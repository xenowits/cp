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

ll arr[1005][1005];

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  ll n;
  cin >> n;
  vector<ll> v(n+1), ans(n+1,0);
  fori(i,1,n)
  {
    ll cnt = 0;
    fori(j,1,n)
    {
      cin >> arr[i][j];
      cnt += arr[i][j];
    }
    ans[i] = cnt;
  }

  v[2] = (ll)sqrt((arr[1][2]*arr[2][3])/arr[1][3]);
  // ll S, x = 0;
  // fori(i,1,n)
  // {
  //   x += arr[2][i];
  // }
  // S = x/v[2]+v[2];
  v[1] = arr[1][2]/v[2];
  fori(i,1,n)
  {
    if (i <= 2)
      cout << v[i] << " ";
    else
    {
      cout << arr[1][i]/v[1] << " ";
    }
  }
  return 0;
}
