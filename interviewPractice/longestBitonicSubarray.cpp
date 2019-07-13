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

void solve(vector<int> v)
{
  int n = v.size();
  vector<int> dec(n,1), inc(n,1);
  dec[n-1] = 1;inc[0] = 1;
  fori(i,1,n-1)
  {
    if (v[i] > v[i-1])
      inc[i] = 1 + inc[i-1];
  }
  ford(i,n-1,1)
  {
    if (v[i] < v[i-1])
      dec[i-1] = 1 + dec[i];
  }
  int ans = INT_MIN;
  fori(i,0,n-1)
  {
    if (ans < dec[i]+inc[i])
    {
      ans = dec[i]+inc[i];
      cout << ans << " " << i << " is it" << endl;
    }
    //ans = max(ans,dec[i]+inc[i]);
  }
  cout << ans << endl;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  rnd;
  vector<int> v;
  fori(i,1,12)
  {
    v.pb(uniform_int_distribution<int>(1,20)(rng));
  }
  // vector<int> v{7,9,5,6,3,2};
  for(int a : v)
    cout << a << " ";
  cout << "Longest bitonic subarray length is:" << endl;
  solve(v);
  return 0;
}
