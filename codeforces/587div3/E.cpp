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

  ll n,k;
  cin >> n >> k;

  vector<int> v(n);

  fori(i,0,n-1)
    cin >> v[i];

  if (n == k)   //only one operation
  {
    cout << 1 << endl;
    exit(0);
  }

  ll ans = 0;
  bool flag = 0;
  int maxu = INT_MIN, minu = INT_MAX;

  deque<int> dq;

  for(int i = 0; i <= n-k-1; ++i)
  {
    if (i == 0)
    {
      for(int j = i; j <= i+k-1; ++j)
      {
        maxu = max(maxu,v[j]);
        minu = min(minu,v[j]);
      }
    }

    if (v[i] == minu && v[i+k] > maxu)
    {
      flag = 1;
    }
    else if (flag)
    {
      ans += 1;
      flag = 0;
    }
    else
      ans += 1;
  }
  //cout << ans << endl;
  for(int i = n-k+1; i < n; ++i)
  {
    if (v[i] < v[i-1])
    {
      ans += 1;
      break;
    }
  }
  cout << ans << endl;
  return 0;
}
