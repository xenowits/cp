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
  string s;
  cin >> s;
  int n = s.length();
  bool likhega = false;
  fori(i,0,n-1)
  {
      if (s[i] == 'H')
        likhega = true;
      if (s[i] == 'Q')
        likhega = true;
      if (s[i] == '9')
        likhega = true;
  }
  if (likhega)
    cout << "YES";
  else
    cout << "NO";
  return 0;
}
