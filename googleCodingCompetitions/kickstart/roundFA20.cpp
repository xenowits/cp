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

void solve(ll N, ll X, vector<ll> arr) {
    vector<pi> vp;
    fori (i,0,N-1) {
        vp.pb(mk(ceil(arr[i]/(X + 0.0000000)), i+1));
    }
    sort(vp.begin(), vp.end());
    for (auto x : vp) {
        cout << x.sc << " ";
    }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int T, t = 1;
  cin >> T;

  while (t <= T) {
      ll N, X;
      cin >> N >> X;
      vector<ll> arr(N);
      fori(i,0,N-1) {
          cin >> arr[i];
      }
      cout << "Case #" << t << ": ";
      solve(N, X, arr);
      cout << endl;
      t += 1;
  }

  return 0;
}
