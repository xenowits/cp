#include<bits/stdc++.h>
using namespace std;

#define fori(i,a,b) for (long int i = a; i <= b ; ++i)
#define ford(i,a,b) for(long int i = a;i >= b ; --i)
#define mk make_pair
#define mod 1000000007
#define pb push_back
#define ll long long
#define rnd mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().count())
#define pi pair<int,int>

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  cin >> t;

  while (t--) {

    int n;
    cin >> n;

    string s;
    cin >> s;

    vector<int> pl(n+1,0), pr(n+1,0), pu(n+1,0), pd(n+1,0);

    fori(i,0,n-1) {
      if (s[i] == 'L')
        pl[i+1] = 1+pl[i-1];
      if (s[i] == 'R')
        pr[i+1] = 1+pr[i-1];
      if (s[i] == 'U')
        pu[i+1] = 1+pu[i-1];
      if (s[i] == 'D')
        pd[i+1] = 1+pd[i-1];
    }

    fori(i,1,n)
      cout << pl[i] << pr[i] << pu[i] << pd[i] << endl;

    vector<int> clr(n,0), cud(n,0);
    vector<int> cudKMB, clrKMB;
    map<int,int> mplr, mpud;
    set<int> stlr, stud;

    fori(i,0,n-1) {

      //for up down

      int C = pu[i+1] - pd[i+1];
      if (stud.find(C) != stud.end()) {
        //mil gaya
        cud[i] = mpud[C];
      } else {
        cud[i] = -1;
      }
      stud.insert(C);
      mpud[C] = i;
      if (C == 0) {
        cudKMB.pb(i);
      }
      // for left right

      C = pl[i+1] - pr[i+1];
      if (stlr.find(C) != stlr.end()) {
        //mil gaya
        clr[i] = mplr[C];
      } else {
        clr[i] = -1;
      }
      stlr.insert(C);
      mplr[C] = i;
      if (C == 0)
        clrKMB.pb(i);
      // cout << i << " " << clr[i] << " " << cud[i] << endl;
    }

    int ans = INT_MAX, ans_left = -1, ans_right = -1;

    fori(i,0,n-1) {

      if (clr[i] != -1 && cud[i] != -1) {
        int cnt1 = i-clr[i]+1;
        int cnt2 = i-cud[i]+1;
        if (max(cnt1,cnt2) < ans) {
          ans = max(cnt1,cnt2);
          ans_left = max(clr[i], cud[i]);
          ans_right = i;
        }
      } else if (clr[i] != -1 && cud[i] == -1) {
        //find if ud is in clr[i] i
        auto it = lower_bound
      }
    }

    fori(i,0,n-1) {
      if (clr[i] != -1  cud[i] != -1) {

      }
    }

    if (ans != INT_MAX)
      cout << ans_left+1 << " " << ans_right+1 << endl;
    else
      cout << -1 << endl;

  }
    return 0;
}
