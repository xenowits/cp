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

	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;
		vector<long long> arr(n);
		for(int i = 0;i < n; i++) {
			cin >> arr[i];
		}
		long long ans = 0;
		for(int i = 0; i < n;) {
			bool pos = true;
			if (arr[i] < 0) {
				pos = false;
			}
			long long maxu = -1e16, minu = 1e16;
			int j;
			for (j = i; j < n; j++) {
				if (pos && (arr[j] < 0)) {
					break;
				} else if(!pos && (arr[j] > 0)) {
					break;
				} else {
					maxu = max(maxu, arr[j]);
					minu = min(minu, arr[j]);
				}
			}
			//cout << pos << " " << maxu << " " << minu << endl;

			ans += maxu;
			//cout << ans << " " << j << endl;
			i = j;
		}
		cout << ans << endl;
	}

	return 0;
}
