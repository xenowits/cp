#include<bits/stdc++.h>
using namespace std;

#define fori(i,a,b) for (long int i = a; i <= b ; ++i)
#define ford(i,a,b) for(long int i = a;i >= b ; --i)
#define mk make_pair
#define mod 1000000007
#define pb push_back
#define ll long long
#define rnd mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().count())

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t>0)
  {
    int r,c;
    cin >> r >> c;
    int arr[r+1][c+1];
    fori(i,1,r)
    {
      fori(j,1,c)
      {
        cin >> arr[i][j];
      }
    }
    bool stable = true;
    fori(i,1,r)
    {
      fori(j,1,c)
      {
        int count = 0;
        if (i>1)  //top
          count += 1;
        if (j>1)  //left
          count += 1;
        if (j<c)  //right
          count += 1;
        if (i<r)  //bottom
          count += 1;
        if (count <= arr[i][j])
        {
          stable = false;
          break;
        }
      }
      if (!stable)
        break;
    }
    if (!stable)
      cout << "Unstable" << endl;
    else
      cout << "Stable" << endl;
    t-=1;
  }
  return 0;
}
