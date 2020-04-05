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

	ll n, k, temp;
	cin >> n >> k;
	vector<ll> arr(n+1,0);

	fori(i,1,n) {
		cin >> temp;
		arr[temp] = i;
	}

	//get the last k elements of permutation
	//i.e., (n-k+1) to n
	
	vector<ll> positions;
	ll ans = 0, ans_cnt = 1;
	fori(i,n-k+1,n) {
		positions.pb(arr[i]);
		ans += i;
	}

	sort(positions.begin(), positions.end());

	fori(i,0,k-2) {
		ans_cnt = (ans_cnt*(positions[i+1]-positions[i]))%mod;
	}

	cout << ans << " " << ans_cnt << endl;

	return 0;
}
