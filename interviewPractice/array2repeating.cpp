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

void solve(int n, vector<int> v)
{
  int ans = 0;
  fori(i,0,n-1)
    ans ^= v[i];
  int a = ans&(~(ans-1));
  cout << ans << " " << a << endl;
  vector<int> zero, one;
  fori(i,0,n-1)
  {
    int temp = v[i]&a;
    (temp == a) ? (zero.pb(v[i])) : (one.pb(v[i]));
  }
  a = 0;int b = 0;
  for(int x : zero)
    a ^= x;
  for(int x : one)
    b ^= x;
  cout << "The numbers are " << a << " " << b << endl;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  vector<int> v(n);
  fori(i,0,n-1)
    cin >> v[i];
  solve(n,v);
  return 0;
}
