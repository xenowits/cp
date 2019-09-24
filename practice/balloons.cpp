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

  ll n, x, y;
  cin >> n >> x >> y;

  string s;
  cin >> s;

  ll zeroes = 0, ones = 0;
  fori(i,0,n-1)
  {
    // if (i == 0)
    // {
    //   if (s[i] == '0')
    //     zeroes += 1;
    //   else
    //     ones += 1;
    // }
    if (i == 0 || s[i] != s[i-1])
    {
      if (s[i] == '0')
        zeroes += 1;
      else
        ones += 1;
    }
  }
  //cout << ones << " " << zeroes << endl;
  if (zeroes == 0)
    cout << 0 << endl;
  else
    cout << (zeroes-1)*min(x,y)+y << endl;

  return 0;
}
