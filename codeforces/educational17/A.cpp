#include<bits/stdc++.h>
using namespace std;

#define fori(i,a,b) for (long int i = a; i <= b ; ++i)
#define ford(i,a,b) for(long int i = a;i >= b ; --i)
#define mk make_pair
#define mod 1000000007
#define pb push_back
#define vec vector<long long int>
#define ll long long int
#define rnd mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().count())
#define pi pair<long long int,long long int>
#define sc second
#define fs first

vector<ll> factors;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll n,k;
  cin>>n>>k;
  ll temp = sqrt(n);
  for(ll i=1; i<=temp; i++)
  {
    if(n%i==0)
    {
      factors.pb(i);
      if (i*i != n)
        factors.pb(n/i);
    }
  }

  sort(factors.begin(), factors.end());

  if (factors.size() < k)
  {
    cout << -1 << endl;
    exit(0);
  }

  cout << factors[k-1] << endl;

  return 0;
}
