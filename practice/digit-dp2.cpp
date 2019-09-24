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

ll ans = 0, n = 4,k = 3;
int no[4] = {0,3,3,3};

void solve(int indx, bool smaller, int remainder)
{
  //cout << indx << " " << (smaller ? "small " : "big ") << remainder << " " << dgt << endl;
  if (indx == n)
  {
    if (remainder == 0)
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
      solve(indx+1,0,(remainder+d)%k);
    else
      solve(indx+1,smaller,(remainder+d)%k);
  }
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  
  solve(1,1,0);
  cout << ans << endl;
  return 0;
}
