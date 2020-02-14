#include<bits/stdc++.h>
using namespace std;

#define fori(i,a,b) for (long long int i = a; i <= b ; ++i)
#define ford(i,a,b) for(long long int i = a;i >= b ; --i)
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

  int n;
  cin >> n;
  vector<ll> v(n+1);
  fori(i,1,n)
    cin >> v[i];
  if (n < 3)
  {
    cout << n << endl;
    exit(0);
  }
  vector<ll> vp(n+1,0);
  fori(i,3,n)
  {
    if (v[i] == (v[i-1]+v[i-2]))
    {
      vp[i] = 1;
    }
  }
  ll ans = 2, l = 0;
  fori(i,3,n)
  {
    //cout << vp[i] << " ";
    if (vp[i] == 1) {
      bool flag = false;
      ll j;
      for(j = i; j <= n; j++) {
        // cout << i << " " << vp[i] << endl;
        if (vp[j] == 0) {
          flag = true;
          break;
        }
      }
      // cout << j << endl;
      if (!flag) {
        ans = max(ans, 2+n-i+1);
        break;
      } else {
        ans = max(ans, 2+j-i);
        i = j;
      }
    }
  }
  cout << ans << endl;
  return 0;
}
