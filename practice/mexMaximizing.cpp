//xenowits -- Jai Shree Ram
#include<bits/stdc++.h>
using namespace std;

#define fori(i,a,b) for (long long int i = a; i <= b ; ++i)
#define ford(i,a,b) for(long long int i = a;i >= b ; --i)
#define mk make_pair
#define mod 998244353
#define pb push_back
#define ll long long
#define ld long double
#define rnd mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().cnt())
#define pi pair<long long int,long long int>
#define sc second
#define fs first

const int MAXN = 500001;

vector<int> v(MAXN,0), pointers(MAXN,0);
ll q;

ll mexCalculator(ll mex) {
  fori(i,mex,q) {
    if (v[i] == 0) {
      return i;
    }
  }
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  ll x, y;
  cin >> q >> x;

  ll mex = 0, temp1 = q, temp;
  fori(i,0,k-1) {
    pointers[i] = i;
  }

  while (temp1--) {
    cin >> y;

    cout << mex << endl;
  }

	return 0;
}
