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

  int n;
  cin >> n;
  vector<int> v(n+1);
  for(int i = 1; i <=n; ++i)
    cin >> v[i];

  vector<int> v1end(n+1,0), v2end(n+1,0), v1start(n+1,0), v2start(n+1,0);

  for(int i = 1; i <= n; ++i)
  {
    if (v[i] == 1)
    {
      v1end[i] = 1+v1end[i-1];
    }
    else
      v2end[i] = 1+v2end[i-1];
  }

  for (int i = 1; i <= n; ++i)
  {
    if (v[i] == 1)
      v1start[i-v1end[i]+1] = v1end[i];
    else
      v2start[i-v2end[i]+1] = v2end[i];
  }

  // main algorithm here
  int ans = 0;
  for(int i = 1; i < n; ++i)
  {
    int temp = max( min(v1end[i],v2start[i+1]), min(v2end[i],v1start[i+1]));
    ans = max(ans,temp);
  }

  cout << 2*ans << endl;

  return 0;
}
