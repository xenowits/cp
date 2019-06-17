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
  string str;int M;
  cin >> str >> M;
  vector<int> s;
  fori(i,0,9)
  {
    if (str[i] == '1')
      s.pb(i+1);
  }
  if (s.size() == 0)
  {
    cout << "NO" << endl;
    return 0;
  }
  ll m;
  for (int i = 0; i < s.size() ; ++i)
  {
    ll a = 0, b = 0, recent;
    a += *(s.begin()+i);
    recent = *(s.begin()+i);
    m = M;
    m-=1;
    bool chance = false;
    ll temp;
    vector<int> v;
    v.pb(recent);
    vector<int> ds = s;
    reverse(ds.begin(),ds.end());
    //cout << "a is recently " << v[0] << endl;
    while(m>0)
    {
      bool done = false;
      if (!chance)          //b ka chance
      {
        temp = a-b;
        //cout << "a-b wala " << a << " " << b << endl;
        //auto it = std::upper_bound(s.begin(),s.end(),temp);
        for(auto x : ds)
        {
          if (x > temp && x != recent)
          {
            //cout << "a-b wala h " << x << " " << temp << " " << recent << endl;
            done = true;
            b += x;
            cout << "b is " << b << endl;
            recent = x;
            v.pb(x);
            break;
          }
        }
        if (!done)
        {
          // cout << "NO" << endl;
          // return 0;
          break;
        }
        chance = !chance;
      }
      else                 //a ka choice
      {
        temp = b-a;
        //auto it = std::upper_bound(s.begin(),s.end(),temp);
        for(auto x : ds)
        {
          if (x > temp && x != recent)
          {
            done = true;
            a += x;
            cout << "a is " << a << endl;
            recent = x;
            v.pb(x);
            break;
          }
        }
        if (!done)
        {
          // cout << "NO" << endl;
          // return 0;
          //cout << "m is " << m << endl;
          break;
        }
        chance = !chance;
      }
      m-=1;
    }
    cout << "i ans m are " << v[0] << " " << m << endl;
    if (m == 0)
    {
      //cout << "i is " << i << endl;
      cout << "YES" << endl;
      for(int a : v)
        cout << a << " ";
      cout << endl;
      return 0;
    }
  }
  cout << "NO" << endl;
  return 0;
}
