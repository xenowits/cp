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
    int ans1 = -1, ans2 = -1;
    fori(i,0,n-1) {
      if ((s[i]-'0')%2 == 1) {
        if (ans1 == -1) {
          ans1 = s[i]-'0';
        } else if (ans2 == -1) {
          ans2 = s[i]-'0';
          break;
        }
      }
    }
    if (ans1 != -1 && ans2 != -1) {
      cout << ans1 << ans2 << endl;
    } else {
      cout << -1 << endl;
    }
  }

  return 0;
}
