#include<bits/stdc++.h>
using namespace std;

#define fori(i,a,b) for (long long int i = a; i <= b ; ++i)
#define ford(i,a,b) for(long long int i = a;i >= b ; --i)
#define mk make_pair
#define mod 1000000007
#define pb push_back
#define ll long long
#define MAXN 300001
#define rnd mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().cnt())
#define pi pair<long long int,long long int>
#define sc second
#define fs first

ll dp[105], dp2[105];

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n,k,d;
  cin >> n >> k >> d;

  fori(i,1,k)
  {
    dp[i] = 1;
  }
  // total ways
  fori(sum,1,n)
  {
    for(int j = 1;j <= k; ++j)
    {
      if (sum >= j)
      {
        dp[sum] = (dp[sum] + dp[sum-j])%mod;
      }
    }
  }
  //cout << dp[n] << endl;
  //all values less than d
  fori(i,1,d-1)
    dp2[i] = 1;
  fori(sum,1,n)
  {
    for(int j = 1;j < d; ++j)
    {
      if (sum >= j)
      {
        dp2[sum] = (dp2[sum]+dp2[sum-j])%mod;
      }
    }
  }
  cout << (dp[n]%mod-dp2[n]%mod+mod)%mod;
  return 0;
}
