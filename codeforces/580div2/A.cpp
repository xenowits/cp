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

  vector<int> a(n);
  fori(i,0,n-1)
    cin >> a[i];
  int m;
  cin >> m;
  vector<int> b(m);
  fori(i,0,m-1)
    cin >> b[i];
  sort(a.begin(),a.end());
  sort(b.begin(),b.end());
  cout << a[n-1] << " " << b[m-1] << endl;
  // fori(i,0,n-1)
  // {
  //   int temp = a[i];
  //   bool flag = 0;
  //   fori(j,0,m-1)
  //   {
  //     if (b[j] == a[i])
  //     {
  //         flag = 1;
  //     }
  //   }
  //   if (!flag)
  //   {
  //     cout << temp << " ";
  //     break;
  //   }
  // }
  // fori(i,0,m-1)
  // {
  //   int temp = b[i];
  //   bool flag = 0;
  //   fori(j,0,n-1)
  //   {
  //     if (b[i] == a[j])
  //     {
  //         flag = 1;
  //     }
  //   }
  //   if (!flag)
  //   {
  //     cout << temp;
  //     break;
  //   }
  // }
  return 0;
}
