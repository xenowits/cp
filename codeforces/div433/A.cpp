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
  int n;
  cin >> n;
  int num = 1, den = n-1;
  fori(i,2,n/2)
  {
    if (__gcd(i,n-i) == 1 && (den*i - num*(n-i) > 0))
    {
      num = i;
      den = n-i;
    }
  }
  cout << num << " " << den << endl;
  return 0;
}
