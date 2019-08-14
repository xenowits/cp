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

  long n,m,k;
  while (t--)
  {
    cin >> n >> m >> k;
    vector<long> v(n+1);
    fori(i,1,n)
      cin >> v[i];
    if (n == 1)
    {
      cout << "YES" << endl;
    }
    else
    {
      bool flag = 0;
      int i = 1;
      while(i < n)
      {
        int temp = abs(v[i+1] - v[i]);
        if (v[i+1]-v[i] <= 0)
        {
          m += (temp);
          m += min(k,v[i+1]);
          i+=1;
        }
        else if (temp <= k)
        {
          m += min(k-temp,v[i]);
          i+=1;
        }
        else if (m >= temp-k)
        {
          m = m - (temp-k);
          i+=1;
        }
        else
        {
          flag = 1;
          break;
        }
      }
      if (flag)
        cout << "NO" << endl;
      else
        cout << "YES" << endl;
    }
  }

  return 0;
}
