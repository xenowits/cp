#include<bits/stdc++.h>
using namespace std;

#define fori(i,q,r) for (long int i = q; i <= r ; ++i)
#define ford(i,q,r) for (long int i = q; i >= r ; --i)
#define mk make_pair
#define mod 1000000007
#define pb push_back
#define vec vector<long long int>
#define ll long long
#define rnd mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().count())
#define pi pair<int,int>
#define sc second
#define fs first

ll n;

ll dp[101][101], mat[101][101];

void initialiseDP()
{
  fori(i,1,n)
    fori(j,1,n)
      dp[i][j] = -1;
}

void printer()
{
  fori(i,1,n)
  {
    fori(j,1,n)
      cout << dp[i][j] << " ";
    cout << endl;
  }
  cout << endl;
}

ll solve(int a, int b)
{
  
  if (dp[a][b] != -1)
    return dp[a][b];

  if (a > 1 && mat[a-1][b] == (mat[a][b] + 1) )
    return dp[a][b] = 1 + solve(a-1,b);

  if (a < n && mat[a+1][b] == (mat[a][b] + 1) )
    return dp[a][b] = 1 + solve(a+1,b);

  if (b > 1 && mat[a][b-1] == (mat[a][b] + 1) )
    return dp[a][b] = 1 + solve(a,b-1);

  if (b < n && mat[a][b+1] == (mat[a][b] + 1) )
    return dp[a][b] = 1 + solve(a,b+1);

  return dp[a][b] = 1;
}

void findMax()
{
  ll ans = INT_MIN;
  fori(i,1,n)
  {
    fori(j,1,n)
    {
      if (dp[i][j] == -1)
      {
        solve(i,j);
        printer();
      }
      ans = max(ans,dp[i][j]);
    }
  }
  cout << ans << endl;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n;

  fori(i,1,n)
    fori(j,1,n)
      cin >> mat[i][j];

  initialiseDP();

  //cout << solve(1,1) << endl;

  findMax();

  return 0;
}
