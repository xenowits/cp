//xenowitz -- Jai Shree Ram
#include<bits/stdc++.h>
using namespace std;

#define fori(i,a,b) for (long int i = a; i <= b ; ++i)
#define ford(i,a,b) for(long int i = a;i >= b ; --i)
#define mk make_pair
#define mod 1000000007
#define pb push_back
#define eb emplace_back
#define vec vector<long long int>
#define ll long long
#define rnd mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().count())
#define pi pair<long long int,long long int>
#define sc second
#define fs first
#define stf shrink_to_fit

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	ll t, tc = 1;
	cin >> t;

	for (; tc <= t; tc += 1) {
		ll n, d;
		cin >> n >> d;

		map<ll, ll> mp;
		vector<ll> arr(n);
		fori(i,0,n-1) {
			cin >> arr[i];
			mp[arr[i]] += 1;
		}

		if (d == 3) {
			//check if 3 are already same

			bool done = false;
			ll ans = 0;

			for (auto x : mp) {
				if (x.sc >= 3) {
					done = true;
					ans = 0;
					break;
				}
			}

			if (done) {
				cout << "Case #" << tc << ": " << ans << endl;
				continue;
			}

			//now check if 2 are there

			for (auto x : mp) {
				if (x.sc >= 2) {
					bool ho_jaega = false;
					fori(i,0,n-1) {
						if (arr[i] > x.fs) {
							ho_jaega = true;
							break;
						}
					}
					if (ho_jaega) {
						done = true;
						ans = 1;
						break;
					}
				}
			}

			if (done) {
							cout << "Case #" << tc << ": " << ans << endl;
							continue;
			}

			//now check for ans = 1 with 2 boys

			sort(arr.begin(), arr.end());

			fori(i,0,n-1) {
				fori(j, i+1, n-1) {
					if (arr[j] >= 2*arr[i]) {
						done = true;
						ans = 1;
						break;
					}
				}
			}

			if (done) {
					cout << "Case #" << tc << ": " << ans << endl;
					continue;
			}

			if (n == 1) {
				if (arr[0]%3 == 0) {
					ans = 2;
				} else {
					ans = 3;
				}
			} else {
				ans = 2;
			}

			cout << "Case #" << tc << ": " << ans << endl;
		} else if (d == 2) {
			bool done = false;
			ll ans = 0;

			for (auto x : mp) {
				if (x.sc >= 2) {
					bool ho_jaega = false;
					fori(i,0,n-1) {
						if (arr[i] > x.fs) {
							ho_jaega = true;
							break;
						}
					}
					if (ho_jaega) {
						done = true;
						ans = 0;
						break;
					}
				}
			}

			if (done) {
					cout << "Case #" << tc << ": " << ans << endl;
					continue;
			}

			if (n == 1) {
				ans = 2;
			} else {
				ans = 1;
			}

			cout << "Case #" << tc << ": " << ans << endl;

		}


	}

	return 0;
}
