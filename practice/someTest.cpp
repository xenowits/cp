#include<bits/stdc++.h>
using namespace std;

#define fori(i,a,b) for (long int i = a; i <= b ; ++i)
#define ford(i,a,b) for(long int i = a;i >= b ; --i)
#define mk make_pair
#define mod 1000000007
#define pb push_back
#define ll long long
#define rnd mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().count())

#define MAXN 10000007

// stores smallest prime factor for every number
int spf[MAXN];
//long long int f[MAXN];
vector<ll> f(MAXN,0);
// Calculating SPF (Smallest Prime Factor) for every
// number till MAXN.
// Time Complexity : O(nloglogn)
void sieve()
{
	spf[1] = 1;
	for (int i=2; i<MAXN; i++)

		// marking smallest prime factor for every
		// number to be itself.
		spf[i] = i;

	// separately marking spf for every even
	// number as 2
	for (int i=4; i<MAXN; i+=2)
		spf[i] = 2;

	for (int i=3; i*i<MAXN; i++)
	{
		// checking if i is prime
		if (spf[i] == i)
		{
			// marking SPF for all numbers divisible by i
			for (int j=i*i; j<MAXN; j+=i)

				// marking spf[j] if it is not
				// previously marked
				if (spf[j]==j)
					spf[j] = i;
		}
	}
}

// A O(log n) function returning primefactorization
// by dividing by smallest prime factor at every step
void getFactorization(int x)
{
  //cout << "aa gya" << endl;
  //cout << "x h " << x << endl;
  set<ll> s;
	while (x != 1)
	{
    //cout << "ghum raha hoo " << spf[x] << endl;
    //f[spf[x]] += 1;
    s.insert(spf[x]);
    //cout << x << " " << spf[x] << " " << f[spf[x]] <<  endl;
		x = x / spf[x];
	}
  for (auto i : s)
    f[spf[i]] += 1;
}


int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  sieve();
  int n;
  cin >> n;
  vector<int> v(n+1);
  fori(i,1,n)
  {
    cin >> v[i];
    getFactorization(v[i]);
  }
  fori(i,1,MAXN)
  {
    // if (f[i] != 0)
    //   cout << i << " " << f[i] << endl;
    f[i] += f[i-1];
  }
  //cout << "now enter m" << endl;
  int m;
  cin >> m;
  ll l,r;
  //cout << "f wala kaam bhi ho gya" << endl;
  fori(i,1,m)
  {
    cin >> l >> r;
    if (r > MAXN)
      r = MAXN;
    //cout << f[r] << " " << f[l-1] << endl;
    if (f[r] - f[l-1] < 0)
      cout << l << " is the l and r " << r << endl;
    cout << (f[r] - f[l-1]) << endl;
  }
  return 0;
}
