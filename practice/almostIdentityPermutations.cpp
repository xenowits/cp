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
	
	//the problem is based on Derangements(!n)
	ll n, k;
	cin >> n >> k;

	ll ans = 1;	//for identity permutation
	if (k >= 1)
		ans += 0;
	if (k >= 2)
		ans += n*(n-1)/2;
	//cout << ans << " " << k << endl;
	if (k >= 3)
		ans += (n*(n-1)*(n-2)/6)*2;
	//cout << ans << endl;
	if (k >= 4)
		ans += (n*(n-1)*(n-2)*(n-3)/24)*9;

	cout << ans << endl;	

	return 0;
}
