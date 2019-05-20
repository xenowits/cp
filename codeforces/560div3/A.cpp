#include<bits/stdc++.h>
using namespace std;

#define fori(i,a,b) for (long int i = a; i <= b ; ++i)
#define ford(i,a,b) for(long int i = a;i >= b ; --i)
#define mk make_pair
#define mod 1000000007
#define pb push_back
#define ll long long
#define rnd mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().count())

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll n,x,y;
  cin >> n >> x >> y;
  string s,stemp2 = "";
  cin >> s;
  string stemp1 = s.substr(n-x,x);
  //cout << stemp1 << endl;
  fori(i,0,x-1)
  {
    if (i == x-1-y)
      stemp2 += '1';
    else
      stemp2 += '0';
    //cout << i << " " << n-1-y << endl;
  }
  //cout << stemp2;
  ll cnt = 0;
  fori(i,0,x)
  {
    if (stemp1[i] != stemp2[i])
      cnt += 1;
  }
  cout << cnt;
  return 0;
}
