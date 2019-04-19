#include<bits/stdc++.h>
using namespace std;

#define fori(i,a,b) for (int i = a; i <= b ; ++i)
#define ford(i,a,b) for(int i = a;i >= b ; --i)
#define mk make_pair
#define mod 1000000007
#define pb push_back
#define ll long long

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<long> s(n+1);
    vector<long> c(n+1);
    fori(i,1,n)
    {
      cin >> s[i];
    }
    // fori(i,1,n)
    // {
    //   cin >> c[i];
    // }
    int k = 4;
    long dp[k+1][n+1];
    memset(dp, 0, sizeof (dp));
    fori(i,1,n)
      dp[1][i] = 1;
    for (int l = 2; l <= k; ++l)
    {
      for (int i = l; i <= n ; ++i)
      {
        dp[l][i] = 0;
        for (int j = l-1 ; j < i ; ++j)
        {
          if (s[j] < s[i])
          {
            dp[l][i] += dp[l-1][j];
          }
        }
      }
    }
    int sum = 0;
    for (int i = 1; i <= n; ++i)
      sum += dp[k][i];
    cout << sum;
    return 0;
}
