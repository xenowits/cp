#include<bits/stdc++.h>
using namespace std;

#define fori(i,a,b) for (long int i = a; i <= b ; ++i)
#define ford(i,a,b) for(long int i = a;i >= b ; --i)
#define mk make_pair
#define mod 1000000007
#define pb push_back
#define ll long long
#define rnd mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().count())

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while(t>0)
  {
    string s;int n;
    cin >> n >> s;
    int count = 0;
    fori(i,0,n-2)
    {
      char temp = s[i];
      if (temp != 'a' && temp != 'e' && temp != 'i' && temp != 'o' && temp != 'u')
      {
        char ch = s[i+1];
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
        {
          count += 1;
        }
      }
    }
    cout << count << endl;
    t-=1;
  }
  return 0;
}
