#include<bits/stdc++.h>
using namespace std;

#define fori(i,a,b) for (long long int i = a; i <= b ; ++i)
#define ford(i,a,b) for(long long int i = a;i >= b ; --i)
#define mk make_pair
#define mod 1000000000
#define pb push_back
#define ll long long
#define MAXN 300001
#define rnd mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().cnt())
#define pi pair<long long int,long long int>
#define sc second
#define fs first

void solve(ll n, ll k,vector<int> v)
{
  ll l = 1, r = 1000000000,mid;
  while(l < r)
  {
    mid = l+(r-l)/2;
    if(cntr(mid,v))
  }
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  ll n,k;
  cin >> n >> k;
  vector<ll> v(n+1);

  fori(i,1,n)
    cin >> v[i];

  solve(n,k,v);

  return 0;
}
