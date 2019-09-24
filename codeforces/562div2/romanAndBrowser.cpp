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

int n,k;
int ans = 0;

void solve(int a, vector<int> v)
{
  for(int i = (1-a)/k; i <= (n-a)/k; ++i)
  {
    int c = a + i*k;
    v[c] = 0;
  }

  int e = 0, s = 0;
  for(int i = 1; i <= n; ++i)
  {
    if (v[i] == -1)
      e += 1;
    else if (v[i] == 1)
      s += 1;
  }
  // cout << a << " " << e <
  ans = max(ans,abs(e-s));
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n >> k;
  vector<int> v(n+1);
  int e = 0, s = 0;
  fori(i,1,n)
  {
    cin >> v[i];
    if (v[i] == -1)
      s += 1;
    else
      e += 1;
  }
  // cout << e << " " << s << endl;
  // ans = abs(e-s);
  for (int i = 1; i <= n; ++i)
  {
    solve(i,v);
  }

  cout << ans << endl;

  return 0;
}
