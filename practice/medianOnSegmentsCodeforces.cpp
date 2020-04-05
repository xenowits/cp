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

//wonderful problem to learn : check its editorial

ll binpow(ll a, ll b) {
    ll res = 1;
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
  int n, m;
  cin >> n >> m;
  vector<int> p(n);
  fori(i, 0, n-1)
      cin >> p[i];
  map<int,int> c;
  c[0] = 1;
  bool has = false;
  int sum = 0;
  long long ans = 0;
  //best thing : to define a function (greater - less)
  //so if (G-g = L-l) ==> (G-L = g-l)
  //thus if we find (g-l) before that's one of possible left index
  //there's a catch though : only indices(l) that are left of i(st A[i] = m) are to be taken
  //for that has boolean variable is used
  
  for (int r = 0; r < n; r++) {
      if (p[r] < m)
          sum--;
      else if (p[r] > m)
          sum++;

      if (p[r] == m)
          has = true;
      if (has)
          ans += c[sum] + c[sum - 1];
      else
          c[sum]++;
  }
  cout << ans << endl;
	return 0;
}
