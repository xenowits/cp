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
#define pi pair<int,int>
#define sc second
#define fs first


int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll q;
  cin >> q;
  while (q)
  {
    ll n,m;
    cin >> n >> m;
    char mat[n+1][m+1];
    fori(i,1,n)
    {
      fori(j,1,m)
        cin >> mat[i][j];
    }
    vector<ll> vr(n+1);
    fori(i,1,n)
    {
      ll nc = 0;
      fori(j,1,m)
      {
        if (mat[i][j] == '*')
        {
            nc += 1;
        }
      }
      vr[i] = nc;
    }
    vector<ll> vc(m+1);
    fori(j,1,m)
    {
      ll nc = 0;
      fori(i,1,n)
      {
        if (mat[i][j] == '*')
          nc += 1;
      }
      vc[j] = nc;
    }
    ll ans = INT_MAX;
    fori(i,1,n)
    {
      fori(j,1,m)
      {
        if (mat[i][j] == '.')
        {
          ans = min(ans,m - vr[i] + n - vc[j] - 1);
        }
        else
          ans = min(ans, m - vr[i] + n - vc[j]);
      }
    }
    cout << ans << endl;
    q-=1;
  }
  return 0;
}
