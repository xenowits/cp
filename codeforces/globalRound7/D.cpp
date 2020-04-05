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

string solve(string s) {

int n = s.length();
vector<int> d1(n);

for (int i = 0, l = 0, r = -1; i < n; i++) {
    int k = (i > r) ? 1 : min(d1[l + r - i], r - i + 1);
    while (0 <= i - k && i + k < n && s[i - k] == s[i + k]) {
        k++;
    }
    d1[i] = k--;
    if (i + k > r) {
        l = i - k;
        r = i + k;
    }
}

vector<int> d2(n);
for (int i = 0, l = 0, r = -1; i < n; i++) {
    int k = (i > r) ? 0 : min(d2[l + r - i + 1], r - i + 1);
    while (0 <= i - k - 1 && i + k < n && s[i - k - 1] == s[i + k]) {
        k++;
    }
    d2[i] = k--;
    if (i + k > r) {
        l = i - k - 1;
        r = i + k ;
    }
}

int indx = -1;
fori(i,0,n-1) {
	if ((i-d1[i]+1 == 0) || (i-d2[i] == 0)) {
		indx = i;
	}
	//cout << i << " " << d1[i] << " " << d2[i] << endl;
}
//i see that the indx is never -1 we will get atleast a single character
//hooray
//manacher rocks
//cout << indx << " from the manacher's algo" << endl;
if (indx-d1[indx]+1 == 0) {
	//odd length palindromes
	return s.substr(0,2*indx+1);
} else {
	return s.substr(0,2*indx);
}

return "";

}



int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;

	while (t--) {
		string str, pre = "", suf, temp;
		cin >> str;
		if (str.length() == 1) {
			cout << str << endl;
			continue;
		}
		ll n = str.length(), indx = -1;
		fori(i,0,n/2) {
			if (str[i] == str[n-1-i]) {
				pre += str[i];
			} else {
				indx = i;
//				cout << "i m breaking up " << indx << " " << i << endl;
				break;
			}
		}
		//cout << str << " and the fuckin indx " << indx << endl;
		suf = pre;
		reverse(suf.begin(), suf.end());
		//now that we have got the basic prefix and suffix part
		//let's find if string from index "indx" or suffix can give us more palindromes
		//indx == -1 may mean that the string is not palindrome from the first character itself
		//or it may mean that the whole string is a palindrome -- fucckkk

		if (indx == -1) {
			temp = str;
		} else {
			temp = str.substr(indx,n-2*indx);
		}

		string pretemp, suftemp, temp2, ans = "";
		temp2 = temp;
		reverse(temp2.begin(), temp2.end());
		pretemp = solve(temp);
		suftemp = solve(temp2);
		if (indx == -1) {
			ans = pretemp; 
		} else if (pretemp.length() < suftemp.length()) {
			ans = pre + suftemp + suf;
		} else {
			ans = pre + pretemp + suf;
		}
		cout << ans << endl;
	}

	return 0;
}
