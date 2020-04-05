//xenowitz -- Jai Shree Ram
#include<bits/stdc++.h>
using namespace std;

#define fori(i,a,b) for (long int i = a; i <= b ; ++i)
#define ford(i,a,b) for(long int i = a;i >= b ; --i)
#define mk make_pair
#define mod 1000000007
#define MAXN 200005
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
		vector<int> T(MAXN,0);
		bool allsame = true;
		int allsame_temp;
		fori(i,0,n-1) {
			cin >> T[i];
			if (i == 0)
				allsame_temp = T[i];
		}
		fori(i,1,n-1) {
			if (T[i] != allsame_temp) {
				allsame = false;
				break;
			}
		}
		if (allsame) {
			cout << 1 << endl;
			fori(i,1,n) {
				cout << 1 << " ";
			}
			cout << endl;
			continue;
		}
		set<int> st;
		int start_indx = 0, end_indx = 0, longest = 1, start, ending;
		//first check for without circular longest subarray with distinct elements
		for (int i = 0; i < n; i++) {
			if (st.empty() || st.find(T[i]) == st.end() ) {
				st.insert(T[i]);
				end_indx = i;
			} else {
				st.clear();
				int temp = end_indx-start_indx+1;
				if (temp > longest) {
					longest = temp;
					start = start_indx;
					ending = end_indx;
				}
				st.insert(T[i]);
				start_indx = end_indx = i;
			}
		}
		//cout << start << " pops " << ending;
		//cout << endl << start_indx << " " << end_indx << endl;
		//let's go around
		for(int i = 0; i < n; i++) {
			if (st.find(T[i]) == st.end()) {
				st.insert(T[i]);
				end_indx = i;
			} else {
                                st.clear();
                                int temp = end_indx-start_indx+1+n;
                                if (temp > longest) {
                                        longest = temp;
                                        start = start_indx;
                                        ending = end_indx;
                                }
                                break;
                        }
		}
		//cout << start_indx << " bc " << end_indx << endl;
		vector<int> coloring(n,-1);
		if (start <= ending) {
			//within array
			int cnt = 1;
			for(int i = start; i <= ending; i++, cnt += 1) {
				coloring[i] = cnt;
			}
			for (int i = start-1; i >= 0; i -= 1) {
				if (coloring[i+1] == 1) {
					coloring[i] = 2;
				} else {
					coloring[i] = 1;
				}
			}
			for (int i = ending+1; i < n; i += 1) {
                                if (coloring[i-1] == 1) {
                                        coloring[i] = 2;
                                } else {
                                        coloring[i] = 1;
                                }
                        }
			cout << cnt-1 << endl;

		} else {
			int cnt = 1;
			for (int i = 0; i <= ending; i++) {
				coloring[i] = cnt;
				cnt += 1;
			}
			for (int i = start; i < n; i++) {
				coloring[i] = cnt;
				cnt += 1;
			}
			for (int i = ending+1; i < start; i++) {
				if (coloring[i-1] == 1) {
					coloring[i] = 2;
				} else {
					coloring[i] = 1;
				}
			}
			cout << cnt-1 << endl;
		}
		fori(i,0,n-1) {
			cout << coloring[i] << " ";
		}
		cout << endl;
	}


	return 0;
}
