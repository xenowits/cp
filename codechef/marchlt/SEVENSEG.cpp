#include<bits/stdc++.h>
using namespace std;

#define fori(i,a,b) for (int i = a; i <= b ; ++i)
#define ford(i,a,b) for(int i = a;i >= b ; --i)
#define mk make_pair
#define mod 1000000007

int main()
{
  ios_base::sync_with_stdio(false);cin.tie(0);
  int arr[10] = {6,2,5,5,4,5,6,3,7,6};
  int t,x,y,n;
  cin >> t;
  while(t>0)
  {
    cin >> n;
    // fori(i,1,n)
    // {
    //   cin >> x >> y;
    //   if (arr[x] < y)
    //     cout << "invalid";
    //   else
    //   {
    //     cout << arr[x] - y << " " << 7 - y;
    //   }
    //   if (t>1)
    //     cout << "\n";
    // }
    if (n == 1)
    {
        cin >> x >> y;
        if (arr[x] < y)
          cout << "invalid";
        else
        {
          cout << arr[x] - y << " " << 7 - y;
        }
    }
    t-=1;
    if (t>0)
      cout << "\n";
  }
  return 0;
}
