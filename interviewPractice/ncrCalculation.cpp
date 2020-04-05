//xenowitz -- Jai Shree Ram
#include<bits/stdc++.h>
using namespace std;

#define fori(i,a,b) for (long int i = a; i <= b ; ++i)
#define ford(i,a,b) for(long int i = a;i >= b ; --i)
#define mk make_pair
#define mod 1000000007
#define pb push_back
#define vec vector<long long int>
#define ll long long
#define rnd mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().count())
#define pi pair<long long int,long long int>
#define sc second
#define fs first
#define MAXN 1000001

ll binpow(ll a, ll b) {
	ll res = 1;
	a %= mod;
	while (b>0) {
		if (b&1) {
			res = (res*a)%mod;
		}
		a = a*a%mod;
		b >>= 1;
	}
	return res;
}

ll modInverse(ll a) {
	return binpow(a, mod-2);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	//calculation of nCr ---> calculate factorial[i] from i to MAXN
	
	vector<ll> factorial(MAXN,1);
	for (int i = 1; i <= MAXN; i++) {
		factorial[i] = (i*factorial[i-1])%mod;
	}

	//now query for nCr --> let's say q queries
	
	int q;
	cin >> q;

	while (q--) {
		ll n, r;
		cin >> n >> r;
		//expect n to be less than MAXN
		if (n < r) {
			cout << "Factorial not possible : n < r" << endl;
			continue;
		}		
		//concept is simple
		//we use fermat's little theorem
		//we use binary exponentiation to calculate a^(p-2)modp
		//this is the inverse

		ll ans = (factorial[n]*modInverse(factorial[n-r]))%mod;
		ans = (ans*modInverse(factorial[r]))%mod;

		cout << ans << endl;
	}

	return 0;
}
