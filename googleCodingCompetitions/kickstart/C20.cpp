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

struct diff {
	int current, actual_diff, cnt;
	diff(int a, int b, int c) : current(a), actual_diff(b), cnt(c) {}
};

struct compareDiff {
	bool operator() (diff const& a, diff const& b) {
		if (a.current == b.current) {
			return a.actual_diff < b.actual_diff;
		}
		return a.current < b.current;
	}
};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t;
	cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;
		vector<int> arr(n);
		fori(i,0,n-1) {
			cin >> arr[i];
		}
		priority_queue<diff, vector<diff>, compareDiff> Q;
		fori(i,0,n-2) {
			auto temp = diff(arr[i+1]-arr[i], arr[i+1]-arr[i], 0);
			Q.push(temp);
		}
		//repeat the process for k times
		fori(i,1,k) {	
			auto temp = Q.top();
			Q.pop();
			int A = temp.current, B = temp.actual_diff, C = temp.cnt;
			//cout << A << " " << B << " " << C << endl;
			C += 1;
			A = (int)ceil(B/(1.00000+C));
			auto new_temp = diff(A, B, C);
			//cout << A << " " << B << " " << C << endl;
			Q.push(new_temp);
		}
		int ans = INT_MIN;
		while (!Q.empty()) {
			auto temp = Q.top();
			Q.pop();
			//cout << temp.current << " final " << temp.actual_diff << " " << temp.cnt << endl;
			ans = max(ans,temp.current);
		}
		cout << ans << endl;		
	}
	//auto temp = diff(40, 40, 10);	
	
	return 0;
}

