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

void sorter(vector<int> v)
{
  int n = v.size();
  int i = -1;
  int j = 0;
  fori(j,0,n-1)
  {
    if (v[j]<=0)
    {
      i+=1;
      swap(v[i],v[j]);
    }
  }
  for(int a : v)
    cout << a << " ";
  cout << endl;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  rnd;
  vector<int> v;
  fori(i,0,9)
  {
    int temp = std::uniform_int_distribution<int>(-12,12)(rng);
    // if (temp == 0)
    //   v.pb(std::uniform_int_distribution<int>(1,5)(rng));
    // else
    //   v.pb(temp);
    v.pb(temp);
  }
  sorter(v);
  return 0;
}
