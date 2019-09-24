#include<bits/stdc++.h>
using namespace std;

#define fori(i,a,b) for (long int i = a; i <= b ; ++i)
#define ford(i,a,b) for(long int i = a;i >= b ; --i)
#define mk make_pair
#define mod 1000000007
#define pb push_back
#define vec vector<long long int>
#define ll long long
#define rnd mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().count())
#define pi pair<int,int>
#define sc second
#define fs first


int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  stack<char> stk;
  string s;
  cin >> s;
  int cnt = 0;
  for(int i = 0 ; i < s.length(); ++i)
  {
    char ch = s[i];

    if (ch == '[' || ch == ':' || ch == '|')
      stk.push('[');

    if ((ch >= 'a' && ch <= 'z'))
      cnt += 1;
    if (ch == ']')
    {
      //stk.pop();
      // if (stk.top() != ':')
      // {
        //   cout << -1 << endl;
        //   return 0;
        // }
      while (!stk.empty() && stk.top() != ':')
      {
        stk.pop();
        ans += 1;
      }
      // not stack top is :
      while (!stk.empty() && stk.top() != ':')
      
      if (stk.empty())
        cout << -1 << endl;
      else
        stk.pop();
    }
  }
  if (stk.empty())
    cout << -1 << endl;
  else
    cout << ans << endl;
  return 0;
}
