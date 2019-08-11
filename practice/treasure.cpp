#include<bits/stdc++.h>
using namespace std;

#define fori(i,a,b) for (int i = a; i <= b ; ++i)
#define ford(i,a,b) for(int i = a;i >= b ; --i)
#define mk make_pair
#define mod 1000000007
#define pb push_back
#define ll long long
#define MAXN 100001
#define rnd mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().cnt())
#define pi pair<long long int,long long int>

int main()
{
  string s;
  cin >> s;
  int n = s.length();
  vector<int> v(n+1,0);
  vector<int> ans;
  for(int i = 0 ; i < n; ++i)
  {
      if (s[i] == ')')
      {
        v[i+1] = v[i]-1;
      }
      else if (s[i] == '(')
        v[i+1] = v[i]+1;
      else if (s[i] == '#')
      {
        v[i+1] = v[i]-1;
        ans.pb(i);
      }
      if (v[i+1] < 0)
      {
        cout << -1 << endl;
        return 0;
      }
      //cout << i+1 << " " << v[i+1] << endl;
  }
  int rem = v[n];
  int m = ans.size();
  v[ans[m-1]+1] -= v[n];
  if (v[ans[m-1]+1] < 0)
  {
    cout << -1 << endl;
    return 0;
  }
  //cout << ans[m-1]+1 << endl;
  for (int i = ans[m-1]+1; i < n; ++i)
  {
    if (s[i] == ')')
    {
      v[i+1] = v[i]-1;
    }
    else if (s[i] == '(')
      v[i+1] = v[i]+1;
    else if (s[i] == '#')
    {
      v[i+1] = v[i]-1;
      ans.pb(i);
    }
    if (v[i+1] < 0)
    {
      cout << -1 << endl;
      return 0;
    }
  }

  for (int i = 0 ; i < m-1; ++i)
    cout << 1 << endl;

  cout << 1+rem << endl;
  return 0;
}
