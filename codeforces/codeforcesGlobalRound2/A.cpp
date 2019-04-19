#include<bits/stdc++.h>
using namespace std;

#define fori(i,a,b) for (int i = a; i <= b ; ++i)
#define ford(i,a,b) for(int i = a;i >= b ; --i)
#define mk make_pair
#define mod 1000000007
#define pb push_back

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  int arr[n+1] = {-1};
  fori(i,1,n)
  {
    cin >> arr[i];
  }
  int a,b;
  ford(i,n,2)
  {
    if (arr[i] != arr[1])
    {
      a = i-1;
      break;
    }
  }
  fori(i,1,n-1)
  {
    if (arr[i] != arr[n])
    {
      b = n-i;
      break;
    }
  }
  cout << max(a,b);
  return 0;
}
