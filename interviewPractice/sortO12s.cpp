#include<bits/stdc++.h>
using namespace std;

#define fori(i,a,b) for (long int i = a; i <= b ; ++i)
#define ford(i,a,b) for(long int i = a;i >= b ; --i)
#define mk make_pair
#define mod 1000000007
#define pb push_back
#define ll long long
#define rnd mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().count())
#define pi pair<int,int>

void sorter01(int n, vector<int> v)
{
  int i = 0, j = n-1;
  while (i <= j)
  {
    if (v[i] == 1)
    {
      if (v[j] == 0)
        swap(v[i],v[j]);
      j-=1;
      continue;
    }
    i+=1;
  }
  cout << "\nsorted array would be" << endl;
  for(int a : v)
    cout << a << " ";
  cout << endl;
}

void sorter012(int n, vector<int> v)
{
  int i = 0, j = 0, k = n-1;
  while (j <= k)
  {
    if (v[j] == 0)
    {
      swap(v[i],v[j]);
      i+=1;
      j+=1;
    }
    else if (v[j] == 1)
      j+=1;
    else
    {
      swap(v[j],v[k]);
      k-=1;
    }
  }
  //cout << endl << i << " " << j << " " << k << endl;
  cout << "\nsorted array would be" << endl;
  for(int a : v)
    cout << a << " ";
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  rnd;
  int n = 10;
  vector<int> v;
  fori(i,0,n-1)
  {
    //cout << std::uniform_int_distribution<int>(0,1)(rng) << " h ji ";
    v.push_back(std::uniform_int_distribution<int>(0,2)(rng));
  }
  for (int a : v)
    cout << a << " ";
  sorter012(n,v);
  cout << endl;
  return 0;
}
