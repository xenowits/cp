#include<bits/stdc++.h>
using namespace std;

#define fori(i,a,b) for (long long int i = a; i <= b ; ++i)
#define ford(i,a,b) for(long long int i = a;i >= b ; --i)
#define mk make_pair
#define mod 998244353
#define pb push_back
#define ll long long
#define MAXN 300001
#define rnd mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().cnt())
#define pi pair<long long int,long long int>
#define sc second
#define fs first

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  string s1,s2;
  cin >> s1 >> s2;
  int n1 = s1.length(), n2 = s2.length();
  reverse(s1.begin(), s1.end());
  reverse(s2.begin(), s2.end());

  ll q1 = 0, q2 = 0, o1 = 0, o2 = 0;
  //calculation for string 1
  for(int i = 0; i < n1; ++i)
  {
    if (i == 0 && s1[i] == '1')
    {
        o1 += 1;
    }
    else if (i == 1 & s1[i] == '1')
      q1 += 1;
    else if (s1[i] == '1')
    {
      q1 += i-1;
      o1 += 1;
    }
  }
  //calculation for string 2
  for(int i = 0; i < n2; ++i)
  {
    if (i == 0 && s2[i] == '1')
    {
        o2 += 1;
    }
    else if (i == 1 & s2[i] == '1')
      q2 += 1;
    else if (s2[i] == '1')
    {
      q2 += i-1;
      o2 += 1;
    }
  }
  double x = 1.618033988749895;
  if (n1 > 50)
  {
    cout << "=" << q1 << " " << o1 << " " << q2 << " " << o2 << endl;
    exit(0);
  }
  // if (q1*x+o1 > q2*x+o2)
  //   cout << ">";
  // else if (q1*x+o1 == q2*x+o2)
  //   cout << "=";
  // else
  //   cout << "<";
  return 0;
}
