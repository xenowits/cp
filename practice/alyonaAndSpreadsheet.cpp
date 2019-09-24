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

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n,m;
  cin >> n >> m;
  int arr[n+1][m+1];

  fori(i,1,n)
    fori(j,1,m)
      cin >> arr[i][j];

  int maxlen[n+1][m+1];
  vector<int> maxcnt(n+1,INT_MIN);
  fori(j,1,m)
  {
    ford(i,n,1)
    {
      if (i == n || arr[i+1][j] < arr[i][j])
        maxlen[i][j] = 1;
      else if (arr[i+1][j] >= arr[i][j])
        maxlen[i][j] = maxlen[i+1][j]+1;
    }
  }

  fori(i,1,n)
  {
    fori(j,1,m)
    {
      maxcnt[i] = max(maxcnt[i],maxlen[i][j]);
      //cout << maxlen[i][j] << " ";
    }
    //cout << endl;
  }

  ll k,l,r;
  cin >> k;
  while (k--)
  {
     cin >> l >> r;
     //cout << l << " " << r << " " << maxcnt[l] << endl;
     if (maxcnt[l] + l - 1 >= r)
        cout << "Yes" << endl;
     else
       cout << "No" << endl;
  }

  return 0;
}
