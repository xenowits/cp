#include<bits/stdc++.h>
using namespace std;

#define fori(i,a,b) for (long int i = a; i <= b ; ++i)
#define ford(i,a,b) for(long int i = a;i >= b ; --i)
#define mk make_pair
#define mod 1000000007
#define pb push_back
#define ll long long

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n,m,h;
  cin >> n >> m >> h;
  vector<int> a(m);
  vector<int> b(n);
  fori(i,0,m-1)
    cin >> a[i];
  fori(i,0,n-1)
    cin >> b[i];
  int arr[n+1][m+1];
  fori(i,0,n-1)
  {
    int sum = 0;
    fori(j,0,m-1)
    {
      cin >> arr[i][j];
      sum += arr[i][j];
    }
    arr[i][m] = sum;
  }
  fori(i,0,m-1)
  {
    int sum = 0;
    fori(j,0,n-1)
    {
      sum += arr[j][i];
    }
    arr[n][i] = sum;
  }
  bool touched[n+1][m+1] = {false};
  bool internal[m+1] = {false};
  fori(i,0,n-1)
  {
    // if (arr[i][m] >= 2)
    // {
      fori(j,0,m-1)
      {
        if (arr[i][j] == 1 && !internal[j])
        {
          arr[i][j] = b[i];
          touched[i][j] = true;
          internal[j] = true;
          //cout << i << " " << j << " done\n";
          break;
        }
      // }
    }
    // else
    // {
      // fori(j,0,m-1)
      // {
      //   if (arr[i][j] == 1)
      //   {
      //     arr[i][j] = b[i];
      //     touched[i][j] = true;
      //     break;
      //   }
      // }
    // }
  }

  //end of first part
  cout << endl;
  fori(i,0,n-1)
  {
    fori(j,0,m-1)
    {
      if (j < m-1)
        cout << arr[i][j] << " ";
      else
        cout << arr[i][j];
    }
    if (i < n-1)
      cout << endl;
  }
  cout << endl;
  fori(i,0,m-1)
  {
    // if (arr[n][i] >= 2)
    // {
      fori(j,0,n-1)
      {
        if (arr[j][i] == 1 && !touched[j][i])
        {
          arr[j][i] = a[i];
          break;
        }
      }
    // }
    // else
    // {
      // fori(j,0,n-1)
      // {
      //   if (arr[j][i] == 1 && !touched[j][i])
      //   {
      //     arr[j][i] = a[i];
      //     break;
      //   }
      // }
    // }
  }
  fori(i,0,n-1)
  {
    fori(j,0,m-1)
    {
      if (j < m-1)
        cout << arr[i][j] << " ";
      else
        cout << arr[i][j];
    }
    if (i < n-1)
      cout << endl;
  }
  return 0;
}
