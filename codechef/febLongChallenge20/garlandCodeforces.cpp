#include<bits/stdc++.h>
using namespace std;

#define fori(i,a,b) for (long int i = a; i <= b ; ++i)
#define ford(i,a,b) for(long int i = a;i >= b ; --i)
#define mk make_pair
#define mod 1000000007
#define pb push_back
#define ll long long
#define rnd mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().count())

int dp[105][2];

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;

  vector<int> p(n+1,-1);
  fori(i,1,n) {
    cin >> p[i];
    if (p[i] == 0)
      p[i] = -1;
    else
      p[i] = p[i]%2;
  }

  dp[1][0] = dp[1][1] = 0;
  //if p[i] != -1 dp[i][0] = dp[i][1];

  for(int i = 2; i <= n; i++) {
    if (p[i] == -1) {
      if (p[i-1] != -1) {
        dp[i][0] = dp[i-1][0]+ ~(p[i-1]^1);
        dp[i][1] = dp[i-1][1]+ ~(p[i-1]^0);
      } else {
        dp[i][0] = min(dp[i-1][0], dp[i-1][1]+1);
        dp[i][1] = min(dp[i-1][1], dp[i-1][0]+1);
      }
    } else {
      if (p[i-1] != -1) {
        dp[i][0] = dp[i][1] = dp[i-1][0]+(p[i-1]^p[i]);
      } else {
        dp[i][0] = min(dp[i-1][0]+~(p[i]^1), dp[i-1][1]+~(p[i]^0));
        dp[i][1] = dp[i][0];
       }
    }
  }

  cout << min(dp[n][0], dp[n][1]) << endl;

  return 0;
}
