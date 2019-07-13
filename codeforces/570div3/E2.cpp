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
  int n,k;
  cin >> n >> k;
  string s;
  cin >> s;
  // bfs on strings for the first time in my life
  int ans = 0;
  queue<string> q;
  set<string> st;
  q.push(s);
  st.insert(s);
  while (!q.empty() && st.size() < k)
  {
    string v = q.front();
    q.pop();
    for(int i = 0 ; i < v.size() ; ++i)
    {
      string nv = v;
      nv.erase(i,1);
      if (!st.count(nv) && st.size()+1 <= k)
      {
        q.push(nv);
        st.insert(nv);
        ans += n-nv.size();
      }
    }
  }
  if (st.size() < k)
    cout << -1 << endl;
  else
    cout << ans << endl;
  return 0;
}
