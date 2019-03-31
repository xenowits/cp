#include<bits/stdc++.h>
using namespace std;

#define fori(i,a,b) for (int i = a; i <= b ; ++i)
#define ford(i,a,b) for(int i = a;i >= b ; --i)
#define mk make_pair
#define mod 1000000007

long int solve(int arr[], int n, int k)
{
  int dp[n+1] = {0};
  long int maxcount = INT_MIN;
  ford(i,n,1)
  {
    if (i+k <= n)
    {
        dp[i] = arr[i] + dp[i+k];
        if (dp[i] > maxcount)
          maxcount = dp[i];
    }
    else{
      dp[i] = arr[i];
      if (dp[i] > maxcount)
        maxcount = dp[i];
    }
  }
  return maxcount;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t,n,k;
  cin >> t;
  while (t>0)
  {
      cin >> n >> k;
      int arr[n+1];
      fori(i,1,n)
      {
        cin >> arr[i];
      }
      long ans = solve(arr,n,k);
      t-=1;
      if (t>0)
        cout << ans << "\n";
      else
        cout << ans;
  }
  return 0;
}
