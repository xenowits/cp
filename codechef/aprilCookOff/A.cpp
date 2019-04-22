#include<bits/stdc++.h>
using namespace std;

#define fori(i,a,b) for (long int i = a; i <= b ; ++i)
#define ford(i,a,b) for(long int i = a;i >= b ; --i)
#define mk make_pair
#define mod 1000000007
#define pb push_back
#define ll long long

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t>0)
  {
    int n;
    cin >> n;
    vector<string> arr(n+1);
    fori(i,1,n)
      cin >> arr[i];
    vector<long> v(27,0);
    fori(i,1,n)
    {
      string a = arr[i];
      fori(i,0,a.size()-1)
        v[a[i]-'a'+1] += 1;
    }
    int c = v[3];
    int e = v[5];
    int o = v[15];
    int d = v[4];
    int h = v[8];
    int f = v[6];
    if (c >= 2 && e >= 2 && o >= 1 && d >= 1 && h >= 1 && f >= 1)
    {
      int xx = min( min ( min(o,d),h ),f);
      int yy = min(c,e);
      cout << min(yy/2,xx) << endl;
    }
    else
      cout << 0 << endl;
    t-=1;
  }
  return 0;
}
