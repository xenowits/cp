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
	
	int t, t_count = 1;
	cin >> t;

	while (t_count <= t) {

		int r, c, h, v;
		cin >> r >> c >> h >> v;
		char arr[r+1][c+1];
		int no_of_chips = 0, no_of_cells = (h+1)*(v+1);

		fori(i,1,r) {
			fori (j, 1, c) {
				cin >> arr[i][j];
				if (arr[i][j] == '@') {
					no_of_chips += 1;
				}
			}
		}

		cout << "Case #" << t_count << ": ";
		if (no_of_chips%no_of_cells == 0) {
			//vector of indices if we have ever want to print the cut indices
			int chips_per_piece = no_of_chips/no_of_cells;
			
		} else {
			cout << "IMPOSSIBLE" << endl;
		}
		t_count += 1;
	}	
	return 0;
}
