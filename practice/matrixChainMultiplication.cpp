#include<bits/stdc++.h>
using namespace std;

#define fori(i,a,b) for (long int i = a; i <= b ; ++i)
#define ford(i,a,b) for(long int i = a;i >= b ; --i)
#define mk make_pair
#define mod 1000000007
#define pb push_back
#define ll long long
#define rnd mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().count())

long matrixChainOrder(vector<int> v, int n)
{
  int m[n+1][n+1];
  fori(i,1,n)
    m[i][i] = 0;
  fori(l,2,n)
  {
    fori(i,1,n-l+1)
    {
      int j = i+l-1;
      m[i][j] = INT_MAX;
      fori(k,i,j-1)
      {
          int q = m[i][k] + m[k+1][j] + v[i-1]*v[k]*v[j];
          if (q < m[i][j])
            m[i][j] = q;
      }
    }
  }
  return m[1][n];
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout << "Heard u wanted to find minimum no of scalar multiplications??" << endl;
  bool truth;
  cout << "Input 1 if u really wanted and 0 if u didn't" << endl;
  cin >> truth;
  if (!truth)
  {
    cout << "No problem come back someday later when u find the shire" << endl;
    return 0;
  }
  cout << "Input the no of matrices u wish to multiply" << endl;
  int n;
  cin >> n;
  cout << "First input the p array .. arree dimensions array" << endl;
  vector<int> v(n+1);
  fori(i,0,n)
    cin >> v[i];
  cout << matrixChainOrder(v,n);
  return 0;
}
