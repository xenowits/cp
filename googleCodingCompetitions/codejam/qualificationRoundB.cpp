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

struct segment {
	int id;
	int start;
	int end;
	segment(int a, int b, int c) : id(a), start(b), end(c) {
	}
};

bool comp(segment X, segment Y) {
	if (X.start == Y.start) {
		return (X.end-X.start > Y.end-Y.start);
	}
	return X.start < Y.start;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t, t_count = 1;
	cin >> t;
	while (t_count <= t) {
		int n, s, e;
		cin >> n;
		vector<segment> v;
		vector<int> ans(n+1,0), times(2500,0);
		fori(i,1,n) {
			cin >> s >> e;
			v.emplace_back(i,s,e);
		}
		sort(v.begin(), v.end(), comp);
//		for (auto x : v) {
//			cout << x.start << " " << x.end << endl;
//		}
		bool possible = true;
		for (auto x : v) {
			//paint all points of this segment with color 1(if possible)
			int color;
			if (times[x.start] == 0 || times[x.start] == 2) {
				//color this segment with color 1
				ans[x.id] = 1;
				color = 1;
			} else if (times[x.start] == 1) {
				//color this segment with color 2
				ans[x.id] = 2;
				color = 2;
			} else if (times[x.start] > 2) {
				possible = false;
				break;
			}
			fori(i,x.start,x.end-1) {
				times[i] += color;
			}
		}
		string ans_str;
		if (!possible) {
			ans_str = "IMPOSSIBLE";
		} else {
			fori(i,1,n) {
				char ch = (ans[i] == 1 ? 'C' : 'J');
				ans_str.pb(ch);
			}
		}
		cout << "Case #" << t_count << ": " << ans_str << endl;
		t_count += 1;
	}	
	
	return 0;
}
