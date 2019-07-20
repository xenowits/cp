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
#define f first
#define s second

ll dp[1001][1001];

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  string s, x;
  cin >> s >> x;
  ll n1 = s.length(), n2 = x.length();
  fori(i,0,n2)
    dp[0][i] = 0;
  fori(i,0,n1)
    dp[i][0] = 1;
  fori(j,1,n2)
  {
    fori(i,1,n1)
    {
      dp[i][j] = dp[i-1][j];
      if (x[n2-j] == s[n1-i])
      {
        dp[i][j] += dp[i][j-1];
      }
    }
  }
  cout << dp[n1][n2] << endl;
  return 0;
}
