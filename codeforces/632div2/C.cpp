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

	ll n;
	cin >> n;
	vector<ll> arr(n+1,0), prefix_sum(n+1,0);
	fori(i,1,n) {
		cin >> arr[i];
		prefix_sum[i] = prefix_sum[i-1]+arr[i];
	}

	ll l = 1, r = 1, sum, len, total = 0;
	while (r <= n) {
		sum = prefix_sum[r] - prefix_sum[l-1];
		if (sum == 0) {
			len = r-l+1;
			total += (len*(len+1)/2-1);
			r += 1;
			l = r;
		} else {
			r += 1;
		}
	}
	//l....n is a good subarray
	len = n-l+1;
	total += len*(len+1)/2;
	cout << total << endl;

	return 0;
}
