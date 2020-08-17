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

    ll t;
    cin >> t;

    while (t--) {
        ll n;
        cin >> n;

        vector<ll> perm(n+1,0), pos(n+1,0);
        for(int i = 1; i <= n; i++) {
            cin >> perm[i];
            pos[perm[i]] = i;
        }

        vector<set<ll> v(n+1);
        map<ll, ll> maps;

        set<ll, greater<ll> > deleted_indices, di2;
        ll minu , maxu, l, r;
        for (int i = n; i >= 1; i -= 1) {

            //delete i from its position in the perm array
            if (deleted_indices.size() == 0) {
                deleted_indices.insert(pos[i]);
                di2.insert(pos[i]);
                minu = pos[i];
                maxu = pos[i];
                maps[pos[i]] = pos[i];
                continue;
            }

            if (pos[i] < minu) {
                mp[pos[i]] = pos[i];
                mp[minu] = (minu-pos[i]);
                minu = pos[i];
            } else if (pos[i] > maxu) {
                mp[pos[i]] = n-pos[i]+1;
                mp[maxu] = (pos[i] - maxu);
                maxu = pos[i];
            } else {
                l = *(deleted_indices.lower_bound(pos[i]));
                r = *(di2.upper_bound(pos[i]));
                mp[pos[i]] = pos[i] - l;
                mp[r] = r-pos[i];
            }

            deleted_indices.insert(pos[i]);
            di2.insert(pos[i]);

        }

    }

	return 0;
}
