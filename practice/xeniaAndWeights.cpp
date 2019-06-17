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
#define pi pair<int,int>

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  string str;int m;
  cin >> str >> m;
  vector<int> s;
  fori(i,0,9)
  {
    if (str[i] == '1')
      s.pb(i+1);
  }
  int wts = s.size();
  ll a = 0, b = 0, recent;
  a += s[wts-1];
  recent = s[wts-1];
  m-=1;
  bool chance = false;
  ll temp;
  vector<int> v;
  v.pb(recent);
  while(m>0)
  {
    bool done = false;
    if (!chance)          //b ka chance
    {
      temp = a-b;
      //auto it = std::upper_bound(s.begin(),s.end(),temp);
      for(int x = wts-1; x>=0; ++x)
      {
        if (x > temp && x != recent)
        {
          done = true;
          b += x;
          recent = x;
          v.pb(x);
          break;
        }
      }
      if (!done)
      {
        cout << "NO" << endl;
        return 0;
      }
      chance = !chance;
    }
    else                 //a ka choice
    {
      temp = b-a;
      //auto it = std::upper_bound(s.begin(),s.end(),temp);
      for(int x = wts-1; x>=0; ++x)
      {
        if (x > temp && x != recent)
        {
          done = true;
          a += x;
          recent = x;
          v.pb(x);
          break;
        }
      }
      if (!done)
      {
        cout << "NO" << endl;
        return 0;
      }
    }
    m-=1;
  }
  cout << "YES" << endl;
  for(int a : v)
    cout << a << " ";
  cout << endl;
  return 0;
}
