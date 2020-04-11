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
		ll n;
		cin >> n;
		vector<ll> arr(n), barr(n), prefix(n+1,0);
		fori(i,0,n-1) {
			cin >> arr[i] >> barr[i];
		}
		fori(i,1,n-1) {
			prefix[i] = prefix[i-1] + max((ll)0,arr[i]-barr[i-1]);
		}
		//check for all i's
		ll ans = 1e15;
		fori(i,0,n-1) {
			ll temp = arr[i];
			if (i == 0) {
				temp += prefix[n-1];
			} else if (i == n-1) {
				temp += prefix[n-2]+max((ll)0,arr[0]-barr[n-1]);
			} else {
				temp += prefix[i-1]+prefix[n-1]-prefix[i]+max((ll)0,arr[0]-barr[n-1]);
			}
			ans = min(ans,temp);
		}
		cout << ans << endl;
	}

	return 0;
}
