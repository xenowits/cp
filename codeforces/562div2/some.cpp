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

  int n,h,m,l,r,x;
  cin >> n >> h >> m;
  vector<int> height(n+1,h);
  for(int i = 1; i <= m; ++i)
  {
    cin >> l >> r >> x;
    for(int j = l; j <= r; ++j)
    {
      height[j] = min(height[j],x);
    }
  }
  ll sum = 0;
  for(int i = 1; i <= n; ++i)
    sum += (height[i]*height[i]);
  cout << sum << endl;
  return 0;
}
