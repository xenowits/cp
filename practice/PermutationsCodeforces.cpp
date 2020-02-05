//xenowits -- Jai Shree Ram
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


int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

	int n, temp;
	cin >> n;
	map<int,int> mp;
	int maxu = INT_MIN, maxNo = -1;
	vector<int> arr(n+1);
	fori(i,1,n) {
		cin >> temp;
		mp[temp] += 1;
		maxu = max(maxu,mp[temp]);
		maxNo = max(temp,maxNo);
		arr[i] = temp;
	}
	//check for impossibility
	fori(i,1,maxNo-1) {
		if ((mp[i] == 0 || mp[i+1] == 0) || mp[i] < mp[i+1]) {
			cout << -1 << endl;
			exit(0);
		}
	}
	//now it's possible

	//1. If u want all permutations
	// vector<vector<int> > v(maxu);
	// fori(i,1,maxNo) {
	// 	temp = 0;
	// 	while (mp[i]) {
	// 		v[temp].pb(i);
	// 		temp += 1;
	// 		mp[i] -= 1;
	// 		// cout << i << " " << mp[i] << endl;
	// 	}
	// }
	// cout << maxu << endl;
	// fori(i,0,maxu-1) {
	// 	auto x = v[i];
	// 	for (int p : x) {
	// 		cout << p << " ";
	// 	}
	// 	// cout << endl;
	// }

	//2. Just as asked in the question
	vector<vector<int> > positions(maxNo+1);
	fori(i,1,n) {
		positions[arr[i]].pb(i);
	}
	cout << maxu << endl;
	vector<int> ans(n+1,0);
	fori(i,1,maxNo) {
		auto x = positions[i];
		temp = mp[i];
		for (int p : x) {
			if (temp > 0) {
				ans[p] = temp;
				temp -= 1;
			}
		}
	}

	fori(i,1,n) {
		cout << ans[i] << " ";
	}

	return 0;
}
