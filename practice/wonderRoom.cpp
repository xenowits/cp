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
  if (sz < 3) {
    cout << "YES" << endl;
    exit(0);
  }

  fori(i,1,sz-2) {
    if (s[i] == 'A') {
      if (s[i-1] == 'B' && s[i+1] == 'B') {
        cout << "NO" << endl;
        exit(0);
      }
    } else if (s[i] == 'B') {
      if (s[i-1] == 'A' && s[i+1] == 'A') {
        cout << "NO" << endl;
        exit(0);
      }
    }
  }

  fori(i,1,sz-1) {
    if ((s[i-1] == 'A' && s[i] == 'B') || (s[i-1] == 'B' && s[i] == 'A')) {
      // cout << i << endl;
      cout << "YES" << endl;
      exit(0);
    }
  }

  cout << "NO" << endl;

	return 0;
}
