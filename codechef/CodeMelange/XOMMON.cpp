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
  int n;
  long long int a;
  cin >> n;
  vector<ll> v(n);
  fori(i,0,n-1)
  {
    cin >> v[i];
  }
  vector<ll> dp(n,0);
  vector<ll> xor(n,0);
  dp[0] = 1;
  xor[0] = v[0];
  fori(i,1,n-1)
  {
    fori(j,0,i-1)
    {
      if (v[i]^v[j] >= xor[i] && dp[i] <= dp[j] + 1)
      {
          dp[i] = 1 + dp[j];
          xor[i] = v[i]^v[j];
      }
    }
  }
  return 0;
}
