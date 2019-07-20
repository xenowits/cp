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
#define fs first
#define sc second

string str1, str2;
ll n1, n2, dp[1001][1001];

ll solveRecursive(int p, int q)
{
  if (p >= n1 || q >= n2)
    return 0;

  else if (str1[p] == str2[q])
  {
    return solve(p+1,q+1);
  }

  else if (str1[p] != str2[q])
  {
    return min( min(1+solve(p+1,q+1), 1+solve(p,q+1)), 1+solve(p+1,q) );
  }

}

void solveDP()
{

  fori(i,0,n1-1)
  {
    fori(j,0,n2-1)
    {
      if (i == 0 && j == 0)
        (str1[i] == str2[j]) ? (dp[0][0] = 0) : (dp[0][0] = 1);

      else if (i == 0 && j > 0)
        dp[i][j] = 1+dp[i][j-1];

      else if (j == 0 && i > 0)
        dp[i][j] = 1+dp[i-1][j];

      else if (str1[i] == str2[j])
        dp[i][j] = dp[i-1][j-1];

      else if (str1[i] != str2[j])
      {
        dp[i][j] = min( min(1+dp[i-1][j], 1+dp[i][j-1]), 1+dp[i-1][j-1]);
      }

    }
  }

  cout << dp[n1-1][n2-1] << endl;

}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> str1 >> str2;

  n1 = str1.length();
  n2 = str2.length();

  solveDP();

  return 0;
}
