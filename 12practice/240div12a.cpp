#include<bits/stdc++.h>
using namespace std;

#define fori(i,a,b) for (long int i = a; i <= b ; ++i)
#define ford(i,a,b) for(long int i = a;i >= b ; --i)
#define mk make_pair
#define mod 1000000007
#define pb push_back
#define ll long long

ll dp[2001][2001];

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n,k;
  cin >> n >> k;
  fori(i,1,n)
    dp[1][i] = 1;
  fori(i,2,k)
  {
    fori(j,1,n)
    {
      if (dp[i-1][j] != 0 && (j+k-1)%j == 0)
      {
        dp[i][j] = 1;
      }
    }
  }
  ll count = 0;
  fori(i,1,n)
  {
    if (dp[k][i] == 1)
      count += 1;
  }
  cout << count;
  return 0;
}
