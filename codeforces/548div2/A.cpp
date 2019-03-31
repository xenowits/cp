#include<bits/stdc++.h>
using namespace std;

#define fori(i,a,b) for (int i = a; i <= b ; ++i)
#define ford(i,a,b) for(int i = a;i >= b ; --i)
#define mk make_pair
#define mod 1000000007

int main()
{
  ios_base::sync_with_stdio(false);cin.tie(0);
  int n,count = 0;
  string s;
  cin >> n >> s;
  if (n == 1)
  {
    if (s[0] == '2' || s[0] == '4' || s[0] == '6' || s[0] == '8')
    {
      cout << 1;
      return 0;
    }
    cout << 0;
    return 0;
  }
  fori(i,0,n)
  {
    if (s[i] == '2' || s[i] == '4' || s[i] == '6' || s[i] == '8')
    {
      count+=i+1;
    }
  }
  cout << count;
  return 0;
}
