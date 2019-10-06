#include <bits/stdc++.h>
#define li long long int
using namespace std;

#define MOD 1000000007

set<li> primeFactors(li n) {
  set<li> fac;
  while (n % 2 == 0) {
    // cout << 2 << " ";
    fac.insert(2);
    n = n / 2;
  }

  for (int i = 3; i <= sqrt(n); i = i + 2) {
    while (n % i == 0) {
      // cout << i << " ";
      fac.insert(i);
      n = n / i;
    }
  }

  if (n > 2)
    fac.insert(n);
  // cout << n << " ";
  return fac;
}

li largestPower(li n, li p) {
  li x = 0;

  while (n) {
    n /= p;
    x += n;
  }
  return x;
}

li power(li x, li y) {
  li res = 1;
  x = x % MOD;
  while (y > 0) {
    if (y & 1)
      res = (res * x) % MOD;
    y = y >> 1; // y = y/2
    x = (x * x) % MOD;
  }
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  li n, x;
  cin >> x >> n;

  set<li> fac = primeFactors(x);
  li ans = 1, temp;
  for(auto a : fac) {
    // cout << a << ' ';
    temp = largestPower(n, a);
    ans = (ans * power(a, temp)) % MOD;
  }

  cout << ans << '\n';

  return 0;
}
