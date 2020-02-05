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
    vector<ll> v(n+1,0), prefixZeroes(n+1,0);
    fori(i,1,n) {
      cin >> v[i];
      if (v[i] == 0)
        prefixZeroes[i] += (1+prefixZeroes[i-1]);
      else
        prefixZeroes[i] += prefixZeroes[i-1];
    }
    //check
    string ans = "No";
    fori(i,1,n) {
      if (v[i] >= max(i-1,n-i)) {
        ll temp1 = prefixZeroes[n]-prefixZeroes[i];
        ll temp2 = prefixZeroes[i-1]-prefixZeroes[0];
        
        //cout << temp1 << temp2 << endl;
        if (temp1 > 1 || temp2 > 1) {
          continue;
        }
        if ((temp1 == 1 && v[n] != 0)) {
          // cout << "fuc" << endl;
            continue;
        }
        if ((temp2 == 1 && v[1] != 0)) {
          // cout << "fuck" << endl;
          continue;
        }
        ans = "Yes";
        break;
      }
    }
    cout << ans << endl;
  }

  return 0;
}
