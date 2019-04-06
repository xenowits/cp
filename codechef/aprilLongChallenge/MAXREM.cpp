#include<bits/stdc++.h>
using namespace std;

#define fori(i,a,b) for (int i = a; i <= b ; ++i)
#define ford(i,a,b) for(int i = a;i >= b ; --i)
#define mk make_pair
#define mod 1000000007
#define pb push_back

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  long int a;
  cin >> n;
  set<long int> s;
  fori(i,1,n)
  {
    cin >> a;
    s.insert(a);
  }
  vector<long int> v;
  for (auto x : s)
  {
    v.pb(x);
  }
  if (v.size() == 1)
    cout << 0;
  else
    cout << v[v.size()-2];
  return 0;
}
