#include<bits/stdc++.h>
using namespace std;

#define fori(i,a,b) for (int i = a; i <= b ; ++i)
#define ford(i,a,b) for(int i = a;i >= b ; --i)
#define mk make_pair
#define mod 1000000007

int main()
{
  ios_base::sync_with_stdio(false);cin.tie(0);
  int n,leftcount = 0, rightcount = 0;
  cin >> n;
  int arr[n];
  fori(i,0,n-1)
  {
    cin >> arr[i];
    if (arr[i] == 0)
      leftcount += 1;
    else
      rightcount +=1;
  }
  int lefttemp = 0,righttemp = 0,ans;
  fori(i,0,n-1)
  {
    if (arr[i] == 0)
    {
      lefttemp += 1;
      if (lefttemp == leftcount)
      {
        ans = i+1;
        break;
      }
    }
    else
    {
      righttemp += 1;
      if (righttemp == rightcount)
      {
        ans = i+1;
        break;
      }
    }
  }
  cout << ans;
  return 0;
}
