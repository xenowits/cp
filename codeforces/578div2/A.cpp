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

  int n;
  cin >> n;

  string s;
  cin >> s;

  vector<int> v(10,0);

  int l = 0, r = 9;

  for (int i = 0 ; i < s.length(); ++i)
  {
    if (s[i] == 'L')
    {
      v[l] = 1;
      for (int x = 0; x < 10; ++x)
      {
        if (v[x] == 0)
        {
          l = x;
          break;
        }
      }
    }
    else if (s[i] == 'R')
    {
      v[r] = 1;
      for (int x = 9; x >= 0; --x)
      {
        if (v[x] == 0)
        {
          r = x;
          break;
        }
      }
    }
    else
    {
      ll temp = s[i]-'0';
      v[temp] = 0;
      for (int x = 0; x < 10; ++x)
      {
        if (v[x] == 0)
        {
          l = x;
          break;
        }
      }
      for (int x = 9; x >= 0; --x)
      {
        if (v[x] == 0)
        {
          r = x;
          break;
        }
      }
    }
  }
  fori(i,0,9)
    cout << v[i];
  return 0;
}
