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

  int arr[105];
  string s;
  cin >> s;
  int n = s.length();
  fori(i,1,n)
  {
    arr[i] = s[i-1]-'0';
  }
  fori(i,1,n)
  {
    if (arr[i] == 0 || arr[i] == 8)
    {
      cout << "YES" << endl << arr[i] << endl;
      exit(0);
    }
  }
  ll num;
  fori(i,1,n)
  {
    fori(j,i+1,n)
    {
      num = 10*arr[i]+arr[j];
      if (arr[i] != 0 && num%8 == 0)
      {
        cout << "YES" << endl << arr[i] << arr[j] << endl;
        exit(0);
      }
    }
  }

  fori(i,1,n)
  {
    fori(j,i+1,n)
    {
      fori(k,j+1,n)
      {
        num = 100*arr[i]+10*arr[j]+arr[k];
        if (arr[i] != 0 && num%8 == 0)
        {
          cout << "YES" << endl << arr[i] << arr[j] << arr[k] << endl;
          exit(0);
        }
      }
    }
  }
  cout << "NO" << endl;
  return 0;
}
