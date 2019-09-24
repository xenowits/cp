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
#define pi pair<long long int,long long int>
#define sc second
#define fs first


int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;

  vector<int> a(n+1);

  fori(i,1,n)
    cin >> a[i];

  sort(a.begin()+1,a.end());

  vector<int> ans(n+1,-1);
  int cnt = 0,temp;
  fori(i,1,n)
  {
    if (ans[i] == -1)
    {
      temp = a[i];
      ans[i] = cnt;
      cnt += 1;
      fori(j,i+1,n)
      {
        if (ans[j] == -1 && a[j]%temp == 0)
        {
          ans[j] = ans[i];
        }
      }
    }
  }
  // fori(i,1,n)
  //   cout << ans[i] << " ";
  // cout << endl;
  // cout << cnt << endl;
  int neg = 0;
  fori(i,1,n)
  {
    if (ans[i] == -1)
      neg += 1;
  }
  cout << neg + cnt << endl;
  return 0;
}
