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

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  ll t;
  cin >> t;

  while (t--)
  {
    ll n, sig;
    cin >> n >> sig;
    if (n == 1 && sig != 0)
    {
      cout << -1 << endl;
    }
    else if (n == 1 && sig == 0)
    {
      cout << 1 << endl;
    }
    else
    {
      double ans = ((double)(n*sig))/((double)sqrt(n-1));
      fori(i,1,n)
      {
        if (i == 1)
        {
          cout << fixed << setprecision(6) << ans << " ";
        }
        else if (i == n)
          cout << 0 << endl;
        else
          cout << 0 << " ";
      }
    }
  }

  return 0;
}
