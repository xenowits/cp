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
  vector<ll> v(n+1);
  int maxu = INT_MIN, minu = INT_MAX;
  fori(i,1,n)
  {
    cin >> v[i];
    int temp = v[i];
    maxu = max(maxu,temp);
    minu = min(minu,temp);
    //cout << maxu << " " << minu << endl;
  }
  int maxindx, minidx;
  fori(i,1,n)
  {
    if (v[i] == maxu)
    {
      maxindx = i;
      break;
    }
  }
  ford(i,n,1)
  {
    if (v[i] == minu)
    {
      minidx = i;
      break;
    }
  }
  //cout << maxindx << " " << minidx << endl;
  int ans = maxindx-1 + n-minidx;
  if (maxindx > minidx)
    ans -= 1;
  cout << ans << endl;
  return 0;
}
