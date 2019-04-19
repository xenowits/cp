#include<bits/stdc++.h>
using namespace std;

#define fori(i,a,b) for (long int i = a; i <= b ; ++i)
#define ford(i,a,b) for(int i = a;i >= b ; --i)
#define mk make_pair
#define mod 1000000007
#define pb push_back

void solve(string s)
{
  int n = s.length();
  int dp[n][n];
  fori(i,0,n-1)
    fori(j,0,n-1)
      dp[i][j] = 0;
  fori(i,0,n-1)
  {
    fori(j,1,i+1)
    {
      string temp = s.substr(i-j+1,j);
      string temp2 = temp.substr(0,temp.size()-1);
      cout << temp << " tempu wla " << i << " " << j << endl;
      cout << temp2 << " tempu2 wla " << i << " " << j << endl;
      reverse(temp.begin(),temp.end());
      reverse(temp2.begin(),temp2.end());
      for (int k = i+1; k <= n-1; ++k)
      {
        string some_temp = s.substr(k,j);
        cout << temp << " sb " << some_temp << endl;
        if (temp == some_temp)
        {
          dp[i][j] += 1;
          cout << i << " palin " << temp << some_temp << " palin " << j << endl;
        }
        string some_temp2 = s.substr(k,j-1);
        if (!temp2.empty() && temp2 == some_temp2)
        {
            dp[i][j] += 1;
            cout << i << " palin2 " << temp2 << some_temp2 << " palin2 " << j << endl;
        }
      }
    }
  }
  int sum = 0;
  fori(i,0,n-1)
  {
    fori(j,1,n-1)
    {
      sum += dp[i][j];
    }
  }
  cout << sum;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  string s;
  cin >> s;
  solve(s);
  return 0;
}
