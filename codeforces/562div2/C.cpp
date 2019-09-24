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
  while (n--)
  {
    string s;
    cin >> s;
    vector<int> v(26,0);
    bool flag = 1;
    sort(s.begin(), s.end());
    bool a = 0,z = 0;
    for(int i = 0 ; i < s.length()-1; ++i)
    {
      if (s[i+1] != 1+s[i])
      {
        flag = 0;
        break;
      }
    }
    cout << (flag ? "Yes" : "No") << endl;
  }
  return 0;
}
