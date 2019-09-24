#undef NDEBUG
#ifdef ssu1
#define _GLIBCXX_DEBUG
#endif

#include <algorithm>
#include <functional>
#include <numeric>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <cassert>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <bitset>
#include <sstream>

using namespace std;

#define fore(i, l, r) for(int i = int(l); i < int(r); ++i)
#define forn(i, n) fore(i, 0, n)
#define fori(i, l, r) fore(i, l, (r) + 1)
#define forit(i, a) for(typeof((a).begin()) i = (a).begin(); i != (a).end(); ++i)
#define sz(v) int((v).size())
#define all(v) (v).begin(), (v).end()
#define pb push_back
#define mp make_pair
#define X first
#define Y second

template<typename T> inline T abs(T a){ return ((a < 0) ? -a : a); }
template<typename T> inline T sqr(T a){ return a * a; }

typedef long long li;
typedef long double ld;
typedef pair<int, int> pt;

int main() {
#ifdef ssu1
    assert(freopen("input.txt", "rt", stdin));
#endif

    int n, k, p;
    cin >> n >> k >> p;
    vector<int> a[2];
    forn(i, n){
        int cur;
        cin >> cur;
        a[cur % 2].pb(cur);
    }

    if(sz(a[1]) < k - p){
        puts("NO");
        exit(0);
    }

    vector<vector<int> > ans(k);
    forn(i, k - p){
        ans[i].pb(a[1].back());
        a[1].pop_back();
    }

    if(sz(a[1]) % 2 != 0){
        puts("NO");
        exit(0);
    }

    if(sz(a[0]) + sz(a[1]) / 2 < p){
        puts("NO");
        exit(0);
    }

    fore(i, k - p, k){
        if(!a[0].empty()){
            ans[i].pb(a[0].back());
            a[0].pop_back();
        }else{
            forn(step, 2){
                ans[i].pb(a[1].back());
                a[1].pop_back();
            }
        }
    }

    forn(j, 2){
        forn(i, sz(a[j])){
            ans[0].pb(a[j][i]);
        }
    }

    puts("YES");
    forn(i, sz(ans)){
        printf("%d", sz(ans[i]));
        forn(j, sz(ans[i])){
            printf(" %d", ans[i][j]);
        }
        puts("");
    }
#ifdef ssu1
    cerr << "\nTime = " << double(clock()) / CLOCKS_PER_SEC << endl;
#endif
    return 0;
}
