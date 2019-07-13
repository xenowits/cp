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
  vector<char> m[10][10];
  m[1][1].pb('a');
  m[1][1].pb('c');
  for (auto a : m[1][1])
    cout << a << endl;
  int a = 0,b = 1;
  if (1 == 1)
    a+=1,b+=1;
  cout << a << " " << b << endl;
  return 0;
}
