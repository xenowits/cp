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
  cin >> n >> k;
  string s;
  cin >> s;
  vector<ll> dp(n+1), last(27,-1);
  fori(i,0,n-1)
  {
    if (i == 0)
    {
      dp[i] = 1;
      last[s[i]-'a'] = 0;
      continue;
    }
    else if (last[s[i]-'a'] >= 1)
    {
      dp[i] = 2*dp[i-1]-dp[last[s[i]-'a']-1];
    }
    else if (last[s[i]-'a'] == 0)
    {
      dp[i] = 2*dp[i-1];
    }
    else if(last[s[i]-'a'] == -1)
    {
        dp[i] = 2*dp[i-1]+1;
    }
    last[s[i]-'a'] = i;
    cout << i << " " << dp[i] << " is the answer" << endl;
  }
  return 0;
}
