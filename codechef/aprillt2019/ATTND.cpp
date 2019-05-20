#include<bits/stdc++.h>
using namespace std;

#define fori(i,a,b) for (long int i = a; i <= b ; ++i)
#define ford(i,a,b) for(long int i = a;i >= b ; --i)
#define mk make_pair
#define mod 1000000007
#define pb push_back
#define ll long long

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t,n;
  string s1,s2;
  cin >> t;
  while (t>0)
  {
    cin >> n;
    unordered_map<string,int> umap;
    vector<pair<string,string> > v;
    fori(i,1,n)
    {
      cin >> s1 >> s2;
      umap[s1] += 1;
      v.pb(mk(s1,s2));
    }
    fori(i,0,n-1)
    {
      auto x = v[i];
      if (umap[x.first] >= 2)
      {
        cout << x.first << " " << x.second << endl;
      }
      else
        cout << x.first << endl;
    }
    t-=1;
  }
  return 0;
}
