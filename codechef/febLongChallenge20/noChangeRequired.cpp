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

  int t;
  cin >> t;

  while (t--) {
    int n, p;
    cin >> n >> p;
    vector<int> v(n);
    fori(i,0,n-1) {
      cin >> v[i];
    }
    //reverse(v.begin(), v.end());
    vector<int> ans;
    ford(i,n-1,0) {
      if (p == 0) {
        ans.pb(0);
      } else if (p%v[i] != 0) {
        int temp = ceil((p+0.0)/v[i]);
        ans.pb(temp);
        p = 0;
      } else {
        ans.pb(p/v[i]-1);
        p = v[i];
      }
    }
    if (p != 0) {
      cout << "NO" << endl;
    } else {
      cout << "YES" << endl;
      ford(i,n-1,0) {
        cout << ans[i] << " ";
      }
      cout << endl;
    }
  }

  return 0;
}