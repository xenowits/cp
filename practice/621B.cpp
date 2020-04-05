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
#define MAXN (ll)1e5+5
#define rnd mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().cnt())
#define pi pair<long long int,long long int>
#define sc second
#define fs first

vector<vector<int> > prefix(MAXN, vector<int>(26,0));

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  t = 1;

  while (t--) {
    string str;
    cin >> str;
    map<string,ll> mp;
    int n = str.length();

    fori(i,0,n-1) {
      string some = "";
      some += str[i];
      mp[some] += 1;
      if (i > 0) {
        fori(j,0,25) {
          prefix[i][j] += prefix[i-1][j];
        }
      }
      prefix[i][str[i]-'a'] += 1;
    }

    for(int i = 1; i < n; i++) {
      for (char ch2 = 'a'; ch2 <= 'z'; ch2++) {
        // string temp = ch2+""+str[i];
        string temp = "";
        temp += ch2;
        temp += str[i];
        mp[temp] += (prefix[i-1][ch2-'a']);
      }
    }

    ll ans = INT_MIN;
    for(auto x : mp) {
      ans = max(ans,x.sc);
      // cout << x.fs << " " << x.sc << endl;
    }
    cout << ans << endl;
  }
	return 0;
}
