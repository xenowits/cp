#include<bits/stdc++.h>
using namespace std;

#define fori(i,a,b) for (long long int i = a; i <= b ; ++i)
#define ford(i,a,b) for(long long int i = a;i >= b ; --i)
#define mk make_pair
#define mod 998244353
#define pb push_back
#define ll long long
#define MAXN 300001
#define rnd mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().cnt())
#define pi pair<long long int,long long int>
#define sc second
#define fs first

char arr[1005][1005];

ll dp[3][1001];   //starting at array i and column no j
int n,m,x,y;
vector<ll> bcost(1005,0), wcost(1005,0);

void initialise()
{
  fori(i,1,2)
    fori(j,1,m)
      dp[i][j] = -1;
}

ll solve(int w, int c)
{
  if (c == m+1)
    return 0;

  if (m-c+1 < x)
    return INT_MAX;

  if (dp[w][c] != -1)
    return dp[w][c];

  if (w == 1)
  {
    ll ans = INT_MAX;
    fori(i,x,y)
    {
      if (i+c-1 <= m)
      {
        ll temp = solve(2,c+i);
        ans = min(temp+bcost[c+i-1]-bcost[c-1], ans);
      }
      else if (i+c-1 > m)
        break;
    }
    return dp[w][c] = ans;
  }
  else if (w == 2)
  {
    ll ans = INT_MAX;
    fori(i,x,y)
    {
      if (i+c-1 <= m)
      {
        ll temp = solve(1,c+i);
        ans = min(temp+wcost[c+i-1]-wcost[c-1], ans);
      }
      else if (i+c-1 > m)
        break;
    }
    return dp[w][c] = ans;
  }
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n >> m >> x >> y;

  fori(i,1,n)
    fori(j,1,m)
      cin >> arr[i][j];

  fori(i,1,m)
  {
    int black = 0;
    fori(j,1,n)
      if (arr[j][i] == '#')
        black += 1;
    bcost[i] = black;
    wcost[i] = n-black;
  }

  fori(i,1,m)
  {
    wcost[i] = wcost[i-1]+wcost[i];
    bcost[i] = bcost[i-1] + bcost[i];
  }

  initialise();

  solve(1,1);

  ll ans = dp[1][1];

  initialise();

  solve(2,1);

  ans = min(dp[2][1],ans);
  cout << ans << endl;
  return 0;
}
