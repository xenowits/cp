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
  int w,h,u1,d1,u2,d2;
  cin >> w >> h >> u1 >> d1 >> u2 >> d2;
  if (d1 > d2)
  {
    std::swap(d1,d2);
    std::swap(u1,u2);
  }
  ll ans = w;
  //cout << w << h << u1 << d1 << u2 << d2 << endl;
  if (h > d2)
  {
      while (h > d2)
      {
        ans += h;
        h-=1;
      }
  }
  //cout << "1 " << ans << h << u1 << d1 << u2 << d2 << endl;
  if (h == d2)
  {
    ans -= u2;
    ans += h;
    if (ans < 0)
      ans = 0;
    // ans = std::max(0,ans);
    h-=1;
  }
  //cout << ans << h << u1 << d1 << u2 << d2 << endl;
  if (h > d1)
  {
    while (h > d1)
    {
      ans += h;
      h-=1;
    }
  }
  //cout << ans << h << u1 << d1 << u2 << d2 << endl;
  if (h == d1)
  {
    ans -= u1;
    ans += h;
    if (ans < 0)
      ans = 0;
    // ans = std::max(0,ans);
    h-=1;
  }
  //cout << ans << h << u1 << d1 << u2 << d2 << endl;
  while (h > 0)
  {
    ans += h;
    h-=1;
  }
  cout << ans << endl;
  return 0;
}
