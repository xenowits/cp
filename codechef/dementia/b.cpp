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
  int n;string str;
  cin >> n >> str;
  int a[11];
  fori(j,1,9)
  {
    cin >> a[j];
  }
  int i;
  for(i = 0; i <= n-1; ++i)
  {
    if (a[str[i]-'0'] > str[i]-'0')
      break;
  }
  fori(j,i,n-1)
  {
    if (a[str[j]-'0'] >= str[j]-'0')
    {
      str[j] = a[str[j]-'0']+'0';
    }
    else
      break;
  }
  cout << str;
  return 0;
}
