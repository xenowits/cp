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

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  vector<float> v(n+1);
  ll sum = 0;
  fori(i,1,n)
  {
    cin >> v[i];
    sum += (int)floor(v[i]);
  }
  //cout << sum << " is the sum" << endl;
  int i = 1;
  while (sum != 0)
  {
    if (abs(v[i]-(int)v[i]) != 0)
    {
      sum += 1;
      cout << (int)floor(v[i])+1 << endl;
    }
    else
      cout << v[i] << endl;
    i+=1;
  }
  for(int j = i ; j <= n; ++j)
    cout << (int)floor(v[j]) << endl;
  return 0;
}
