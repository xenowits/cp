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
		if (n == 1) {
			cout << -1 << endl;
		} else if (n == 2) {
			cout << 57 << endl;
		} else if (n == 3) {
			cout << 239 << endl;
		} else if ((4*n)%3 == 0) {
			cout << 5;
			fori(i,1,n-3) {
				cout << 4;
			}
			cout << "23" << endl;
		} else {
			fori(i,1,n-2) {
				cout << 4;
			}
			cout << "23" << endl;
		}
	}	

	return 0;
}
