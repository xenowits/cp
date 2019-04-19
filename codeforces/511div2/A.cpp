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
  long int n;
  cin >> n;
  if (n%3 == 0)
    cout << 1 << " " << 1 << " " << n-2;
  else
    cout << 1 << " " << 2 << " " << n-3;
  return 0;
}
