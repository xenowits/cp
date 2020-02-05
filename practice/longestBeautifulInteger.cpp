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

  ll n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  vector<int> a(n+1,0), b(n+1,0);
  fori(i,1,n) {
    a[i] = s[i-1]-'0';
    if (i%k)
      b[i] = a[i%k];
    else
      b[i] = a[k];
    //cout << a[i] << " " << b[i] << endl;
  }

  bool flag = true;

  fori(i,1,n) {
    if (a[i] == b[i])
      continue;
    flag = a[i] < b[i];
    break;
  }
  //flag true means no problem if we keep the original set of k
  //digits
  if (flag) {
    cout << n << endl;
    fori(i,1,n) {
      cout << b[i];
    }
    return 0;
  }
  //else find the last non-9 number in the first k digits
  //increment it with 1 and make next digits = 0
  ford(i,k,1) {
    if (b[i] < 9) {
      b[i] += 1;
      for (int j = i+1; j <= k; j++) {
        b[j] = 0;
      }
      break;
    }
  }

  fori(i,1,k) {
    for(int j = 1; (i+j*k) <= n; j++) {
      b[i+j*k] = b[i];
    }
  }

  cout << n << endl;
  fori(i,1,n) {
    cout << b[i];
  }

  return 0;
}
