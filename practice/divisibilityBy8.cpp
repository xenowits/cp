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

  set<string> st;

  fori(i,0,125) {
    st.insert(to_string(8*i));
  }
  int sz = s.length();
  fori(i,0,sz-1) {
    if (s[i] == '0' || s[i] == '8') {
      cout << "YES" << endl << s[i] << endl;
      exit(0);
    }
  }

  fori(i,0,sz-2) {
    fori(j,i+1,sz-1) {
      string t = "";
      t += s[i];
      t += s[j];
      if (st.find(t) != st.end()) {
        cout << "YES" << endl << t << endl;
        exit(0);
      }
    }
  }

  string t = "";

  fori(i,0,sz-3) {
    t.pb(s[i]);
    fori(j,i+1,sz-2) {
      t.pb(s[j]);
      fori(k,j+1,sz-1) {
        t.pb(s[k]);
        if (st.find(t) != st.end()) {
          cout << "YES" << endl << t << endl;
          exit(0);
        }
        t.pop_back();
      }
      t.pop_back();
    }
    t.pop_back();
  }

  cout << "NO" << endl;

	return 0;
}
