#include<bits/stdc++.h>
using namespace std;

#define fori(i,a,b) for (long int i = a; i <= b ; ++i)
#define ford(i,a,b) for(long int i = a;i >= b ; --i)
#define mk make_pair
#define mod 1000000007
#define pb push_back
#define ll long long
#define rnd mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().count())

int n;

void merge(vector<int> &v, int p, int q, int r)
{
  int n1 = q-p+1;
  int n2 = r-q;
  vector<int> L(n1+2);
  vector<int> R(n2+2);
  L[n1+1] = INT_MAX;
  R[n2+1] = INT_MAX;
  for (int i = 1 ; i <= n1 ; ++i)
    L[i] = v[p+i-1];
  for (int i = 1; i <= n2 ; ++i)
    R[i] = v[q+i];
  int i = 1, j = 1;
  for (int k = p ; k <= r; ++k)
  {
    if (L[i] <= R[j])
    {
      v[k] = L[i];
      i += 1;
    }
    else
    {
      v[k] = R[j];
      j += 1;
    }
  }
}

void mergeSort(vector<int> &v, int p, int r)
{
  if (p < r)
  {
    int q = p + (r-p)/2;
    mergeSort(v,p,q);
    mergeSort(v,q+1,r);
    merge(v,p,q,r);
  }
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout << "Plz provide the n" << endl;
  cin >> n;
  vector<int> v(n+1);
  fori(i,1,n)
    cin >> v[i];
  mergeSort(v,1,n);
  fori(i,1,n)
    cout << v[i] << " ";
  cout << endl;
  return 0;
}
