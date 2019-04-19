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
  long int a,b,c,n;
  cin >> n >> a >> b >> c;
  int d = min(a,min(b,c));
  if (n == 1)
    cout << 0;
  else if (d == a || d == b)
    cout << (n-1)*d;
  else
    cout << (n-2)*d + min(a,b);
  return 0;
}
