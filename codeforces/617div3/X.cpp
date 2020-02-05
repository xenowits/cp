#include<bits/stdc++.h>
using namespace std;

#define fori(i,a,b) for (int i = a; i <= b ; ++i)
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
    map<pi,int> mp;
    string s;
    cin >> s;

    int ans = INT_MAX;
    int x = 0, y = 0;
    mp[mk(x,y)] = 0;

    fori(i,0,n-1) {
      char ch = s[i];
      if (ch == 'L')
        x -= 1;
      else if (ch == 'R')
        x += 1;
      else if (ch == 'U')
        y += 1;
      else if (ch == 'D')
        y -= 1;
      int temp = mp[mk(x,y)];
      if (temp > 0) {
        cout << temp << " " << i+1 << endl;
        ans = min(ans,i+1-temp);
      } else if (temp == 0 && x == 0 && y == 0) {
        ans = min(ans,i+1);
      }
      mp[mk(x,y)] = i+1;
    }
    cout << ans << endl;

  }
  // map<pi,int> mp;

  return 0;
}
