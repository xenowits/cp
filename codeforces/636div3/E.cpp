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
		ll n, k;
		cin >> n >> k;

		vector<ll> arr(n);
		for(int i = 0; i < n; i++) {
			cin >> arr[i];
		}

		vector<ll> prefix(2*k+2,0), cnt(2*k+2,0);

		/*
		-- Prefix array(prefix[x]) stores no of pairs where modification
		to atmost 1 element of the pair yields the sum x
		-- also the cnt[x] array stores how many pairs don't need a
		modification
		-- n/2-prefix[x] stores the no of pairs where both elements of
		a pair has to be changed
		*/

		for (int i = 0; i < n/2; i++) {
			cnt[arr[i]+ arr[n-1-i]] += 1;
			int minu = min(arr[i], arr[n-1-i]) + 1;
			int maxu = max(arr[i], arr[n-1-i]) + k;
			if (minu <= maxu) {
				prefix[minu] += 1;		//min sum
				prefix[maxu+1] -= 1;	//max sum
			}
		}

		//calc prefix sums

		for(int i = 1; i <= 2*k; i+=1) {
			prefix[i] += prefix[i-1];
			//cout << i << " " << prefix[i] << endl;
		}

		long long ans = 1e15;

		//calc ans

		for(int sum = 2; sum <= 2*k; sum += 1) {
			ans = min(ans, (prefix[sum] - cnt[sum])+(n/2 - prefix[sum])*2);
		}

		cout << ans << endl;

	}

	return 0;
}
