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
	//complete the triangle first
	//actually the problem is based on the fact that:
	//Every equilateral triangle has a hexagon(with all angles = 120 deg) hidden inside it
	//for this just take two points on the triangle's every edge and join them
	//Also another concept is that : if an equilateral triangle is broken into triangles of 1 edge length
	//there are exactly a*a new smaller triangles
	ll A = arr[1], B = arr[3], C = arr[5], D = (A+C+arr[0]);
	ll ans = D*D - (A*A+B*B+C*C);
	cout << ans << endl;
	return 0;
}
