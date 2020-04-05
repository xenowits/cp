//xenowitz -- Jai Shree Ram
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
#define pi pair<long long int,long long int>
#define sc second
#define fs first


int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  ll t = 1;
  cin >> t;
  while(t--) {
      string str;
      cin >> str;
      vector<int> positions;
      positions.pb(0);
      int n = str.length();
      fori(i,0,n-1) {
        if (str[i] == 'R') {
          positions.pb(i+1);
        }
      }
      positions.pb(n+1);
      // for(int x : positions) {
      //   cout << x << " heh ";
      // }
      // cout << endl;
      n = positions.size();
      //cout << n << " is the n" << endl;
      int ans = INT_MIN;
      fori(i,0,n-2) {
        ans = max(ans,positions[i+1]-positions[i]);
      }
      cout << ans << endl;
  }
  return 0;
}
