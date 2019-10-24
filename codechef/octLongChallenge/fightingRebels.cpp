#include <bits/stdc++.h>
using namespace std;

#define fs first
#define sc second
typedef unsigned long long ll;

ll findLCM(vector<ll> &rebels, ll n)
{
  ll ans = rebels[1];

  for(int i = 2; i <= n; ++i)
  {
    ans = ((rebels[i]*ans)/(__gcd(rebels[i], ans)));
  }

  return ans;
}

int main()
{
  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;
    vector<ll> rebels(n+1);
    for(int i = 1; i <= n; ++i)
      cin >> rebels[i];
    ll lower, upper;
    cin >> lower >> upper;
    ll total = upper-lower+1;
    ll lcm = findLCM(rebels,n);
    //cout << lcm << endl;
    //cout << total << endl;
    ll marjaa = upper/lcm - (lower-1)/lcm;
    //cout << marjaa << endl;
    cout << total - marjaa << endl;
  }
}
