//xenowitz -- Jai Shree Ram
#include<bits/stdc++.h>
using namespace std;

#define fori(i,a,b) for (long int i = a; i <= b ; ++i)
#define ford(i,a,b) for(long int i = a;i >= b ; --i)
#define mk make_pair
#define mod 1000000007
#define pb push_back
#define eb emplace_back
#define vec vector<long long int>
#define ll long long
#define rnd mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().count())
#define pi pair<long long int,long long int>
#define sc second
#define fs first
#define stf shrink_to_fit

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  ll n, ans = 0;
  cin >> n;

  fori(a, 1, n) {
     for(ll b = 1; a*b < n; b += 1) {
         ans += 1;
     }
  }

  cout << ans << endl;

  return 0;
}
