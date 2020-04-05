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
		int n, x, temp;
		cin >> n >> x;
		vector<int> arr(210,0);
		fori(i,0,n-1) {
			cin >> temp;
			arr[temp] += 1;
		}
		//we have x more chances
		int indx = 1;
		while (x > 0) {
			if (arr[indx] == 0) {
				x -= 1;
				arr[indx] += 1;
			}
			indx += 1;
		}
		int ans = 0;
		fori(i,1,205) {
			if (arr[i] == 0) {
				break;
			}
			ans += 1;
		}
		cout << ans << endl;
	}	

	return 0;
}
