#include<bits/stdc++.h>
using namespace std;

#define fori(i,a,b) for (int i = a; i <= b ; ++i)
#define ford(i,a,b) for(int i = a;i >= b ; --i)
#define mk make_pair
#define mod 1000000007

int main()
{
  ios_base::sync_with_stdio(false);cin.tie(0);
  int n;long long int sum = 0,temp;
  cin >> n;
  long long int a[n+1] = {0};
  fori(i,1,n)
  {
    cin >> a[i];
    // a[i] = temp;
    // cout << a[i] << " ";
  }
  // fori(i,1,n)
  // {
  //     cout << a[i] << " ";
  // }
  // cout << endl;
  // fflush(stdout);
  // fflush(stdout);
  ford(i,n,2)
  {
    // if (a[i] > a[i-1] || (a[i] == a[i-1] == 0))
    // {
    //   b[i] = a[i];
    //   cout << i << "fef\n";
    // }
    //cout << "here" << a[i] << a[i-1] << endl;
    if (a[i] <= a[i-1])
    {
      //cout << "helloworld\n";
      if (a[i]>=1)
        a[i-1] = a[i] - 1;
      else
        a[i-1] = 0;
    }
  }
  // fori(i,1,n)
  //   cout << a[i] << " ";
  cout << accumulate(a+1, a+n+1, sum);
  return 0;
}
