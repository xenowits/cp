#include<bits/stdc++.h>
using namespace std;

#define fori(i,a,b) for (int i = a; i <= b ; ++i)
#define ford(i,a,b) for(int i = a;i >= b ; --i)
#define mk make_pair
#define mod 1000000007
#define pb push_back
#define ll long long

ll dp[3001][3001];

vector<ll> divisors(long n)
{
  vector<ll> v;
  for (int i = 2; i < sqrt(n) ; ++i)
  {
    if (n%i == 0)
    {
        v.pb(i);
    }
  }
  for (int x : v)
    cout << x << " ";
  cout << endl;
  return v;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t>0)
  {
    int N,p;
    cin >> N;
    p = N/2;
    if (N&1 == 1)
    {
      cout << -1 << endl;
      continue;
    }
    ll max_abc = -1;
    fori(i,1,N)
      fori(j,i+1,N)
        dp[i][j] = -1;
    for (int a = 2; a <= N && a != p && a !=2*p; ++a)
    {
      ll b = (2*p*(a-p))/(a-2*p);
      ll c = N-(a+b);
      if (dp[a][c] != -1 || a*a + b*b == c*c )
      {
        if (a < b && b < c && c < N)
        {
          ll d = a*b*c;
          //cout << a << " " << b << " " << c << endl;
          if (d > max_abc)
            max_abc = d;
          dp[a][c] = max(d,dp[a][c]);
        }
      }
    }
    cout << max_abc << endl;
    t-=1;
  }
    return 0;
}
