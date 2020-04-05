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

bool comp(pi a, pi b) {
	if ((a.fs - a.sc) == (b.fs - b.sc)) {
		return a.fs < b.fs;
	}
	return (a.fs - a.sc) > (b.fs - b.sc);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
		
	ll n, m;
	cin >> n >> m;

	vector<pi> arr;
	ll cnta = 0, cntb = 0, ans = 0;
	vector<int> A(n,0), B(n,0);
	fori(i,0,n-1) {
		cin >> A[i] >> B[i];
		cnta += A[i];
		cntb += B[i];
		arr.pb(mk(A[i], B[i]));
	}

	if (cntb > m) {
		cout << -1 << endl;
		return 0;
	}

	sort(arr.begin(), arr.end(), comp);

	//now start ejecting the items to bring down sum to atmost m
	
	for (auto x : arr) {
		if (cnta > m) {
			cnta = cnta - (x.fs - x.sc);
			ans += 1;
		} else {
			cout << ans << endl;
			return 0;
		}
	}
	
	cout << ans << endl;	
	return 0;
}
