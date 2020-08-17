//xenowi`tz -- Jai Shree Ram
#include<bits/stdc++.h>
using namespace std;

#define fori(i,a,b) for (long long int i = a; i <= b ; ++i)
#define ford(i,a,b) for(long long int i = a;i >= b ; --i)
#define mk make_pair
#define mod 1000000007
#define MAXN 5005
#define pb push_back
#define vec vector<long long int>
#define ll long long
#define rnd mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().count())
#define pi pair<long long int,long long int>
#define sc second
#define fs first

ll dp[MAXN][4];

vector<ll> binpows(MAXN,-1);

void binpow(ll a, ll b) {
	ll res = 1, temp_b = b;
	while (b > 0) {
		if (b&1) {
			res = (res*a)%mod;
		}
		a = (a*a)%mod;
		b >>= 1;
	}
	binpows[temp_b] = res;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	ll r, c = 3;
	cin >> r;
	
	ll p = 3;		//p denotes no of available colors
	
	//c is the important factor in this implementation technique
	
	//w(n) refers to 3-color combos
	//y(n) refers to 2-color combos
	
	//w(n+1) = 2*(wn + yn)
	//y(n+1) = 2*w(n) + 3*y(n)
	
	ll w1 = 6, y1 = 6;	//filling the first row with 3 & 2 colors respectively

	fori(i,2,r) {
		ll w_temp = (2*w1 + (2*y1) )%mod;
		ll y_temp = (2*w1 + (3*y1) )%mod;

		w1 = w_temp;
		y1 = y_temp;
	}

	cout << (w1 + y1)%mod << endl;


	return 0;
}
