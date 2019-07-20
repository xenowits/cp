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
  ll n,k;
  cin >> n >> k;
  vector<int> v(k+1,0);
  ll tmp;
  fori(i,0,n-1)
  {
    cin >> tmp;
    v[tmp] += 1;
  }
  ll ans = 0;
  fori(i,1,k)
  {
    if (v[i]%2 == 1)
      ans += 1;
  }
  cout << n-ans/2;
  return 0;
}
