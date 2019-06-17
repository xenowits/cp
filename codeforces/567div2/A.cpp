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
  ll x,y,z;
  cin >> x >> y >> z;
  ll a = x%z; ll b = y%z;
  ll total = x/z+y/z;
  ll temp = 0;
  if (a+b >= z)
  {
    total += 1;
    temp = z-max(a,b);
  }
  cout << total << " " << temp;
  return 0;
}
