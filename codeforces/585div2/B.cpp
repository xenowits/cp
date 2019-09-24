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

  ll n;
  cin >> n;

  vector<int> a(n+1);

  fori(i,1,n)
  {
    cin >> a[i];
    if (a[i] < 0)
      a[i] = -1;
    else
      a[i] = 1;
  }

  vector<int> cnt(n+1,0), evendp(n+1,0), odddp(n+1,0);
  evendp[0] = 1;

  fori(i,1,n)
  {
    if (a[i] == -1)
      cnt[i] = cnt[i-1]+1;
    else
      cnt[i] = cnt[i-1];

    if (cnt[i]%2 == 0)
      evendp[i] = evendp[i-1]+1;
    else
      evendp[i] = evendp[i-1];

    if (cnt[i]%2 == 1)
      odddp[i] = odddp[i-1]+1;
    else
      odddp[i] = odddp[i-1];

  }

  ll ans = 0;

  fori(i,1,n)
  {
    if (cnt[i]%2 == 0)  //even hoo
    {
      ans += odddp[i-1];
    }
    else
    {
      ans += evendp[i-1];
    }
    //cout << i << " " << ans << endl;
  }

  ll rem = n*(n+1)/2 - ans;
  cout << ans << " " << rem << endl;

  return 0;
}
