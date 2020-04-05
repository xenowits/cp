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

void printMap(int k, map<int,int> a, map<int,int> b) {
	cout << k << endl;
	for (auto x : a) {
		cout << x.fs << " " << x.sc << endl;
	}
	cout << "a done" << endl;
	for (auto x : b) {
		cout << x.fs << " " << x.sc << endl;
	}
	cout << "b done" << endl;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;

	while (t--) {
		ll n;
		cin >> n;
		vector<int> arr(n+1,0);
		map<int,int> mp1, mp2;
		fori(i,1,n) {
			cin >> arr[i];
			mp2[arr[i]] += 1;
		}
		vector<int> ans;
		fori(i,1,n-1) {
			//i is the length of the first per, n-i is of the second per
			mp1[arr[i]] += 1;
			mp2[arr[i]] -= 1;
			if (mp2[arr[i]] == 0) {
					mp2.erase(arr[i]);
			}
			//check for ans
			bool check1 = false, check2 = false;
			if (mp1.size() == i && ((mp1.rbegin())->first == i)) {
				check1 = true;
			}
                        if (mp2.size() == (n-i) && ((mp2.rbegin())->first == (n-i))) {
                                check2 = true;
                        }
			//printMap(i,mp1,mp2);
			if (check1 && check2) {
				ans.pb(i);
			}
		}
		cout << ans.size() << endl;
		for (auto x : ans) {
			cout << x << " " << (n-x) << endl;
		}
	}

	return 0;
}
