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
		int n;
		cin >> n;
		vector<ll> arr(n), barr(n);
		vector<bool> ok(n,false);
		fori(i,0,n-1) {
			cin >> arr[i];
		}
		fori(i,0,n-1) {
			cin >> barr[i];
		}
		int minus_indx = -1, plus_indx = -1;
		bool possible = true;
		fori(i,0,n-1) {

			if (arr[i] == -1) {
				minus_indx = i;
			} else if (arr[i] == 1) {
				plus_indx = i;
			}
			//for here
			if (arr[i] < barr[i]) {
				//we need a plus here do we have it?
				if (plus_indx != -1 && plus_indx < i) {
					ok[i] = true;
				} else {
					possible = false;
					break;
				}				
			} else if (arr[i] > barr[i]) {
				//we need a minus here
				if (minus_indx != -1 && minus_indx < i) {
					ok[i] = true;
				} else {
					possible = false;
					break;
				}
			} else {
				ok[i] = true;
			}
			//cout << i << " " << ok[i] << endl;

		}
		//so far so good
		//check for problems
		if (!possible) {
			cout << "NO" << endl;
			continue;
		} else {
			bool real_bool = false;
			fori(i,0,n-1) {
				if (!ok[i]) {
					real_bool = true;
				}
			}
			if (real_bool) {
				cout << "NO" << endl;
			} else {
				cout << "YES" << endl;
			}
		}
	}

	return 0;
}
