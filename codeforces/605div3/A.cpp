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

  int q;
  cin >> q;

  while (q--) {
    ll a, b, c, an, bn, cn;
    cin >> a >> b >> c;
    ll ans = INT_MAX;
    for (int i = -1; i <= 1; i++) {
      for (int j = -1; j <= 1; j++) {
        for (int k = -1; k <= 1; k++) {
          an = a+i;
          bn = b+j;
          cn = c+k;
          ans = min(ans, abs(an-bn)+abs(bn-cn)+abs(an-cn));
        }
      }
    }
    cout << ans << endl;
  }

  return 0;
}
