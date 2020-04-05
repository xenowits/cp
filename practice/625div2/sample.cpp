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
	
	int n;
	cin >> n;
	vector<int> b(n+1,0);
	map<int,int> mp;
	//map stores the index(x) closest to b[i] where b[i]-b[x]=i-x
	//fori(i,1,n) {
	//	cin >> b[i];
	//	mp[b[i]-i] = i;
	//}
	vector<ll> dp(n+1,0);
	fori(i,1,n) {
		cin >> b[i];	
		int temp = b[i]-i;
		//find if temp is already present
		if (mp[temp] != 0) {
			dp[i] = b[i]+dp[mp[temp]];
			//cout << i << " " << mp[temp] << " " << temp << endl;
		} else {
			dp[i] = b[i];
			//cout << i << " " << b[i] << " aisa bhi" << endl;
		}
		mp[b[i]-i] = i;
	}
	ll ans = INT_MIN;
	fori(i,1,n) {
		ans = max(ans,dp[i]);
	}
	cout << ans << endl;
	return 0;
}
