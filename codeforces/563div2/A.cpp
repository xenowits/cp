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
  int n;
  cin >> n;
  bool even = false, odd = false;
  vector<ll> v(n);
  fori(i,0,n-1)
  {
    cin >> v[i];
    if (v[i]&1)
      odd = true;
    else
      even = true;
  }
  if (even && odd)
    sort(v.begin(),v.end());
  for(auto i : v)
    cout << i << " ";
  cout << endl;
  return 0;
}
