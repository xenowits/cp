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

  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;

    vector<int> a(n+1,0), b(n+1,0);
    fori(i,1,n)
      cin >> a[i];
    fori(i,1,n)
      cin >> b[i];

    bool allzero = true;
    fori(i,1,n) {
      a[i] -= b[i];
      if (a[i] != 0)
        allzero = false;
    }

    if (allzero) {
      cout << "YES" << endl;
      continue;
    }

    bool started = false;
    int k = -1;

    fori(i,1,n) {
      if (!started && a[i] != 0) {
        started = !started;
        k = -a[i];
        a[i] += k;
      } else if (started && a[i] != 0) {
        a[i] += k;
      } else if (started && a[i] == 0) {
        break;
      }
    }

    bool alldone = true;

    fori(i,1,n) {
      if (a[i] != 0) {
        alldone = false;
        break;
      }
    }

    if (k > 0 && alldone == true) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }

  }

	return 0;
}
