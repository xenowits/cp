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
#define fs first
#define sc second

ll dp[1001];

void solve(ll n)
{
  fori(i,0,n)
  {
    if (i <= 2)
      dp[i] = i;
    if (i == 3)
      dp[i] = 4;
    else if (i > 3)
    {
      dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
    }
    cout << i << " " << dp[i] << endl;
  }
  cout << dp[n] << endl;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll n;
  cin >> n;

  solve(n);

  return 0;
}
