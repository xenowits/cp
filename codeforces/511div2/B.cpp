#include<bits/stdc++.h>
using namespace std;

#define fori(i,a,b) for (long int i = a; i <= b ; ++i)
#define ford(i,a,b) for(long int i = a;i >= b ; --i)
#define mk make_pair
#define mod 1000000007
#define pb push_back
#define ll long long

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  long int x,y,a,b;
  vector<pair<long,long> > v;
  float dist_max = 0,dist_temp;
  fori(i,1,n)
  {
    cin >> a >> b;
    dist_temp = a + b;
    if (dist_temp > dist_max)
      dist_max = dist_temp;
  }
  cout << dist_max;

  return 0;
}
