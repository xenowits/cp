#include<bits/stdc++.h>
using namespace std;

#define fori(i,a,b) for (long long int i = a; i <= b ; ++i)
#define ford(i,a,b) for(long long int i = a;i >= b ; --i)
#define mk make_pair
#define mod 998244353
#define pb push_back
#define ll long long
#define MAXN 300001
#define rnd mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().cnt())
#define pi pair<long long int,long long int>
#define sc second
#define fs first

ll ans = 0, n = 3,k = 9;
int no[4] = {0,3,6};

void solve(int indx, bool smaller, int sum)
{
  //cout << indx << " " << (smaller ? "small " : "big ") << remainder << " " << dgt << endl;
  if (indx == n)
  {
    if (sum == 0)
      ans += 1;
    return;
  }

  int limit;
  if (smaller)
    limit = no[indx];
  else
    limit = 9;
  //cout << limit << endl;
  for(int d = 0; d <= limit; ++d)
  {
    if (d<no[indx])
      solve(indx+1,0,sum-d);
    else
      solve(indx+1,smaller,sum-d);
  }
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  solve(1,1,k);
  
  cout << ans << endl;
  return 0;
}
