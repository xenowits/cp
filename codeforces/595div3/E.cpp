#include<bits/stdc++.h>
using namespace std;

#define fori(i,a,b) for (long int i = a; i <= b ; ++i)
#define ford(i,a,b) for(long int i = a;i >= b ; --i)
#define mk make_pair
#define mod 1000000007
#define pb push_back
#define vec vector<long long int>
#define ll long long
#define rnd mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().count())
#define pi pair<long long int,long long int>
#define sc second
#define fs first
#define MAXN 200005

ll dp[MAXN][2];

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  ll n, c;
  cin >> n >> c;

  vector<ll> a(n), b(n);

  fori(i,1,n-1)
     cin >> a[i];

  fori(i,1,n-1)
    cin >> b[i];


  //bit 0 means last step was by stairs
  //bit 1 means last step was by elevator
  fori(i,1,n-1)
  {
    dp[i+1][0] = a[i]+min(dp[i][0], dp[i][1]);
    if (i == 1)
      dp[i+1][1] = b[i]+c;
    else
      dp[i+1][1] = b[i]+min(c+dp[i][0], dp[i][1]);
  }

  fori(i,1,n)
    cout << min(dp[i][0], dp[i][1])  << " ";
  cout << endl;

  return 0;
}
