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
  int n,m,z;
  cin >> n >> m >> z;
  long count = 0;
  long lcm = (n*m)/(__gcd(n,m));
  fori(i,1,z)
  {
    if (i%lcm == 0)
      count += 1;
  }
  cout << count;
  return 0;
}
