//xenowi`tz -- Jai Shree Ram
#include<bits/stdc++.h>
using namespace std;

#define fori(i,a,b) for (long long int i = a; i <= b ; ++i)
#define ford(i,a,b) for(long long int i = a;i >= b ; --i)
#define mk make_pair
#define mod 1000000000
#define MAXN 400005
#define pb push_back
#define vec vector<long long int>
#define ll long long
#define rnd mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().count())
#define pi pair<long long int,long long int>
#define sc second
#define fs first

long double binpow(long long b) {
    long double res = 1, a = 0.500000000;
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
	
	int t, t_count = 1;
	cin >> t;
	while (t_count <= t) {
		ll w, h, l, u, r, d;
		cin >> w >> h >> l >> u >> r >> d;
		
		long double ans = 0;
		
		if (u > 1) {
			//can fall through top
			ans += binpow(l+u-3)*(1-binpow(r-l+1));

			//if the last endpoint is the last column
			if (r == w) {
				ans -= binpow(u-1)*binpow(w-1);
				ans += binpow(w-1);
			}
		}

		if (l > 1) {
			//can fall through right
			ans += binpow(l+u-3)*(1- binpow(d-u+1));		

			//if the last endpoint is the last row
			if (d == h) {
                                ans -= binpow(l-1)*binpow(h-1);
                                ans += binpow(h-1);
                        }

		}
		ans = 1 - ans;
		cout << "Case #" << t_count << ": " << setprecision(8) << fixed << ans << endl;
		t_count += 1;
	}	
	return 0;
}
