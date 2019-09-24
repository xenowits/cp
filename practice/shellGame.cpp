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

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll n,x;
  cin >> n >> x;
  //leftmost
  int a1[6] = {0,1,2,2,1,0}, a2[6] = {1,0,0,1,2,2}, a3[6] = {2,2,1,0,0,1};
  if (a1[n%6] == x)
  {
    cout << 0 << endl;
    exit(0);
  }
  if (a2[n%6] == x)
  {
    cout << 1 << endl;
    exit(0);
  }
  if (a3[n%6] == x)
  {
    cout << 2 << endl;
    exit(0);
  }
  return 0;
}
