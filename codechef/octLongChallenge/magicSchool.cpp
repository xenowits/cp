#include <bits/stdc++.h>
using namespace std;

#define fs first
#define sc second

int main()
{
  int t;
  cin >> t;

  while (t--)
  {
    int n, temp;
    cin >> n;
    map<int,int> mp;

    for(int i = 0; i < n; ++i)
    {
      cin >> temp;
      mp[temp] += 1;
    }

    if (mp.size() == 1)
    {
      int a = mp.begin()->first, b = mp.begin()->second;
      if (a == n-1 && b == n)
        cout << 0 << endl;
      else if (a == 0 && b == n)
        cout << n << endl;
      else
        cout << -1 << endl;
    }
    else if (mp.size() == 2)
    {
      vector<pair<int, int> > v;
      for(auto x : mp)
        v.push_back(make_pair(x.first, x.second));

      sort(v.begin(), v.end());

      // for (auto x : v)
      //   cout << x.fs << " " << x.sc << endl;
      //

      if ((v[1].fs-v[0].fs) != 1 || (v[0].sc - v[0].fs) != 1 || (v[0].sc != v[1].fs) || (v[0].sc+v[1].sc) != n)
        cout << -1 << endl;
      else
      {
        cout << v[1].second << endl;
      }
    }
    else
      cout << -1 << endl;
  }
}
