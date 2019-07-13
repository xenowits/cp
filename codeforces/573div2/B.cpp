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
#define f first


int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  vector<int> s, m, p;
  string str;
  fori(i,1,3)
  {
    cin >> str;
    if (str[1] == 's')
      s.pb(str[0]-'0');
    if (str[1] == 'm')
      m.pb(str[0]-'0');
    if (str[1] == 'p')
      p.pb(str[0]-'0');
  }
  sort(s.begin(), s.end());
  sort(m.begin(),m.end());
  sort(p.begin(),p.end());
  int ss = s.size();int ms = m.size();int ps = p.size();
  set<int> st;
  //cout << ss << " " << ms << " " << ps << endl;
  st.insert(ss);st.insert(ms);st.insert(ps);
  if (st.size() == 1)
  {
    cout << 2 << endl;
    exit(0);
  }
  if (st.size() == 2)
  {
      //cout << ps << " done" << endl;
      if (ss == 3)
      {
        int a = s[1] - s[0];
        int b = s[2] - s[1];
        if (a == b && (a == 0 || a == 1))
        {
          cout << 0 << endl;
          exit(0);
        }
        if (a <= 2 || b <= 2)
        {
          cout << 1 << endl;
          exit(0);
        }
        else
        {
          cout << 2 << endl;
          exit(0);
        }
      }
      if (ms == 3)
      {
        int a = m[1] - m[0];
        int b = m[2] - m[1];
        if (a == b && (a == 0 || a == 1))
        {
          cout << 0 << endl;
          exit(0);
        }
        if (a <= 2 || b <= 2)
        {
          cout << 1 << endl;
          exit(0);
        }
        else
        {
          cout << 2 << endl;
          exit(0);
        }
      }
      if (ps == 3)
      {
        int a = p[1] - p[0];
        int b = p[2] - p[1];
        //cout << a << " " << b << endl;
        if (a == b && (a == 0 || a == 1))
        {
          cout << 0 << endl;
          exit(0);
        }
        if (a <= 2 || b <= 2)
        {
          cout << 1 << endl;
          exit(0);
        }
        else
        {
          cout << 2 << endl;
          exit(0);
        }
      }
  }
  if (ss == 2)
  {
    if (s[1] - s[0] <= 2)
    {
      cout << 1 << endl;
      return 0;
    }
    else
    {
      cout << 2 << endl;
      return 0;
    }
  }
  if (ms == 2)
  {
    if (m[1] - m[0] <= 2)
    {
      cout << 1 << endl;
      return 0;
    }
    else
    {
      cout << 2 << endl;
      return 0;
    }
  }
  if (ps == 2)
  {
    if (p[1] - p[0] <= 2)
    {
      cout << 1 << endl;
      return 0;
    }
    else
    {
      cout << 2 << endl;
      return 0;
    }
  }
  return 0;
}
