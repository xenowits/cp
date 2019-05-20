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
  ll n;
  cin >> n;
  vector<ll> a(n);
  fori(i,0,n-1)
    cin >> a[i];
  sort(a.begin(),a.end());
  ll curr_day, cnt = 0;
  curr_day = 1;
  fori(i,0,n-1)
  {
    if (a[i] >= curr_day)
    {
      curr_day += 1;
      cnt += 1;
    }
  }
  cout << cnt;
  return 0;
}
