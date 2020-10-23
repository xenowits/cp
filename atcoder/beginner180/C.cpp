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

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  ll n;
  cin >> n;
  vector<ll> ans;

  //calculate no of factors
  for (ll factor = 1; factor*factor <= n; factor += 1) {
      if (n%factor == 0) {
          ans.pb(factor);
          if (factor*factor != n) {
              //n is NOT a perfect square
              ans.pb(n/factor);
          }
      }
  }

  sort(ans.begin(), ans.end());

  for (auto x : ans) {
      cout << x << " ";
  }

  return 0;
}
