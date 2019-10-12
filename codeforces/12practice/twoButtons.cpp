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
#define s second
#define f first

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll n,m;
  cin >> n >> m;
  if (n >= m)
  {
    cout << n-m << endl;
  }
  ll x = 0;ll tp = n;
  fori(i,0,100)
  {
    if (tp == m)
    {
      cout << x << endl;
      exit(0);
    }
    else if (tp < m && tp*2 > m)
    {
      break;
    }
    tp *= 2;
    x += 1;
  }
  if (tp*2 == m)
  {
    cout << x+1 << endl;
    exit(0);
  }
  if (n <= m && m%2 == 0)
  {
    cout << std::min(x+1+2*tp-m, x+1+tp-m/2) << endl;
  }
  else if(n <= m && m%2 != 0)
  {
    cout << x+1+2*tp-m;
  }
  return 0;
}
