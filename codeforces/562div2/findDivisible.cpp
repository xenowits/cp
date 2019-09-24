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

  vector<int> v{2, 3, 4, 5, 6, 7, 8, 9, 'T', 'J', 'Q', 'K', 'A'};

  string x;
  cin >> x;
  int xa = x[0], xb = x[1];
  fori(i,1,5)
  {
    string temp;
    cin >> temp;
    int ya = temp[0], yb = temp[1];
    if (yb == xb || xa == ya)
    {
      cout << "YES" << endl;
      return 0;
    }
  }
  cout << "NO" << endl;
  return 0;
}
