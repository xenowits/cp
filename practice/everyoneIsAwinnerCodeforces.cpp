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

vector<ll> v;

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

void solve(ll n) {
	v.pb(0); //for x > n
	ll temp, current = n;
	while (current > 0) {
		if (current == 0) {
			cout << "blunder" << endl;
			exit(0);
		}
		temp = n/current;
		v.pb(temp);
		ll temp1 = floor(n/(temp+1.000000));

		//all x > temp1 have the same floor value i.e., temp
		//cout << temp << " is the temp and temp1 " << temp1 << endl;

		current = temp1;
		//cout << current << endl;
	}
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
		solve(n);
		cout << v.size() << endl;
		for(auto x : v) {
			cout << x << " ";
		}
		cout << endl;
		v.clear();
	}
	return 0;
}
