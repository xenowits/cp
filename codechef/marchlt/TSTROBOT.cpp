#include<bits/stdc++.h>
using namespace std;

#define fori(i,a,b) for (int i = a; i <= b ; ++i)
#define ford(i,a,b) for(int i = a;i >= b ; --i)
#define mk make_pair
#define mod 1000000007

int main()
{
  ios_base::sync_with_stdio(false);cin.tie(0);
  int t,n,x,temp;
  cin >> t;
  while (t>0)
  {
    string str;
    set<int> s;
    cin >> n >> x >> str;
    s.insert(x);temp = x;
    fori(i,0,n)
    {
      if (str[i] == 'R')
      {
        temp = temp+1;
        if (s.find(temp) == s.end())
        {
          s.insert(temp);
        }
      }
      if (str[i] == 'L')
      {
        temp = temp-1;
        if (s.find(temp) == s.end())
        {
          s.insert(temp);
        }
      }
    }
    t-=1;
    if (t>0)
      cout << s.size() << "\n";
    else
      cout << s.size();
  }
  return 0;
}
