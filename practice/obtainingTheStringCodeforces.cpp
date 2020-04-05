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

	string str1, str2;
	cin >> str1 >> str2;

	vector<int> freq1(26,0), freq2(26,0);
	vector<int> moves;

	fori(i,0,n-1) {
		freq1[str1[i]-'a'] += 1;
		freq2[str2[i]-'a'] += 1;
	}

	fori(i,0,25) {
		if (freq1[i] != freq2[i]) {
			cout << -1 << endl;
			return 0;
		}
	}

	//now the strings are interconvertible
	
	fori(i,0,n-1) {
		//check where str2[i] occurs for the first time in str1
		int j = i;
		for(;j < n; j++) {
			if (str1[j] == str2[i]) {
				break;
			}
		}
		//now bring that jth character to the ith character
		while(j > i) {
			moves.pb(j-1+1);
			//now swap (j-1) and j th characters
			auto ch = str1[j];
			str1[j] = str1[j-1];
		       	str1[j-1] = ch;	
			j -= 1;	
		}
		//cout << str1 << endl;
	}

	cout << moves.size() << endl;
	for (auto x : moves) {
		cout << x << " ";
	}
	cout << endl;

	return 0;
}
