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

	int t;
	cin >> t;
	while (t--) {

				ll n;
		        cin>>n;
		        int total = 3;
		        int pow2 = 2;
		        while(true) {
		            if(n%total==0){
		                cout<<n/total<<endl;
		                break;
		            }
		            else
		            {
		                total+=pow2*2;
		                pow2=2*pow2;
		            }
		        }
	}

	return 0;
}