//xenowitz -- Jai Shree Ram
#include<bits/stdc++.h>
using namespace std;

#define fori(i,a,b) for (long int i = a; i <= b ; ++i)
#define ford(i,a,b) for(long int i = a;i >= b ; --i)
#define mk make_pair
#define mod 1000000007
#define pb push_back
#define vec vector<long long int>
#define ll long long
#define rnd mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().count())
#define pi pair<long long int,long long int>
#define sc second
#define fs first
#define MAXN 1e16+9

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  cin >> t;

  while (t--) {
    int n, k;
    cin >> n >> k;
    vector<ll> v(n,0);
    fori(i,0,n-1) {
      cin >> v[i];
    }
    vector<ll> peldenge;
    int cnt = 0;
    ll temp;
    while (1) {
      temp = (ll)pow(k,cnt);
      if (temp > MAXN) {
        break;
      }
      peldenge.pb(temp);
      cnt += 1;
    }
    reverse(peldenge.begin() , peldenge.end());
    // for (auto x : peldenge) {
    //   cout << x << " pel ";
    // }
    // cout << endl;
    //now powers are calculated
    set<ll> st;
    bool kharab = false;
    fori(i,0,n-1) {
      if (v[i] == 0) {
        continue;
      }
      //cout << v[i] << " bhai" << endl;
      for (auto x : peldenge) {
        if (v[i] >= x) {
          if (st.find(x) != st.end()) {
            //mil gya
            kharab = true;
            //cout << x << " tar " << endl;
            break;
          }
          st.insert(x);
          v[i] -= x;
          //cout << x << " jah " << endl;
        }
        if (v[i] == 0) {
          break;
        }
      }
      //cout << v[i] << " chut" << endl;
      if (v[i] != 0) {
        kharab = true;
      }
      if (kharab) {
        break;
      }
    }
    if (kharab) {
      cout << "NO" << endl;
    } else {
      cout << "YES" << endl;
    }
    //cout << endl;
  }

  return 0;
}
