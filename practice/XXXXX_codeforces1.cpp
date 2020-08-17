//xenowitz -- Jai Shree Ram
#include<bits/stdc++.h>
using namespace std;

#define fori(i,a,b) for (int i = a; i <= b ; ++i)
#define ford(i,a,b) for(int i = a;i >= b ; --i)
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
		int n, x;
		cin >> n >> x;
		vector<int> arr(n);

		ll sum = 0;

		fori(i,0,n-1) {
			cin >> arr[i];
			sum += arr[i];
		}

		if (sum%x != 0) {
			cout << n << endl;
		} else {
			//find min and max index where
			//arr[i]%x == 0
			
			int minl = 10000000, minr = -1;

			fori(i,0,n-1) {
				if (arr[i]%x != 0) {
					minl = min(minl, i);
					minr = max(minr, i);
				}
			}
			
//			cout << minl << " " << minr << endl;

			if (minl == -1 || minr == -1) {
				cout << -1 << endl;	
			} else if (minl == minr) {
				//single such element
				cout << 1 << endl;
			} else {
				cout << max(n-minl-1, minr) << endl;
			}
		}
		
	}
	
	return 0;
}
