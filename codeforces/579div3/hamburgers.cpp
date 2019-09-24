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

  string str;
  cin >> str;
  int reg[3] = {0};

  for(int i =  0; i < str.length(); ++i)
  {
    if (str[i] == 'B')
      reg[0] += 1;
    else if (str[i] == 'S')
      reg[1] += 1;
    else if (str[i] == 'C')
      reg[2] += 1;
  }

  int n[3], p[3];
  ll r;

  cin >> n[0] >> n[1] >> n[2];
  cin >> p[0] >> p[1] >> p[2];

  cin >> r;
  ll ans = 0;
  int x = min(n[0]/reg[0], min(n[1]/reg[1], n[2]/reg[2]));
  cout << x << endl;

  ans += x;
  fori(i,0,2)
  {
    n[i] -= x*reg[i];
    cout << n[i] << endl;
  }
  bool flag = 0;
  fori(i,0,2)
  {
    if (n[i] == 0 && p[i]*reg[i] <= r)
    {
      r -= p[i]*reg[i]
    }
    else if (n[i] == 0 && p[i]*reg[i] > r)
    {
      flag = 1;
      break;
    }
  }
  if (!flag)
  {
    cout << ans << endl;
    exit(0);
  }
  ans += 1;
  return 0;
}
