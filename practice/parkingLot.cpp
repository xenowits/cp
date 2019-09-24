#include <bits/stdc++.h>
using namespace std;

#define ll long long int

ll binpow(ll a, ll b)
{
  ll ans = 1;
  while (b > 0) {
    // wo bit set h, tujhe a ka value pta h, tu bas ans m use multiply kr de---ingenious
    if (b&1)
      ans = ans*a;
    // hr loop m a ko a squared krte ja
    a = a*a;
    // b ko right shift krte jaa
    b >>= 1;
  }
  return ans;
}

int main()
{
  int n;
  cin >> n;

  ll ans = 0;

  ans += 4*2*3*binpow(4,n-3) + 4*(n-1-2)*3*3*binpow(4,n-4);

  cout << ans << endl;

}
