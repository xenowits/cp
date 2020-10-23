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

ll binpow (ll a, ll b) {
    ll res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        ll n, ans = 1e16;
        cin >> n;

        // let us first increase 1 to x
        // i = increment steps = x-1
        // c-1 = copy steps = x*c >= n => c >= n/x
        // t = i+c = total steps = x + c - 2

        for (ll x = 1; x*x <= n; x += 1) {
            ans = min(ans, x-1 + (ll)ceil(n/(x + 0.00000)) - 1);
        }

        cout << ans << endl;
    }

	return 0;
}
