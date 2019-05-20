#include<bits/stdc++.h>
using namespace std;

#define fori(i,a,b) for (long int i = a; i <= b ; ++i)
#define ford(i,a,b) for(long int i = a;i >= b ; --i)
#define mk make_pair
#define mod 1000000007
#define pb push_back
#define ll long long
#define rnd mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().count())

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t,n;
  cin >> t;
  while (t>0)
  {
    cin >> n;
    ll stg = n;
    for (long i = n-1; i >= 1 ; --i)
    {
      stg = ((i*stg)%mod + (i + stg)%mod)%mod;
    }
    cout << stg%mod << endl;
    --t;
  }
  return 0;
}
