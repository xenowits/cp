#include<bits/stdc++.h>
using namespace std;

#define fori(i,a,b) for (long int i = a; i <= b ; ++i)
#define ford(i,a,b) for(long int i = a;i >= b ; --i)
#define mk make_pair
#define mod 1000000007
#define pb push_back
#define vec vector<long long int>
#define ll long long
#define rnd mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().count())
#define pi pair<int,int>
#define sc second
#define fs first


int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;
  ll temp;
  int odd_cnt = 0, even_cnt = 0;
  fori(i,1,n)
  {
    cin >> temp;
    if (temp&1)
      odd_cnt += 1;
    else
      even_cnt += 1;
  }
  cout << min(even_cnt,odd_cnt) << endl;
  return 0;
}
