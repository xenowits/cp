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

  vector<int> v(n);
  fori(i,0,n-1)
    cin >> v[i];
  sort(v.begin(), v.end());

  int ans = INT_MAX, ans_t = -1;

  for(int t = v[n-1] ; t > 0; t--)
  {
    int temp = 0;
    for(int x : v)
    {
      if (x < t)
        temp += min(t-x-1, t-x);
      else if (x > t)
        temp += min(x-t, x-t-1);
    }
    if (temp <= ans)
    {
      ans = temp;
      ans_t = t;
    }
    //cout << t << " " << temp << " " << ans << endl;
  }
  cout << ans_t << " " << ans << endl;
  return 0;
}
