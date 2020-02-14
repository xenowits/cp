//xenowitz -- Jai Shree Ram
#include<bits/stdc++.h>
using namespace std;

#define fori(i,a,b) for (long long int i = a; i <= b ; ++i)
#define ford(i,a,b) for(long long int i = a;i >= b ; --i)
#define mk make_pair
#define mod 998244353
#define pb push_back
#define ll long long
#define ld long double
#define MAXN (ll)1e6+5
#define rnd mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().cnt())
#define pi pair<long long int,long long int>
#define sc second
#define fs first


int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  string s;
  cin >> s;

  int sz = s.length();
  if (sz < 4) {
    cout << "NO" << endl;
    exit(0);
  }
  vector<int> dp1(sz+1,0), dp2(sz+1,0);

  fori(i,0,sz-2) {
    // if (i > 0)
    //   cout << i << " " << dp1[i-1] << " " << dp2[i-1] << endl;
    if (s[i] == 'A' && s[i+1] == 'B') {
      dp1[i] = 1 + dp1[max((ll)0,i-1)];
      dp2[i] = dp2[max((ll)0,i-1)];
      // cout << i << " " << dp1[i] << endl;
      continue;
    } else if (s[i] == 'B' || s[i+1] == 'A') {
      dp2[i] = 1 + dp2[max((ll)0,i-1)];
      dp1[i] = dp1[max((ll)0,i-1)];
      // cout << i << " " << dp2[i] << endl;
      continue;
    }
    dp1[i] = dp1[max((ll)0,i-1)];
    dp2[i] = dp2[max((ll)0,i-1)];
    // cout << i << " " << dp1[i] << " " << dp2[i] << endl;
  }

  // cout << dp1[sz-2] << " " << dp2[sz-2] << endl;

  fori(i,0,sz-2) {
    if (s[i] == 'A' && s[i+1] == 'B') {
      if ((i+1 < sz && dp2[sz-2]-dp2[i+1] > 0) || (i-2 >= 0 && dp2[i-2] > 0)) {
        // cout << i << endl;
        cout << "YES" << endl;
        exit(0);
      }
    } else if (s[i] == 'B' && s[i+1] == 'A') {
      if ((i+1 < sz && dp1[sz-2]-dp1[i+1] > 0) || (i-2 >= 0 && dp1[i-2] > 0)) {
        // cout << i << endl;
        cout << "YES" << endl;
        exit(0);
      }
    }
  }

  cout << "NO" << endl;

	return 0;
}
