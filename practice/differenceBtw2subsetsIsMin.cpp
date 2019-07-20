#include<bits/stdc++.h>
using namespace std;

#define fori(i,a,b) for (int i = a; i <= b ; ++i)
#define ford(i,a,b) for(int i = a;i >= b ; --i)
#define mk make_pair
#define mod 1000000007
#define pb push_back
#define ll long long
#define MAXN 100001
#define rnd mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().cnt())
#define pi pair<long long int,long long int>

bool dp[100001][1001];

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll n;
  cin >> n;
  vector<ll> v(n+1);
  ll sum = 0;
  fori(i,1,n)
  {
    cin >> v[i];
    dp[i][0] = 1;
    sum += v[i];
  }
  dp[0][0] = 1;
  fori(i,1,n)
  {
    int x = v[i];
    fori(j,0,sum)
    {
      dp[i][j] += dp[i-1][j];
      if (dp[i-1][j] > 0 && (j+x <= sum) )
        dp[i][j+x] += 1;
    }
  }

  fori(i,0,n)
  {
    fori(j,0,sum)
    {
      cout << dp[i][j] << " ";
    }
    cout << endl;
  }

  ford(j,sum/2,0)
  {
    fori(i,1,n)
    {
      if (dp[i][j])
      {
        cout << sum-2*j << endl;
        exit(0);
      }
    }
  }

  return 0;
}
