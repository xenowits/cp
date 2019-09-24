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

  int n,a,x,b,y;
  cin >> n >> a >> x >> b >> y;

  while (a != x && b != y)
  {
    if (a < n)
      a += 1;
    else
      a = 1;

    if (b > 1)
      b -= 1;
    else
      b = n;
    //cout << a << " " << b << endl;
    if (a == b)
    {
      cout << "YES" << endl;
      exit(0);
    }
  }

  if (a == b)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
  return 0;
}
