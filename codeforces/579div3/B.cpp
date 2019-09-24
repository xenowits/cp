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

  int q;
  cin >> q;

  while(q--)
  {
    int n;
    cin >> n;
    int tot = 4*n;
    vector<int> v(tot);
    fori(i,0,tot-1)
      cin >> v[i];
    sort(v.begin(), v.end());

    bool good = 1;
    for(int i =  0; i < tot-1; i+=2)
    {
      if (v[i] != v[i+1])
      {
        good = 0;
        break;
      }
    }
    if (!good)
      cout << "NO" << endl;

    else
    {
      long area = v[0]*v[tot-1];
      for(int i =  0, j = tot-1; i < tot-1, j >= 0; i+=2, j-=2)
      {
        if (v[i]*v[j] != area)
        {
          good = 0;
          break;
        }
      }
      cout << (good ? "YES" : "NO") << endl;
    }
  }

  return 0;
}
