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
#define pi pair<int,int>
#define sc second
#define fs first

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll n,m,q,sx,sy,ex,ey;
  cin >> n >> m >> q;
  ll g = __gcd(n,m);
  n /= g, m /= g;
  //cout << g << endl;
  while (q--)
  {
      cin >> sx >> sy >> ex >> ey;
      sy = (sy - 1) / (sx == 1 ? n : m);
  		ey = (ey - 1) / (ex == 1 ? n : m);
  		cout << (sy == ey ? "YES" : "NO") << '\n';
  }
  return 0;
}
