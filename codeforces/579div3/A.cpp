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

  int q,n;
  cin >> q;

  while (q--)
  {
    cin >> n;
    vector<int> v(n);
    int a;
    for(int i = 0; i < n ;++i)
    {
      cin >> v[i];
      if (v[i] == 1)
        a = i;
    }
    bool flag = 1;
    for(int i = 0; i < n; ++i)
    {
      if (v[(a+i)%n] != i+1)
      {
        flag = 0;
        break;
      }
    }

    if (flag)
    {
      cout << "YES" << endl;
    }
    else
    {
      reverse(v.begin(),v.end());
      a = n-(a+1);
      flag = 1;
      for(int i = 0; i < n; ++i)
      {
        if (v[(a+i)%n] != i+1)
        {
          flag = 0;
          //cout << "second " << (a+i)%n << " " << v[(a+i)%n] << " " << i << endl;
          break;
        }
      }

      if (flag == 1)
      {
        cout << "YES" << endl;
      }
      else
        cout << "NO" << endl;
    }
  }

  return 0;
}
