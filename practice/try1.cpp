#include<bits/stdc++.h>
using namespace std;

#define fori(i,a,b) for (int i = a; i <= b ; ++i)
#define ford(i,a,b) for(int i = a;i >= b ; --i)
#define mk make_pair
#define mod 1000000007
#define pb push_back
#define ll long long

bool solve(int y)
{
  int arr[5];
  int i = 4;
  while (y > 0)
  {
    arr[i] = y%10;
    y = y/10;
    i-=1;
  }
  bool truth = false;
  fori(i,1,4)
  {
    fori(j,i+1,4)
    {
      if (arr[i] != arr[j])
      {
        cout << arr[i] << " ja " << arr[j] << endl;
        truth = true;
      }
    }
    //cout << arr[i] << " ";
  }
  return truth;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int y;
    cin >> y;
    fori(i,y+1,9000)
    {
      if (solve(i))
      {
        cout << i;
        break;
      }
    }
    //solve(2013);
    return 0;
}
