#include <bits/stdc++.h>
using namespace std;

vector<long long> v(3005,0);
long long dp[3003][3003];

long solve(int i, int j, int chance)
{
  if (dp[i][j] != 0)
    return dp[i][j];
  if (i == j && chance == 0)
  {
    return dp[i][j] = v[i];
  }
  else if (i == j && chance == 1)
    return dp[i][j] = -(v[i]);
  else if (chance == 0)
  {
    return dp[i][j] = max(v[i]+solve(i+1,j,1),v[j]+solve(i,j-1,1));
  }
  else if (chance == 1)
  {
    return dp[i][j] = min(-v[i]+solve(i+1,j,0),-v[j]+solve(i,j-1,0));
  }
  return 1;
}

int main()
{
  int n;
  cin >> n;

  for (int i = 0 ; i < n;++i)
    cin >> v[i];

  cout << solve(0,n-1,0);
  // for (int i = 0 ; i<6;++i){
  //   for (int j = 0 ; j<6;++j){
  //     cout << dp[i][j] << " ";}
  //   cout << endl;}
  return 0;
}
