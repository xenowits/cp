#include<bits/stdc++.h>
using namespace std;

#define fori(i,a,b) for (int i = a; i <= b ; ++i)
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

  int n = s.length();

  vector<int> counter(n+1,0), parity(n,0);
  int m, l, r;
  cin >> m;
  
  fori(i,1,m) {
    cin >> l;
    counter[l] += 1;
    counter[n-l+2] -= 1;
  }

  fori(i,1,n) {
    counter[i] += counter[i-1];
    parity[i] = (counter[i]%2);
  }

  string t;
  t.resize(n);
  fori(i,1,n) {
  //  cout << i << " " << parity[i] << endl;
    if (parity[i] == 0) {
      t[i-1] = s[i-1];
    } else {
      t[i-1] = s[n-i];
    }
  }

  cout << t << endl;

  return 0;
}
