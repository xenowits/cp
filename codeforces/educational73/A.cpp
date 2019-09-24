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
  ll q;
  cin >> q;

  while (q--)
  {
    ll c, m, x, ans = 0;
    cin >> c >> m >> x;

    ll minima = min(x,min(c,m));
    ans += minima;
    c -= minima;
    m -= minima;
    x -= minima;
    if (c == 0 || m == 0)
    {
      cout << ans << endl;
    }
    else if (x == 0)
    {
      ll maxu = max(c,m), minu = min(c,m);
      if (maxu%2 == 1)
      {
        ll temp = min(maxu/2,minu);
        minu -= temp;
        ans += temp;
        if (minu >= 2)
          ans += 1;
      }
      else
        ans += maxu/2;
      cout << ans << endl;
    }
  }
  return 0;
}
