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

struct seg{
  int id, l, r;
};

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t, n,l,r;
  cin >> t;

  while (t--)
  {
    cin >> n;
    vector<seg> v;
    for(int i = 0;i < n; ++i)
    {
      cin >> l >> r;
      seg x;
      x.id = i, x.l = l, x.r = r;
      v.pb(x);
    }
    sort(v.begin(), v.end(), [] (const seg a, const seg b)
  {
    if (a.l == b.l)
    {
      if (a.r == b.r)
        return a.id < b.id;
      else
        return a.r < b.r;
    }
    return a.l < b.l;
  });

  // for(auto x : v)
  // {
  //   cout << t << " " << x.id << " " << x.l << " " << x.r << endl;
  // }

    vector<int> grp(n,0);
    grp[v[0].id] = 1;
    int indx = -1;
    for(int i = 1 ; i < v.size(); ++i)
    {
      seg a = v[i], b = v[i-1];
      //cout << a.l << " fdf " << b.r << endl;
      if (a.l <= b.r)
      {
        grp[a.id] = 1;
      }
      else
      {
        indx = i;
        break;
      }
    }
    //cout << indx << endl;
    if (indx == -1)
      cout << -1 << endl;
    else
    {
      for(int i = indx; i < v.size(); ++i)
      {
        grp[v[i].id] = 2;
      }
      for(int i = 0; i < n; ++i)
        cout << grp[i] << " ";
      cout << endl;
    }
}
  return 0;
}
