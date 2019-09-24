#include<bits/stdc++.h>
using namespace std;

#define fori(i,a,b) for (long long int i = a; i <= b ; ++i)
#define ford(i,a,b) for(long long int i = a;i >= b ; --i)
#define mk make_pair
#define mod 998244353
#define pb push_back
#define ll long long
#define MAXN 300001
#define rnd mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().cnt())
#define pi pair<long long int,long long int>
#define sc second
#define fs first

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n,m,k;
  cin >> n >> m >> k;
  int r = 1, c = 1;
  bool flag = 0;    //0 LR
  fori(i,1,k-1)
  {
    int cntr = 0;
    if (c == m-1 && !flag)
    {
      cout << 2 << " " << r << " " << c << " " << r << " " << c+1 << endl;
      r += 1;
      c += 1;
      flag = 1;
    }
    else if (c == m && !flag)
    {
      cout << 2 << " " << r << " " << c << " " << r+1 << " " << c << endl;
      r += 1;
      c -= 1;
      flag = 1;
    }
    else if (c == 2 && flag)
    {
      cout << 2 << " " << r << " " << c << " " << r << " " << c-1 << endl;
      r += 1;
      c -= 1;
      flag = 0;
    }
    else if (c == 1 && flag)
    {
      cout << 2 << " " << r << " " << c << " " << r+1 << " " << c << endl;
      r += 1;
      c += 1;
      flag = 0;
    }
    else if (!flag)      //lr
    {
      cout << 2 << " " << r << " " << c << " " << r << " " << c+1 << endl;
      c += 2;
    }
    else if (flag)      //lr
    {
      cout << 2 << " " << r << " " << c << " " << r << " " << c-1 << endl;
      c -= 2;
    }
  }

  cout << n*m -2*(k-1) << " ";
  while (r <= n)
  {
    if (!flag)
    {
      for(;c <= m; ++c)
        cout << r << " " << c << " ";
      r += 1;
      flag = !flag;
    }
    if (r > n)
      exit(0);
    if (c == m+1)
      c = m;
    if (flag)
    {
      for(; c >= 1; --c)
        cout << r << " " << c << " ";
      r += 1;
      flag = !flag;
    }
    if (c == 0)
      c = 1;
  }
  return 0;
}
