#include<bits/stdc++.h>
using namespace std;

#define fori(i,a,b) for (int i = a; i <= b ; ++i)
#define ford(i,a,b) for(int i = a;i >= b ; --i)
#define mk make_pair
#define mod 1000000007
#define pb push_back
#define ll long long
#define MAXN 100001
#define rnd mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().cnt())
#define pi pair<long long int,long long int>
#define fs first
#define sc second

string s1, s2, s3;
ll n1,n2,n3;
bool dp[1001][1001];

// dp on lengths of first and second strings
// is first i chars of s1 + first j char of s2 == INTERLEAVING  of (i+j) of s3?
//so we can construct bottom up manner

bool solve()
{
  fori(i,0,n1)
  {
    fori(j,0,n2)
    {

      if (i == 0 && j == 0)
        dp[i][j] = 1;
      //s1 is empty()
      else if (i == 0 && s2[j-1] == s3[j-1])
        dp[i][j] = dp[i][j-1];
      //s2 is empty()
      else if (j == 0 && s1[i-1] == s3[i-1])
        dp[i][j] = dp[i-1][j];
      // ith char of s1 matches with (i+j)th of s3
      else if (s1[i-1] == s3[i+j-1] && s2[j-1] != s3[i+j-1])
        dp[i][j] = dp[i-1][j];
      //jth char of s2 matches with (i+j)th of s3
      else if (s1[i-1] != s3[i+j-1] && s2[j-1] == s3[i+j-1])
        dp[i][j] = dp[i][j-1];
      // above statement means: is first i chars of s1 and first j-1
      // chars of s2 : first i+j-1 chars of s3 a INTERLEAVING?
      //if yes then i+j chars of s3 will be a INTERLEAVING for sure
      else if (s1[i-1] == s3[i+j-1] && s2[j-1] == s3[i+j-1])
        dp[i][j] = (dp[i-1][j] || dp[i][j-1]);

    }
  }
  return dp[n1][n2];
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> s1 >> s2 >> s3;

  n1 = s1.length();
  n2 = s2.length();
  n3 = s3.length();

  vector<bool> seen(26,0);

  fori(i,0,n1-1)
    seen[s1[i]-'a'] = 1;

  fori(i,0,n1-1)
    seen[s2[i]-'a'] = 1;

  string temp;

  fori(i,0,n3-1)
  {
    if (seen[s3[i]-'a'])
      temp.pb(s3[i]);
  }

  s3 = temp;n3 = s3.length();

  if (solve())
    cout << "Yes interleaved h" << endl;
  else
    cout << "Naah kaha se interleaved hoga re.." << endl;

  return 0;
}
