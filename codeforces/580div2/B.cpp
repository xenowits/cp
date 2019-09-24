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
  ll temp;
  cin >> n;

  ll pos = 0, neg = 0, zero = 0, neg_cnt = 0, pos_cnt = 0;
  fori(i,0,n-1)
  {
    cin >> temp;
    if (temp < 0)
    {
      neg += abs(temp+1);
      neg_cnt += 1;
    }
    else if (temp == 0)
      zero += 1;
    else
      pos += (temp-1), pos_cnt += 1;
  }
  if (zero != 0)
    cout << neg+pos+zero << endl;
  else
  {
    if (neg_cnt&1) // odd
    {
      cout << neg+pos+2 << endl;
    }
    else
      cout << neg+pos << endl;
  }
  return 0;
}
