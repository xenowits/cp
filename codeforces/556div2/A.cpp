#include<bits/stdc++.h>
using namespace std;

#define fori(i,a,b) for (long int i = a; i <= b ; ++i)
#define ford(i,a,b) for(long int i = a;i >= b ; --i)
#define mk make_pair
#define mod 1000000007
#define pb push_back
#define ll long long
#define rnd mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().count())

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n,m,r;
  cin >> n >> m >> r;
  vector<ll> a(n), b(m);
  fori(i,0,n-1)
    cin >> a[i];
  fori(i,0,m-1)
    cin >> b[i];
  sort(a.begin(),a.end());
  sort(b.begin(),b.end(), greater<int>());
  ll cpq = r/a[0];
  ll rem = r - cpq*a[0];
  ll sp = b[0]*cpq;
  //cout << cpq << " " << rem << " " << sp << endl;
  if (rem + sp > r)
    cout << rem+sp;
  else
    cout << r;
  return 0;
}
