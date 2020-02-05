#include<bits/stdc++.h>
using namespace std;

#define fori(i,a,b) for (long int i = a; i <= b ; ++i)
#define ford(i,a,b) for(long int i = a;i >= b ; --i)
#define mk make_pair
#define mod 1000000007
#define pb push_back
#define ll long long
#define rnd mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().count())
#define pi pair<int,int>

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  cin >> t;

  while (t--) {
    int n, k1, k2, temp;
    cin >> n >> k1 >> k2;
    int max_first = -1, max_second = -1;
    fori(i,1,k1) {
      cin >> temp;
      max_first = max(max_first, temp);
    }
    fori(i,1,k2) {
      cin >> temp;
      max_second = max(max_second, temp);
    }
    cout << ((max_first > max_second) ? "YES" : "NO");
    cout << endl;
  }

  return 0;
}
