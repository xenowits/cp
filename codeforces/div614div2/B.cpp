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
  long n;
  double sum = 0.00000000000;
  cin >> n;
  fori(i,1,n) {
    sum += ((double)1/i);
  }
  cout << fixed << setprecision(10) << sum << endl;
  return 0;
}
