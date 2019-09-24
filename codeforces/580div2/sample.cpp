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

  int t;
  cin >> t;

  while (t--)
  {
    int n;
    cin >> n;
    int ans;
    int a = 0, b= 0;
    char arr[n+1][n+1];
    fori(i,1,n)
    {
      fori(j,1,n)
      {
        char ch;
        cin >> ch;
        if (j <= n/2 && ch == '1')
          a += 1;
        else if (j > n/2 && ch == '1')
          b += 1;
        arr[i][j] = ch;
      }
    }
    ans = abs(a-b);
    fori(i,1,n)
    {
      int x = 0, y = 0;
      fori(j,1,n)
      {
        char ch = arr[i][j];
        if (j <= n/2 && ch == '1')
          x += 1;
        else if (j > n/2 && ch == '1')
          y += 1;
      }
      int tx = a-x+y, ty = b-y+x;
      //cout << tx << " " << ty << endl;
      ans = min(ans,abs(tx-ty));
    }
    cout << ans << endl;
  }

  return 0;
}
