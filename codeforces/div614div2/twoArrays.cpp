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

ll dp[25][1001];

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, m;
  cin >> n >> m;
  //dp[i][n1] -- means no of ways to construct upto array[i] ending with n1
  //dp[i][n1] = sigma(dp[i-1][n1]+dp[i-1][n1-1]+......)
  //dp[1][n1] = 1

  fori(i,1,n) {
    dp[1][i] = 1;
  }

  fori(i,2,2*m) {
    fori(j,1,n) {
      fori(k,1,j) {
        dp[i][j] = (dp[i][j]+dp[i-1][k])%mod;
      }
    }
  }

  ll ans = 0;
  fori(i,1,n) {
    // cout << i << " " << dp[2*m][i] << endl;
    ans = (ans+dp[2*m][i])%mod;
  }
  cout << ans%mod << endl;
  return 0;
}
