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

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	vector<int> arr(6);
	fori(i,0,5) {
		cin >> arr[i];
	}

	while (1) {
		if ((arr[0] == arr[2]) && (arr[3] == arr[5])) {
			break;
		}
		//shift cyclically towards right
		vector<int> temp(6);
		fori(i,0,4) {
			temp[i+1] = arr[i];
		}
		temp[0] = arr[5];
		arr = temp;
	}

	//the hexagon is in the following format now:
	//   . . . 
	//  .     .
	// .       .
	//  .     .
	//   . . .
	
	ll central = arr[0]+arr[1], angle = arr[5]+(arr[0]+arr[4])/2, angleds = 1+(angle-arr[5])+(angle-arr[2]), sum = 0;

	//first [top, central)
	fori(i,arr[1],central-1) {
		int points = min(angleds,i+1);
		if (i == arr[1]) {
			//only downward facing triangles
			sum += (points-1);
		} else {
			sum += 2*(points-1);
		}
	}
	//then [bottom, central)
	fori(i,arr[4],central-1) {
                int points = min(angleds,i+1);
                if (i == arr[4]) {
                        //only downward facing triangles
                        sum += (points-1);
                } else {
                        sum += 2*(points-1);
                }
        }
	//finally the central line
	sum += 2*(min(angleds,central+1)-1);
	//output the result
	cout << sum << endl;
	return 0;
}
