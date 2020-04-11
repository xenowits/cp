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

ll binpow(ll a, ll b) {
    ll res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;

	while (t--) {
		int n,u,v;
		cin >> n;
		vector<pi> arr;
		arr.pb(mk(0,0));
		fori(i,1,n) {
			cin >> u >> v;
			arr.pb(mk(u,v));
		}
		bool possible = true;
		fori(i,1,n) {
			if (arr[i].fs >= arr[i-1].fs) {
				int delta = arr[i].fs - arr[i-1].fs;
				if (arr[i].sc - arr[i-1].sc >= 0 && (arr[i].sc - arr[i-1].sc <= delta)) {
				} else {
					possible = false;
					break;
				}
			} else {
				possible = false;
				break;
			}
		}
		cout << (possible ? "YES" : "NO") << endl;
	}

	return 0;
}
