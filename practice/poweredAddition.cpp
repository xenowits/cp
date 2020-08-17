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

//problem link: https://codeforces.com/contest/1339/problem/C
//concept: if arr[i] <= arr[i+1], no need to add to arr[i]
//	   just update max as arr[i+1]
//	   note the greedy approach here, when possible we don't change arr[i]
//	   if arr[i] > arr[i=1], we need to add arr[i]
//	   diff = 0000111111, so check what length of set bits invert the above inequality
//	   but again we just update the max as arr[i+1]
//	   this is because: we can well remove some bits from the diff and make arr[i+1] equal to arr[i]
//	   110 100  --> 111 as diff we could have added 111+100 = 11 but that's not the greedy here
//	   just make it 110 110 (take 010 from diff) --> binary representation matters
//	   and that's it

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t;
	cin >> t;
	
	while (t--) {
		ll n, temp;
		cin >> n;
		vector<ll> arr(n);
		fori(i,0,n-1) {
			cin >> arr[i];
		}
		ll ans = 0, diff = 0;
		fori(i,1,n-1) {
			//make arr[i] <= arr[i+1]
			while (arr[i] + diff < arr[i-1]) {
				diff += (1LL << ans);
				ans += 1;
			}
			arr[i] = max(arr[i], arr[i-1]);
		}
		cout << ans << endl;
	}	

	return 0;
}
