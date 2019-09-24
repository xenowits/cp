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

ll you = INT_MAX;
vector<ll> v(2005);



int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;

  fori(i,1,n)
    cin >> v[i];

  map<int,int> mp1,mp2;
  map<int,int> mp;
  vector<map<int,int> > ans(n+2);
  set<int> final;
  for(int i = n; i >= 1; --i)
  {
    mp[v[i]] += 1;
    ans[i] = mp;
    final.insert(v[i]);
  }
  if (final.size() == n)
  {
    cout << 0 << endl;
    exit(0);
  }
  for(ll s = 1; s < n; ++s)
  {
      map<int,int> temp = ans[1+s];
      // cout << s << endl;
      // for(auto p : temp)
      //   cout << p << " pi ";
      // cout << endl;
      for(int i = 1; i <= n+1-s; ++i)
      {
        if (temp.size() == n-s)
        {
            you = min(you,s);
        }

        temp[v[i]] += 1;
        if (temp[v[i+s]] == 1)
          temp.erase(v[i+s]);
        else
          temp[v[i+s]] -= 1;
      }
      //cout << you << " you h " << endl;
  }
  cout << you << endl;
  // for(int i = 1; i <= n; ++i)
  // {
  //   final.erase(v[i-1]);
  //   set<int> temp = final;
  //   for(int s = 1; s <= n+1-i; ++s)
  //   {
  //     temp.erase(v[i-1]);
  //     temp.insert(v[i+1]);
  //     if (temp.size() == n-s)
  //     {
  //       you = min(you,s);
  //     }
  //   }
  // }
  //
  // cout << you << endl;
  return 0;
}
