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
		ll n, x;
		cin >> n >> x;
		vector<int> arr(n);
		fori(i,0,n-1) {
			cin >> arr[i];
		}
		//use 2 pointer technique for this

		int l = 0, r = 0;
		int ans = -1;
		ll sum = arr[0];

		while (r < n) {
			if (sum%x == 0) {
				ans = max(ans, r-l+1);
				sum -= arr[l];

				l += 1;

				if (l > r) {
					r = l;
				}
			} else {
				r += 1;
				sum += arr[r];
			}
//			cout << ans << " " << l << " " << r << endl;
		}

		ans = max(ans, r-l);
		cout << ans << endl;
	}
	
	return 0;
}
