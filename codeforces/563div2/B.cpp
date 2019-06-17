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
  vector<int> v(2*n+1);
  set<int> s;
  fori(i,1,2*n)
  {
    cin >> v[i];
    s.insert(v[i]);
  }
  if (s.size() == 1)
    cout << -1;
  else
  {
    sort(v.begin()+1, v.end());
    fori(i,1,2*n)
      cout << v[i] << " ";
    cout << endl;
  }
  return 0;
}
