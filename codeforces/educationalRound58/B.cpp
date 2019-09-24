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

  int q;
  ll l, r, d;
  cin >> q;
  while (q--)
  {
    cin >> l >> r >> d;
    ll x = l/d, y = r/d;
    if (d < l)
      cout << d << endl;
    else
      cout << d*(y+1) << endl;

    // if (x*d < l && x > 0)
    //   cout << x*d << endl;
    // else
    //   cout << (y+1)*d << endl;
  }

  return 0;
}
