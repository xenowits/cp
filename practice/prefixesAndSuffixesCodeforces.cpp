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

vector<pair<string,int> > v;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n,n2;
	cin >> n;
	if (n == 2) {
		cout << "PS" << endl;
		return 0;
	}
	n2 = 2*n-2;
	string temp, realans;
	vector<string> singles, multiples, possibilities;
	fori(i,1,n2) {
		cin >> temp;
		v.pb(mk(temp,i));
		if (temp.length() == 1) {
			singles.pb(temp);
		} else if (temp.length() == (n-1)) {
			multiples.pb(temp);
		}
	}
	for(string x : singles) {
		for(string y : multiples) {
			possibilities.pb(x+y);
		}
	}
	for(string x : multiples) {
                for(string y : singles) {
                        possibilities.pb(x+y);
                }
        }

	//for (string x : possibilities) {
	//	cout << x << endl;
	//}
	
	for (string x : possibilities) {
		map<string,bool> mp;
		vector<string> prefixes, suffixes;
		for(auto y : v) {
			mp[y.fs] = false;
		}
		//0 mtlb n-1
		string temp;
		fori(i,0,n-2) {
			temp = x.substr(0,i+1);
			mp[temp] = true;
			prefixes.pb(temp);
			temp = x.substr(n-1-i,i+1);
			mp[temp] = true;
			suffixes.pb(temp);
		}
		bool sahi_hai = true;
		for (auto y : mp) {
			if (y.sc == false) {
				sahi_hai = false;
				break;
			}
		}
		if (sahi_hai) {
			//cout << "the answer is " << x << endl;
			realans = x;
			for (auto y : v) {
				bool done = false;
				//find if y is in prefixes or suffixes
				for (auto it = prefixes.begin(); it != prefixes.end(); it++) {
					if ((*it) == y.fs) {
						cout << "P";
						done = true;
						prefixes.erase(it);
						break;
					}
				}
				if (!done) {
					cout << "S";
				}
			}
			return 0;
		}

	}



	return 0;
}
