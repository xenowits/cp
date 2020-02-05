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
    ll s;
    cin >> s;
    ll sumod = 0;
    ll temp = 0, temp2 = 0;
    while (s >= 10) {
      temp = s/10;
      temp2 += temp*10;
      s = s%10;
      s += temp;
    }
    // cout << temp << " " << sumod << endl;
    // while (sumod) {
    //   sumod /= 10;
    //   temp += sumod;
    // }
    cout << temp2+s << endl;
  }

  return 0;
}
