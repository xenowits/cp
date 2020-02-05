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

  while (t) {
    int n;
    cin >> n;
    int flag1 = 0, flag0 = 0;
    vector<int> v(n+1,0);
    fori(i,1,n) {
      cin >> v[i];
      if (v[i]%2 == 1) {
        flag1 += 1;
        //break;
      } else {
        flag0 += 1;
      }
    }
    if ((flag1%2 == 1) || (flag1 && flag0)) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
    t -= 1;
  }

  return 0;
}
