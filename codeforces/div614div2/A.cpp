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
    ll n, s, k, temp;
    cin >> n >> s >> k;
    map<ll,bool> mp;
    fori(i,1,k) {
      cin >> temp;
      mp[temp] = true;
    }
    ll ans1 = INT_MAX, ans2 = INT_MAX;
    fori(i,s,n) {
      if (!mp[i]){
        ans1 = i-s;
        break;
      }
    }
    ford(i,s,1) {
      if (!mp[i]){
        ans2 = s-i;
        break;
      }
    }
    //cout << ans1 << " " << ans2 << endl;
    cout << min(ans1, ans2) << endl;
  }

  return 0;
}
