#include<bits/stdc++.h>
using namespace std;

#define fori(i,a,b) for (long int i = a; i <= b ; ++i)
#define ford(i,a,b) for(long int i = a;i >= b ; --i)
#define mk make_pair
#define mod 1000000007
#define pb push_back
#define ll long long
#define rnd mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().count())
#define pi pair<int,int>

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll t;
  cin >> t;
  std::vector<int> v(6,8);
  v[1] = 10;
  fori(i,2,5)
  {
    v[i] += v[i-1] + 4*((int)(pow(2,i)+0.5) - 2);
  }
  while (t>0)
  {
    ll k;
    cin >> k;
    cout << v[k] << endl;
    t-=1;
  }
  return 0;
}
