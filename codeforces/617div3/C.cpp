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
        pl[i+1] = pl[i]+pl[i-1];
      if (s[i] == 'R')
        pr[i+1] = pr[i]+pr[i-1];
      if (s[i] == 'U')
        pu[i+1] = pu[i]+pu[i-1];
      if (s[i] == 'D')
        pd[i+1] = pd[i]+pd[i-1];
    }

    //two pointer technique

    int i = 0, j = 0, cnt1, cnt2;
    int ans = INT_MAX, ans_left = -1, ans_right = -1;

    while (i < n && j < n) {

      cnt1 = (pl[j+1]-pl[i]) - (pr[j+1]-pr[i]);
      cnt2 = (pu[j+1]-pu[i]) - (pd[j+1]-pd[i]);

      if (cnt1 == 0 || cnt2 == 0) {
        //left pointer ko aage lao
        while (i <= j) {

          cnt1 = (pl[j+1]-pl[i]) - (pr[j+1]-pr[i]);
          cnt2 = (pu[j+1]-pu[i]) - (pd[j+1]-pd[i]);

          if (cnt1 - cnt2 == 0) {
            if (j-i+1 < ans) {
              ans_left = i;
              ans_right = j;
              ans = j-i+1;
            }
          }

          i += 1;

        }
      }

      // if (cnt1 - cnt2 != 0) {
      //   //right pointer ko aage badhao
      //   j += 1;
      //
      // } else {
      //
      //   ans = min(ans, j-i+1);
      //   //left pointer ko aage lao
      //
      //   }
        i += 1;
      }

    }

  return 0;
}
