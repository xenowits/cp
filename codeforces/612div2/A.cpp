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

  cin >> t;
  while (t--) {
    int k, indx = -1;
    cin >> k;
    string str;
    cin >> str;
    int l = str.length();
    fori(i,0,l-1) {
      if (str[i] == 'A') {
        indx = i;
        break;
      }
    }
    if (indx == -1) {
      cout << 0 << endl;
      continue;
    }
    int ans = 0, cnt = 0;
    fori(i,indx+1,l-1) {
      bool flag = false;
      fori(j,i,l-1) {
        if (str[i] != str[j]) {
          flag = true;
          break;
        }
        cnt += 1;
      }
      if (flag)
      {
        ans = max(ans, cnt);
        cnt = 0;
      }
    }
  }

  return 0;
}
