#include<bits/stdc++.h>
using namespace std;

#define fori(i,a,b) for (int i = a; i <= b ; ++i)
#define ford(i,a,b) for(int i = a;i >= b ; --i)
#define mk make_pair
#define mod 1000000007
#define pb push_back
#define ll long long

ll dp[3001][3001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    fori(i,1,3000)
      fori(j,1,3000)
        dp[i][j] = -1;
    while (t>0)
    {
      int N;
      cin >> N;
      ll max_abc = -1;
      bool jaan = true;
      for (int m = 2;;++m)
      {
        for (int n = 1;;++n)
        {
          if (N == 2*m*(m+n) && dp[m][n] == -1)
          {
            max_abc = (m*m - n*n)*2*m*n*(m*m + n*n);
            dp[m][n] = max_abc;
          }
          if ((m*m + n*n > N))
          {
            jaan = false;
            break;
          }
        }
        if (!jaan)
          break;
      }
      cout << max_abc << endl;
      t-=1;
    }
    return 0;
}
