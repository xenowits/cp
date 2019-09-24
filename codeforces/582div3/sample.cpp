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
  int pos = 0, neg = 0;
  int tattu = 0;
  vector<int> v(n+1);
  fori(i,1,n-1)
  {
    cin >> v[i];
    tattu = tattu + v[i];
    if (tattu < 0)
      neg += 1;
  }
  vector<int> ans(n+1);
  ans[1] = neg+1;
  set<int> s;
  s.insert(ans[1]);
  fori(i,2,n)
  {
    ans[i] = ans[i-1]+v[i-1];
    s.insert(ans[i]);
    if (ans[i] > n || ans[i] < 1)
    {
      cout << -1 << endl;
      exit(0);
    }
  }
  if (s.size() != n)
  {
    cout << -1 << endl;
    exit(0);
  }
  fori(i,1,n)
    cout << ans[i] << " ";
  return 0;
}
