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
	
	int n;
	cin >> n;

	vector<int> arr(n+1,-1);
	int ones = 0;
	fori(i,1,n) {
		cin >> arr[i];
		if (arr[i] == 1) {
			ones += 1;
		}
	}
	//if there is atleast 1 in the array --> we can make the whole array equal to 1
	if (ones) {
		cout << n-ones << endl;
		return 0;
	}

	//now since there is no 1
	//we need to find a contiguos subarray whose gcd is 1
	//let length of the subarray be l : then, any contiguos subarray of length less than l
	//will have gcd > 1
	//now this is a good thing
	//ex: a1 a2 a3 a4 .... a8 a9 has gcd 1
	//now do the operation like below:
	//    a1 gcd(a1,a2) gcd(a3,gcd(a1,a2)) ..... ---> this takes exactly (l-1) steps
	//and the final element a9 = 1
	//now we got a 1 --> we can generate the rest
	//ans = len_min-1 + (n-1) ----> this is because we got only 1 so we need n-1 steps to generate all 1s
	int len_min = INT_MAX;
	for(int i = 1; i <= n; i++) {
		int gcd = arr[i];
		for(int j = i+1; j <= n; j++) {
			gcd = __gcd(gcd,arr[j]);
			if (gcd == 1) {
				len_min = min(len_min,j-i+1);
				break;
			}
		}
	}
	if (len_min == INT_MAX) {
		cout << "-1" << endl;
	} else {
		cout << (len_min-1+n-1) << endl;
	}
	return 0;
}
