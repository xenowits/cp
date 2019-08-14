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
int pos = 0,n;
long solve(string s, int i, int pre_pos)
{
  if (i == n)
    return 0;
  if (pre_pos == )
  if (s[i] == '+')
  {
    pre_pos += 1;
  }
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  string s1, s2;
  cin >> s1 >> s2;

  fori(i,0,s1.length()-1)
  {
    if (s1[i] == '+')
      pos += 1;
    else
      pos -= 1;
  }
  n = s2.length();
  long ans = solve(s2,0,pos);

  return 0;
}
