#include<bits/stdc++.h>
using namespace std;

#define fori(i,a,b) for (long int i = a; i <= b ; ++i)
#define ford(i,a,b) for(long int i = a;i >= b ; --i)
#define mk make_pair
#define mod 1000000007
#define pb push_back
#define ll long long
#define rnd mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().count())
#define pi pair<int,int>

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll t;
  cin >> t;
  while (t>0)
  {
    ll n,k;
    cin >> n >> k;
    if (k<=n)
      cout << (k-1)%mod << endl;
    else
    {
      //cout << "waah bhai" << endl;
      ll i = (k-n-1)/(n-1);
      cout << i << endl;
      cout << k-1 << " " << k*(i+1) << " " << (i*(i+1))/2 << " - " << (n*(i+1)*(i+2))/2 << (k-1) + k*(i+1) + (i*(i+1))/2 - (n*(i+1)*(i+2))/2 << endl;
      if (i&1)      //odd
      {
        cout << ( (k-1)%mod + ( k%mod*((i+1)%mod) )%mod - ( (( n%mod*( (i+1)/2 )%mod )%mod)*( (i+2)%mod ) )%mod + ( i%mod*( (i+1)/2 )%mod )%mod )%mod << endl;
      }
      else          //even
      {
        ll a = (k-1)%mod;
        ll b = ( k%mod*((i+1)%mod) )%mod;
        ll c = ( (( n%mod*( (i+1) )%mod )%mod)*( (i+2)/2 )%mod )%mod;
        ll d = ( (i/2)%mod*( (i+1) )%mod )%mod;
        cout << a << "+" << b << "-" << c << "+" << d << "=" << a+b+d-c << " or " << ( (k-1) + k*(i+1) + (i*(i+1))/2 - (n*(i+1)*(i+2))/2 )%mod << endl;
        cout << ( (k-1)%mod + ( k%mod*((i+1)%mod) )%mod - ( (( n%mod*( (i+1) )%mod )%mod)*( (i+2)/2 )%mod )%mod + ( (i/2)%mod*( (i+1) )%mod )%mod )%mod << endl;
      }
    }
    t-=1;
  }
  return 0;
}
/*
1
1267 8934544
*/
