#include<bits/stdc++.h>
using namespace std;

#define fori(i,a,b) for (long long int i = a; i <= b ; ++i)
#define ford(i,a,b) for(long long int i = a;i >= b ; --i)
#define mk make_pair
#define mod 998244353
#define pb push_back
#define ll long long
#define MAXN 300001
#define rnd mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().cnt())
#define pi pair<long long int,long long int>
#define sc second
#define fs first

vector<int> ans(10,0);

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  ll v;
  cin >> v;
  vector<int> a(10,0);
  fori(i,1,9)
    cin >> a[i];
  bool flag = 0;
  int min, min_d;
  for (int i = 9 ; i >= 1; --i)
  {
    if (i == 9)
    {
        min = a[i], min_d = 9;
        continue;
    }

    if (a[i] < min)
      min = a[i], min_d = i;

    if (a[i] <= v)
      flag = 1;
  }

  if (!flag)
  {
    cout << -1 << endl;
    exit(0);
  }
  ll rem = v-(v/min)*min;
//  cout << rem << endl;
  vector<int> somev(v/min+2,min_d);
  if (flag)
  {
    int i = 1;
    for(int j = 9; j >= 1 && rem >= 0 && i <= v/min; --j)
    {
      while (a[j]-min <= rem && i <= v/min)
      {
        //cout << i << " " << j  << " " << a[j]-min << " " << rem << endl;
        somev[i] = j;
        rem -= (a[j]-min);
        i += 1;
        //cout << i << " " << j  << " " << a[j]-min << " " << rem << endl;
        // if (i == 5)
        //   exit(0);
      }
    }
    fori(i,1,v/min)
      cout << somev[i];
  }

  return 0;
}
