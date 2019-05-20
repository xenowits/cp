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
  ll n,count = 1;
  cin >> n;
  if (n < 10)
  {
    cout << 9 << endl;
    return 0;
  }
  n += 1;
  while (n > 9)
  {
    if (n%10 == 0)
    {
      while (n%10 == 0)
      {
        n = n/10;
      }
      continue;
    }
    count += 1;
    n += 1;
  }
  cout << count + 9;
  return 0;
}
