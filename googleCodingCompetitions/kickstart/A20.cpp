//xenowi`tz -- Jai Shree Ram
#include<bits/stdc++.h>
using namespace std;

#define fori(i,a,b) for (long long int i = a; i <= b ; ++i)
#define ford(i,a,b) for(long long int i = a;i >= b ; --i)
#define mk make_pair
#define mod 1000000007
#define MAXN 400005
#define pb push_back
#define vec vector<long long int>
#define ll long long
#define rnd mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().count())
#define pi pair<long long int,long long int>
#define sc second
#define fs first

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t, k = 1;
	cin >> t;

	while (k <= t) {
		ll n, b;
		cin >> n >> b;
		vector<ll> arr(n);
		fori(i,0,n-1) {
			cin >> arr[i];
		}
		sort(arr.begin(), arr.end());
		ll cnt = 0;
		fori(i,0,n-1) {
			if (arr[i] <= b) {
				b -= arr[i];
				cnt += 1;
			} else {
				break;
			}
		}
		cout << "Case #" << k << ": " << cnt << endl;
		k += 1;
	}	
	
	return 0;
}

