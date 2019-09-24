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

string s,t;
int n, ans = 0;
int n1;

void solve(string temp, string some, int len)
{
  if (temp.length() < n1)
    return;
  int i = 0, j = 0;
  while (i < temp.length() && j < n1)
  {
    if (t[j] == temp[i])
      j+=1;
    i += 1;
  }
  if (j == n1)
  {
    ans = max(ans,len);
  }
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> s >> t;
  n = s.length();
  n1 = t.length();

  for(int len = 1; len <= n; ++len)
  {
    for(int i = 0 ; i+len-1 < n; ++i)
    {
      string temp1 = s.substr(0,i);
      string temp2 = s.substr(i+len,n-i-len);
      temp1 = temp1 + temp2;

      solve(temp1,temp2,len);
    }
  }

  cout << ans << endl;
  
  return 0;
}
