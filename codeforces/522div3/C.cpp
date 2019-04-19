#include<bits/stdc++.h>
using namespace std;

#define fori(i,a,b) for (long int i = a; i <= b ; ++i)
#define ford(i,a,b) for(long int i = a;i >= b ; --i)
#define mk make_pair
#define mod 1000000007
#define pb push_back
#define ll long long

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll a,b,c;
  cin >> a >> b >> c;
  ll ans = min(a/3, min(b/2,c/2));
  a -= ans*3;
  b -= ans*2;
  c -= ans*2;
  ans *= 7;
  int temp[8] = {0, 1, 2, 3, 1, 3, 2, 1};
  int mx = 0;
  for (int i = 1; i <= 7; i++)
  {
      int x1 = a, x2 = b, x3 = c;
      int j = i;
      int t = 0;
      while (x1 >= 0 && x2 >= 0 && x3 >= 0)
      {
          if (temp[j] == 1) x1--;
          if (temp[j] == 2) x2--;
          if (temp[j] == 3) x3--;
          t++;
          j++;
          if (j == 8) j = 1;
      }
      if (x1 < 0 || x2 < 0 || x3 < 0) t--;

      mx = max(mx, t);
  }
  cout << ans + mx << endl;
  return 0;
}
