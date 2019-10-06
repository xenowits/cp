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

  int q;
  cin >> q;

  while (q--)
  {
    int n;
    ll sum = 0;
    cin >> n;
    vector<ll> v(n);
    fori(i,0,n-1)
    {
      cin >> v[i];
      sum += v[i];
    }
    cout << (ll)ceil((sum+0.0)/n) << endl;
  }

  return 0;
}
