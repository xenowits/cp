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
  int n,k;
  //cin >> n;
  cin >> n >> k;
  vector<ll> dp(n+1);
  dp[n] = 1;
  ll ans = 1,ans_cost = 0;
  ford(i,n-1,0)
  {
    dp[i] = ((i+1)*dp[i+1])/(n-i);
    //cout << i << " " << dp[i] << endl;
    if (ans+dp[i] >= k)
    {
      ans += (k-ans);
      ans_cost += dp[i]*(n-i);
      cout << "answer is " << ans << " and ans_cost is " << ans_cost << endl;
      break;
    }
    else
    {
      ans += dp[i];
      ans_cost += dp[i]*(n-i);
      cout << "answer is " << ans << " and ans_cost is " << ans_cost << endl;
    }
  }
  cout << "answer is " << ans << " and ans_cost is " << ans_cost << endl;
  return 0;
}
