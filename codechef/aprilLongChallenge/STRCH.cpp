#include<bits/stdc++.h>
using namespace std;

#define fori(i,a,b) for (long int i = a; i <= b ; ++i)
#define ford(i,a,b) for(int i = a;i >= b ; --i)
#define mk make_pair
#define mod 1000000007
#define pb push_back

void solver(int n, string s, char ch)
{
  long int cnt = 0, final = (n*(n+1))/2;
  fori(i,0,n-1)
  {
    if (s[i] != ch)
      cnt+=1;
    else
    {
      final -= (cnt*(cnt+1))/2;
      cnt = 0;
    }
  }
  final -= (cnt*(cnt+1))/2;
  cout << final << endl;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long int n,t;
  cin >> t;
  while (t>0)
  {
    cin >> n;
    string s;char ch;
    cin >> s >> ch;
    long int cnt = 0, final = (n*(n+1))/2;
    fori(i,0,n-1)
    {
      if (s[i] != ch)
        cnt+=1;
      else
      {
        final -= (cnt*(cnt+1))/2;
        cnt = 0;
      }
    }
    final -= (cnt*(cnt+1))/2;
    cout << final << endl;
    t-=1;
  }
  return 0;
}
