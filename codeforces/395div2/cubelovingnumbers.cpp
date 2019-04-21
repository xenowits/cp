#include<bits/stdc++.h>
using namespace std;

#define fori(i,a,b) for (long int i = a; i <= b ; ++i)
#define ford(i,a,b) for(long int i = a;i >= b ; --i)
#define mk make_pair
#define mod 1000000007
#define pb push_back
#define ll long long

long solve(long n) {
    double a = pow(n,1.0/3);
    long b = int(a);
    cout << "b is " << b << endl;
    long long int cnt = 0;
    for(long i = 2; i <= b; ++i)
    {
        cnt += n/(i*i*i);
        cout << n/(i*i*i) << endl;
    }
    for (int i = 2; i <= 4; ++i)
    {
      for (int j = 1;;++j)
      {
        
      }
    }
    return cnt;
}


int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout << solve(101);
  return 0;
}
