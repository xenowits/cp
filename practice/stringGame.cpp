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

bool possible(string s, string t) {
    int a = 0, b = 0;
    fori(i,0,s.length()-1) {
        if (s[i] == t[a]) {
            a += 1;
            if (a == t.length()) {
                return true;
            }
        }
    }
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string t, p;
    cin >> t >> p;
    int l1 = t.length(), l2 = p.length();
    vector<int> v(t.length(),0);
    fori(i,0,l1-1) {
        cin >> v[i];
    }

    ll l = 0, r = l1-l2;
    while (1 < r-l) {
        int mid = l+(r-l)/2;
        vector<bool> vbool(l1,true);
        fori(i,0,mid-1) {
            vbool[v[i]-1] = false;
        }
        string tempString = "";
        fori(i,0,l1-1) {
            if (vbool[i]) {
                tempString.pb(t[i]);
            }
        }

        if (possible(tempString,p)) {
            l = mid;
        } else {
            r = mid-1;
        }
    }
  
    vector<bool> vbool(l1,true);
    fori(i,0,r-1) {
        vbool[v[i]-1] = false;
    }
    string tempString = "";
    fori(i,0,l1-1) {
        if (vbool[i]) {
            tempString.pb(t[i]);
        }
    }
    // cout << tempString << endl;
    if (possible(tempString,p)) {
      cout << r << endl;
    } else
      cout << l << endl;
    return 0;
}
