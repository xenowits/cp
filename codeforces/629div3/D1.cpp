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
		
	int q;
	cin >> q;

	while (q--) {
		int n;
		cin >> n;
		vector<int> T(n);
		fori(i,0,n-1) {
			cin >> T[i];
		}
		vector<int> coloring(n,-1);
		coloring[0] = 0;
		for(int i = 1; i < n; i++) {
			if (T[i] != T[i-1]) {
				coloring[i] = 1-coloring[i-1];
			} else {
				coloring[i] = coloring[i-1];
			}
		}
		if (T[0] != T[n-1] && (coloring[0] == coloring[n-1])) {
			coloring[n-1] = 2;
		} 
		set<int> st;
		fori(i,0,n-1) {
			st.insert(coloring[i]+1);
		}
		cout << st.size() << endl;
		fori(i,0,n-1) {
			cout << coloring[i]+1 << " ";
		}
		cout << endl;
	}	

	return 0;
}
