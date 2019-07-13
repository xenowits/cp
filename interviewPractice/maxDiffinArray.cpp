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
  int ans = v[0], diff = INT_MIN;
  fori(i,1,v.size()-1)
  {
    if (v[i] > ans && ((v[i]-ans) > diff))
    {
      diff = v[i]-ans;
      //cout << v[i] << " " << ans << " " << diff << endl;
    }
    else if (v[i] < ans)
    {
      ans = v[i];
      //cout << "new ans is " << ans << endl;
    }
  }
  cout << diff << endl;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  rnd;
  // vector<int> v;
  // fori(i,1,12)
  // {
  //   v.pb(uniform_int_distribution<int>(1,20)(rng));
  // }
  vector<int> v{7,9,5,6,3,2};
  for(int a : v)
    cout << a << " ";
  cout << endl << "max difference is" << endl;
  solve(v);
  return 0;
}
