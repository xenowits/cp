#include<bits/stdc++.h>
using namespace std;

#define fori(i,a,b) for (long int i = a; i <= b ; ++i)
#define ford(i,a,b) for(long int i = a;i >= b ; --i)
#define mk make_pair
#define mod 1000000007
#define pb push_back
#define ll long long
#define rnd mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().count())
#define pi pair<int,int>

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  fori(i,1,n)
  {
    string s,t;
    cin >> s >> t;
    //unordered_map<char,int> up;
    vector<pair<char,ll> > v,a;
    fori(i,0,s.length()-1)
    {
      //up[s[i]] += 1;
      if (v.empty())
      {
        v.pb(mk(s[i],1));
        continue;
      }
      if (v[v.size()-1].first != s[i])
      {
        v.pb(mk(s[i],1));
      }
      else if (v[v.size()-1].first == s[i])
      {
        v[v.size()-1].second += 1;
      }
    }
    fori(i,0,t.length()-1)
    {
      //up[s[i]] += 1;
      if (a.empty())
      {
        a.pb(mk(t[i],1));
        continue;
      }
      if (a[a.size()-1].first != t[i])
      {
        a.pb(mk(t[i],1));
      }
      else if (a[a.size()-1].first == t[i])
      {
        a[a.size()-1].second += 1;
      }
    }
    if (v.size() != a.size())
    {
      cout << "NO" << endl;
      continue;
    }
    bool truth = true;
    // for (int i = 0 ; i < v.size() ; ++i)
    // {
    //   cout << v[i].first << " " << v[i].second << " " << a[i].first << " " << a[i].second << endl;
    // }
    for (int i = 0 ; i < v.size() ; ++i)
    {
      if ( !( (v[i].first == a[i].first) && (v[i].second <= a[i].second) ))
      {
        truth = false;
        cout << "NO" << endl;
        break;
      }
    }
    if (truth)
      cout << "YES" << endl;
    // ll j = 0;
    // bool truth = true;
    // // for(auto x : v)
    // //   cout << x.first << " " << x.second << endl;
    // // cout << endl;
    // fori(i,0,v.size()-1)
    // {
    //   char a = v[i].first;
    //   ll cnt = v[i].second;ll temp = 0;
    //   for(;j<t.length();++j)
    //   {
    //     if (t[j] == a)
    //     {
    //       temp += 1;
    //     }
    //     else
    //       break;
    //   }
    //   //j-=1;
    //   if (temp < cnt)
    //   {
    //     cout << j << " " << a << " " << temp << " " << cnt << endl;
    //     truth = false;
    //     cout << "NO" << endl;
    //     break;
    //   }
    // }
    // cout << j << " ans h " << endl;
    // if (truth)
    //   cout << "YES" << endl;
  }
  return 0;
}
