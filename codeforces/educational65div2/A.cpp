#include<bits/stdc++.h>
using namespace std;

#define fori(i,a,b) for (long int i = a; i <= b ; ++i)
#define ford(i,a,b) for(long int i = a;i >= b ; --i)
#define mk make_pair
#define mod 1000000007
#define pb push_back
#define ll long long
#define rnd mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().count())

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t>0)
  {
    int n;
    cin >> n;
    string s;
    cin >> s;
    bool truth = false;
    fori(i,0,n-1)
    {
      if (s[i] == '8' && n-i >= 11)
      {
        cout << "YES" << endl;
        truth = true;
        break;
      }
    }
    if (!truth)
      cout << "NO" << endl;
    t-=1;
  }
  return 0;
}
