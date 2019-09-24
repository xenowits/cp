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

bool ans = 0;
int n;
vector<int> v;

bool solve(int f,int pos)
{
  //cout << f << " " << pos << endl;
  if (pos == n&& f == 0)
    return 1;
  else if (pos == n && f != 0)
    return 0;
  int x = f+v[pos], y = (f-v[pos]);
  if (y < 0)
    y += 360;
  if (x > 360)
    x -= 360;
  return solve(x,pos+1) || solve(y,pos+1);
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int a;
  cin >> n;

  int clk = 0, aclk = 0;

  fori(i,1,n)
  {
    cin >> a;
    v.pb(a);
  }

  if (solve(0,0))
    cout << "YES" << endl;
  else
    cout << "NO" << endl;

  return 0;
}
