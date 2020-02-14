//xenowitz -- Jai Shree Ram
#include<bits/stdc++.h>
using namespace std;

#define fori(i,a,b) for (long long int i = a; i <= b ; ++i)
#define ford(i,a,b) for(long long int i = a;i >= b ; --i)
#define mk make_pair
#define mod 998244353
#define pb push_back
#define ll long long
#define ld long double
#define MAXN (ll)1e6+5
#define rnd mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().cnt())
#define pi pair<long long int,long long int>
#define sc second
#define fs first

ll base3giver(vector<int> v) {
  int n = v.size();
  // cout << "aya" << endl;
  ll sum = 0, temp = 1;
  for (auto x : v) {
    sum += (temp*x);
    temp *= 3;
    // cout << x << " ";
  }
  // cout << endl;
  return sum;
}

long long binpow(long long a, long long b) {
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int q;
  cin >> q;

  while (q--) {
    ll n;
    cin >> n;
    vector<int> v;
    while (n) {
      // cout << (n%3) << " ";
      v.pb(n%3);
      n /= 3;
    }
    int sz = v.size();
    // v.resize(sz+1);
    int carry = 0;
    fori(i,0,sz-1) {
      int temp = carry+v[i];
      if (temp >= 2) {
        v[i] = 0;
        carry = 1;
      } else {
        v[i] = temp;
      }
    }

    if (carry) {
      // v[sz] = carry;
      cout << binpow(3,sz) << endl;
    } else {
      cout << base3giver(v) << endl;
    }
  }

	return 0;
}
