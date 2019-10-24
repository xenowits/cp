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

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

	ll n, p, w, d, x, y, z;
	cin >> n >> p >> w >> d;

	x = p/w;

	if (p%(__gcd(w,d)) != 0)
	{
		cout << -1 << endl;
		exit(0);
	}

	while ((p-w*x)%d != 0)
	{
		x -= 1;
	}
	
	y = (p-w*x)/d;

	z = n-(x+y);

	if (x < 0 || y < 0 || z < 0)
		cout << -1 << endl;
	else
		cout << x << " " << y << " " << z << endl;

  return 0;
}
