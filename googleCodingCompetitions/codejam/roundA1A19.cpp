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
		ll p, q, x, y;
		char d;
		cin >> p >> q;
		vector<pi> x_segments, y_segments;
		fori(i,0,p-1) {
			cin >> x >> y >> d;
			switch (d) {
				case 'N':
					y_segments.pb(mk(y+1,q));
					break;
				case 'S':
					y_segments.pb(mk(0,y-1));
					break;
				case 'E':
					x_segments.pb(mk(x+1,q));
					break;
				case 'W':
					x_segments.pb(mk(0,x-1));	
					break;
			}
		}
		//carry out line sweeps on the y-axis and x-axis
		vector<ll> prefix_x(q+5,0), prefix_y(q+5,0);
		ll x_maxu, y_maxu;

		sort(x_segments.begin(), x_segments.end());
		sort(y_segments.begin(), y_segments.end());
		
		for (auto x_ele : x_segments) {
			prefix_x[x_ele.fs] += 1;
			prefix_x[x_ele.sc+1] -= 1;
			//cout << x_ele.fs << " is the x segment " << x_ele.sc << endl;
		}
		
		x_maxu = prefix_x[0];
		fori(i,1,q) {
			prefix_x[i] += prefix_x[i-1];
			x_maxu = max(x_maxu, prefix_x[i]);
		}

		for (auto y_ele : y_segments) {
                        prefix_y[y_ele.fs] += 1;
                        prefix_y[y_ele.sc+1] -= 1;
			//cout << y_ele.fs << " is the y segment " << y_ele.sc << endl;
                }
		y_maxu = prefix_y[0];
                fori(i,1,q) {
                        prefix_y[i] += prefix_y[i-1];
			y_maxu = max(y_maxu, prefix_y[i]);
                }
		//cout << x_maxu << " are the maximums " << y_maxu << endl;
		//get the answer
		//for the x and y axes find the first non-negative co-ordinate equal to the respective maximums
		ll x_ansCoordinate = -1, y_ansCoordinate = -1;
		fori(i,0,q) {
			if (x_ansCoordinate == -1 && prefix_x[i] == x_maxu) {
				x_ansCoordinate = i;
			}
			if (y_ansCoordinate == -1 && prefix_y[i] == y_maxu) {
                                y_ansCoordinate = i;
                        }
		}
		cout << "Case #" << t_count << ": " << x_ansCoordinate << " " << y_ansCoordinate << endl;
		t_count += 1;
	}
	
	return 0;
}
