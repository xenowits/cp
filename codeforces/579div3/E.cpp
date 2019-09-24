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
  vector<int> v(n+1);

  for(int i = 1; i <= n; ++i)
    cin >> v[i];

  set<ll> st;

  sort(v.begin()+1, v.end());

  st.insert(max(v[1]-1,1));

  for(int i = 2; i <= n; ++i)
  {
    int x = max(v[i]-1,1);

    if (st.find(x) == st.end())
      st.insert(x);

    else if (st.find(v[i]) == st.end())
      st.insert(v[i]);

    else if (st.find(v[i]+1) == st.end())
      st.insert(v[i]+1);

  }

  // cout << endl;
  // for(auto p : st)
  //   cout << p << " ";
  // cout << endl;

  cout << st.size() << endl;

  return 0;
}
