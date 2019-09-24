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

  string s1, s2;
  cin >> s1 >> s2;
  vector<char> s{'a','e','i','o','u'};
  int n1 = s1.length(), n2 = s2.length();
  if (n1 != n2)
  {
    cout << "No" << endl;
    exit(0);
  }
  for(int i = 0 ;i < n1; ++i)
  {
    char ch1 = s1[i], ch2 = s2[i];
    bool flag1 = 0, flag2 = 0;
    fori(j,0,4)
    {
      if (ch1 == s[j])
        flag1 = 1;
      if (ch2 == s[j])
        flag2 = 1;
    }
    if (!flag1 && flag2 || (flag1 && !flag2))
    {
      cout << "No" << endl;
      exit(0);
    }
  }
  cout << "Yes" << endl;
  return 0;
}
