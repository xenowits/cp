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
  int n;
  cin >> n;
  ll a[n+1][n+1];
  ll ne[2*n+1] = {0}, se[4005] = {0};
  fori(i,1,n)
  {
    fori(j,1,n)
    {
      cin >> a[i][j];
      ne[i+j] += a[i][j];
      se[i-j+2000] += a[i][j];
    }
  }
  // fori(i,1,2*n)
  //   cout << ne[i] << " ";
  // cout << endl;
  // fori(i,0,4005)
  // {
  //   if (se[i] != 0)
  //     cout << i << " " << se[i] << endl;
  // }
  ll maxB = INT_MIN, maxW = INT_MIN, bi, bj, wi, wj, temp;
  fori(i,1,n)
  {
    fori(j,1,n)
    {
      temp = ne[i+j] + se[i-j+2000] - a[i][j];
      if ((i+j)%2 == 0)   //black
      {
        if (temp > maxB)
        {
          maxB = temp;
          bi = i; bj = j;
        }
      }
      else          // white
      {
        if (temp > maxW)
        {
          maxW = temp;
          wi = i; wj = j;
        }
      }
    }
  }
  //cout << maxB << " " << maxW << endl;
  cout << maxB+maxW << endl;
  cout << bi << " " << bj << " " << wi << " " << wj;
  return 0;
}
