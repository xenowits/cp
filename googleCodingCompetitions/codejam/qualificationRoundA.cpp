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
		
	int t, t_count = 1;
	cin >> t;
	while (t_count <= t) {
		int n, r = 0, c = 0, trace = 0;
		cin >> n;
		int arr[n+1][n+1];
		fori(i,1,n) {
			set<int> row_set;
			fori(j,1,n) {
				cin >> arr[i][j];
				row_set.insert(arr[i][j]);
			}
			if (row_set.size() < n) {
				r += 1;
			}
		}
		//now count good columns and trace
		fori(i,1,n) {
			set<int> col_set;
			fori(j,1,n) {
				if (i == j) {
					trace += arr[i][j];
				}
				col_set.insert(arr[j][i]);
			}
			if (col_set.size() < n) {
				c += 1;
			}
		}
		cout << "Case #" << t_count << ": " << trace << " " << r << " " << c << endl;
		t_count += 1;
	}

	return 0;
}
