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
  //cout << min(abs('D' - 'X'), 26 - abs('D' - 'X'));
  string a = "ACTG";
  int n;cin >> n;
  string s;
  cin >> s;
  int min_cost = INT_MAX;
  fori(i,0,n-4)
  {
    int a1 = s[i] - a[0];
    a1 = min(abs(a1), 26-abs(a1));
    int b = s[(i+1)%n] - a[1];
    b = min(abs(b), 26-abs(b));
    int c = s[(i+2)%n] - a[2];
    c = min(abs(c), 26-abs(c));
    int d = s[(i+3)%n] - a[3];
    d = min(abs(d), 26-abs(d));
    int cost = a1+b+c+d;
    //cout << a1 << " " << b << " " << c << " " << d << endl;
    if (cost < min_cost)
      min_cost = cost;
  }
  cout << min_cost;
  return 0;
}
