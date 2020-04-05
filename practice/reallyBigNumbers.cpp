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

ll sum_of_digits(ll n) {
	ll res = 0;
	while (n) {
		res += n%10;
		n /= 10;
	}
	return res;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	unsigned long long int n, s;
	cin >> n >> s;

	//concept: the function (x-sum_of_digits(x)) is non-decreasing
	//the function exhibits a cool pattern
	//they are all multiples of 9
	//but the problem lies in the boundary(100-109) ----> 90-99 => 81(9*9), 100-109 => 99(9*11), 110-119 => 108(9*12)
	//anyways it is a binary search problem and we just need to find (x-s(x) >= s)
	
	ll low = 1, high = (unsigned ll)1e18;
	while (low < high) {
		//cout << low << " the lows and the highs " << high << endl;
		ll mid = low + (high-low)/2;
		ll function_value = mid-sum_of_digits(mid);
	       	if (function_value >= s) {
			high = mid;
		} else {
			low = mid+1;
		}	
	}

	//cout << low << " " << high << endl;
	//cout << (low - sum_of_digits(low)) << " " << s << endl;	
	ll temp = low - sum_of_digits(low);
	if (n < low || (temp < s)) {
		cout << 0 << endl;
	} else 
		cout << ( n-low+1 ) << endl;
	return 0;
}
