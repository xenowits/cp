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
  ll temp = x-y;
  if (temp == 0 && z == 0)
    cout << "0" << endl;
  else if (temp == 0 && z>0)
    cout << "?" << endl;
  else if (temp<0 && abs(temp)>z)
  {
    cout << "-" << endl;
  }
  else if (temp>0 && abs(temp)>z)
  {
    cout << "+" << endl;
  }
  else if (abs(temp) <= z)
    cout << "?" << endl;
  return 0;
}
