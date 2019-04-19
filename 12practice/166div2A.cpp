#include<bits/stdc++.h>
using namespace std;

#define fori(i,a,b) for (long int i = a; i <= b ; ++i)
#define ford(i,a,b) for(long int i = a;i >= b ; --i)
#define mk make_pair
#define mod 1000000007
#define pb push_back
#define ll long long

bool solve(int y)
{
  int arr[5];
  int indx = 4;
  while (y>0)
  {
    int a = y%10;
    arr[indx] = a;
    indx -= 1;
    y = y/10;
  }
  bool truth = true;
  fori(i,1,3)
  {
    fori(j,i+1,4)
    {
      if (arr[i] == arr[j])
        truth = false;
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
  fori(i,y+1,12000)
  {
    if (solve(i))
    {
      cout << i;
      break;
    }
  }
  return 0;
}
