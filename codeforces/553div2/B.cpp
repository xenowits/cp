#include<bits/stdc++.h>
using namespace std;

#define fori(i,a,b) for (long int i = a; i <= b ; ++i)
#define ford(i,a,b) for(long int i = a;i >= b ; --i)
#define mk make_pair
#define mod 1000000007
#define pb push_back
#define ll long long

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n,m;
  cin >> n >> m;
  int dp[n+1][m+1];
  bool odd_here = false;
  int par[n+1][m+2];
  int ac_par = 0;
  int odd_count = 0;
  fori(i,1,n)
  {
    int count = 0;
    fori(j,1,m)
    {
      cin >> dp[i][j];
      if (dp[i][j]%2 == 1)
      {
          odd_here = true;
          count += 1;
      }
    }
    if (count >= 1)
      ac_par ^= 1,odd_count += 1;
    dp[i][m+1] = count;
  }
  if (!odd_here)
    cout << "NIE";
  else
  {
    cout << "TAK" << endl;
    if (ac_par == 1)
    {
      fori(i,1,n)
      {
        if (dp[i][m+1] == 0)
        {
          cout << 1 << " ";
          continue;
        }
        else
        {
          fori(j,1,m)
          {
            if (dp[i][j]%2 == 1)
            {
              cout << j << " ";
              break;
            }
          }
        }
      }
    }
    else
    {
      //cout << ac_par << " ahah" << endl;
      int odd_cnt = 0;
      fori(i,1,n)
      {
        if (dp[i][m+1] == 0)
        {
          cout << 1 << " ";
          continue;
        }
        else
        {
          if (odd_cnt == odd_count - 1)
          {
            fori(j,1,m)
            {
              if (dp[i][j]%2 == 0)
              {
                  cout << j << " ";
                  break;
              }
            }
          }
          else
          {
            fori(j,1,m)
            {
              if (dp[i][j]%2 == 1)
              {
                  cout << j << " ";
                  break;
              }
            }
            odd_cnt += 1;
          }
        }
      }
    }
  }
  return 0;
}
